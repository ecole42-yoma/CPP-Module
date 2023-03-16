#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#define __NS__ BitcoinExchange

namespace {

	inline bool
	syntax_(const int table[8], char c) {
		return (table[(c >> 5)] & (1U << (c & 0x1f)));
	}

	const int date_[] = {
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
		0x03ff2000, /*	0000 0011 1111 1111  0010 0000 0000 0000 */
		/*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
		0x00000000, /*	0000 0000 0000 0000. 0000 0000 0000 0000 */
		/*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	};

	const int value_[] = {
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
		0x03ff4000, /*	0000 0011 1111 1111  0100 0000 0000 0000 */
		/*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
		0x00000000, /*	0000 0000 0000 0000. 0000 0000 0000 0000 */
		/*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	};

	template <typename _Tp>
	inline void
	log_(const char* s1, const _Tp s2) {
		std::cout << s1 << ": " << s2 << std::endl;
	}

	inline void
	log_line_(std::string file_name, size_t line_number, std::string message) {
		std::cout << file_name << ":" << line_number << ": " << COLOR_RED << "error: ";
		std::cout << COLOR_YELLOW << message << COLOR_RESET << std::endl;
	}

	inline void
	result_log_(const check_t& check, double value = 0) {
		switch (check.error_state) {
		case bad_date: {
			log_("Error: bad input : date : => ", check.date);
			break;
		}
		case bad_value: {
			log_("Error: bad input : value : => ", check.date);
			break;
		}
		case too_large: {
			log_("Error: too large a number. : ", check.value);
			break;
		}
		case negative: {
			log_("Error: not a positive number : ", check.value);
			break;
		}
		case none: {
			std::cout << check.date << " => " << check.value << " = ";
			std::cout << value * check.value << std::endl;
			break;
		}
		case end: {
			break;
		}
		default: {
			log_("Error", "unknown state in print_log_()");
			break;
		}
		}
	}

	inline bool
	is_file_of_(std::string extension, std::string file, void (*log)(const char*, const char*) = NULL) {
		if (file.size() > extension.size() && file.substr(file.size() - 4, 4) == extension) {
			return true;
		} else if (log != NULL) {
			log("Error: not a valid file name", file.c_str());
		}
		return false;
	}

	inline bool
	check_start_line_(std::string buf, std::string s1, std::string s2, std::string delim) {
		if (buf == s1 + delim + s2) {
			return true;
		}
		return false;
	}

	inline bool
	check_date_(std::string& date) {
		(void)syntax_(date_, ' ');
		return false;
	}

	inline bool
	check_value_(std::string& value) {
		(void)syntax_(value_, ' ');
		return false;
	}

	inline check_t
	check_basic_line_(std::string buf, size_t left_size, std::string delim) {
		check_t check;
		check.error_state = none;
		check.value		  = 0;
		check.date		  = "";

		std::string::size_type pos = buf.find(delim);
		if (pos == std::string::npos || pos != left_size) {
			check.error_state = bad_date;
			return check;
		}
		std::string date  = buf.substr(0, pos);
		std::string value = buf.substr(pos + delim.size(), buf.size() - pos - delim.size());
		if (!check_date_(date)) {
			check.error_state = bad_date;
		} else if (!check_value_(value)) {
			check.error_state = bad_value;
		}
		return check;
	}

} // namespace

__NS__::BitcoinExchange(char** argv) {
	if (argv == NULL) {
		log_("Error", "no input file");
		exit(1);
	}
	if (is_file_of_(".csv", std::string(argv[0]))) {
		if (argv[1] == NULL) {
			log_("Error: ./btc [some.csv] ...txt ", "there is no input file");
			exit(1);
		}
		init_db_(argv[0]);
		argv = &argv[1];
	} else {
		init_db_("data.csv");
	}
	for (size_t i = 0; argv[i] != NULL; ++i) {
		exchange_(argv[i]);
	}
}

__NS__::~BitcoinExchange() { }

__NS__::BitcoinExchange(__NS__::const_reference from) { *this = from; }

__NS__::reference
__NS__::operator=(__NS__::const_reference from) {
	if (this != &from) {
		data_ = from.data_;
	}
	return *this;
}

void
__NS__::init_db_(std::string db_file) {
	std::fstream file(db_file.c_str(), std::ios::in);
	if (!file.is_open()) {
		log_("Error: can't open file", db_file.c_str());
		exit(1);
	}

	std::string buf;
	size_t		line_number = 0;
	while (std::getline(file, buf)) {
		++line_number;
		if (line_number == 1) {
			if (!check_start_line_(buf, "date", "exchange_rate", ",")) {
				log_("Error: bad start line", buf.c_str());
				log_line_(db_file, line_number, "is not \'date,exchange_rate\'");
				exit(1);
			} else {
				continue;
			}
		} else if (buf[0] == '#' || buf[0] == '\n') {
			continue;
		} else {
			check_t check = check_basic_line_(buf, 10, ",");
			if (check.error_state == none) {
				data_.insert(std::make_pair(check.date, check.value));
			} else {
				log_line_(db_file, line_number, "form must be [\'0000-00-00\',value] or invalid date or invalid value");
			}
		}
		// TODO : should i check leak?
	}
	file.close();
}

void
__NS__::find_and_exchange_(check_t check) {
	container::iterator is_exist = data_.find(check.date);
	if (is_exist != data_.end()) {
		result_log_(check, is_exist->second);
	} else {
		container::iterator lower_data = data_.lower_bound(check.date);
		if (lower_data != data_.end()) {
			if (lower_data != data_.begin()) {
				--lower_data;
			}
			result_log_(check, lower_data->second);
		} else {
			log_("Error: bad input : date : => ", check.date);
		}
	}
}

void
__NS__::exchange_(const char* input) {
	if (input == NULL || input[0] == '\0' || !is_file_of_(".txt", input, log_)) {
		return;
	}
	std::fstream file(input, std::ios::in);
	if (!file.is_open()) {
		log_("Error: can't open file", input);
		return;
	}

	std::string buf;
	size_t		line_number = 0;
	while (std::getline(file, buf)) {
		++line_number;
		if (line_number == 1) {
			if (!check_start_line_(buf, "date", "value", " | ")) {
				log_("Error: bad start line", buf.c_str());
				log_line_(input, line_number, "is not \'date | value\'");
				return;
			} else {
				continue;
			}
		} else if (buf[0] == '#' || buf[0] == '\n') {
			continue;
		} else {
			check_t check = check_basic_line_(buf, 10, ",");
			if (check.error_state == none) {
				find_and_exchange_(check);
			} else {
				result_log_(check);
			}
		}
	}
	file.close();
}

#undef __NS__
