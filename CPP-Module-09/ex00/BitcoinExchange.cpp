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

	const int sep_[] = {
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
		0x00000001, /*	0000 0000 0000 0000  0000 0000 0000 0001 */
		/*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
		0x00000000, /*	0000 0000 0000 0000. 0000 0000 0000 0000 */
		/*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
		0x10000000, /*	0001 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	};

	const int input_value_[] = {
		0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
		/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
		0x03ff6000, /*	0000 0011 1111 1111  0110 0000 0000 0000 */
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

	inline void
	log_(const char* s1, const char* s2 = NULL) {
		std::cout << s1;
		if (s2 != NULL) {
			std::cout << ": " << s2;
		}
		std::cout << std::endl;
	}

	// inline void
	// check__(const char* s1) {
	// 	std::cout << s1 << std::endl;
	// 	exit(0);
	// }

	inline std::map<std::string, double>
	parse_csv_file_(std::string buf) {
		if (buf.empty()) {
			log_("Error", "csv file is empty");
			exit(1);
		}
		std::map<std::string, double> data;
		std::string::iterator		  it = buf.begin();

		std::string		  temp_string;
		std::string		  date_string;
		std::stringstream ss;
		int				  new_line_count = 0;

		enum {
			start,
			date_year,
			date_month,
			date_day,
			value,
			newline,
			end,
			error
		} state,
			prev_state, next_state;

		state = start;
		while (state != end) {
			switch (state) {
			case start: {
				if ("date" == buf.substr(0, 4) && buf[4] == ',' && buf.substr(5, 13) == "exchange_rate") {
					state	   = newline;
					next_state = date_year;
					it += 18;
				} else {
					log_("Error", "csv start_line error");
					exit(1);
				}
				prev_state = state;
				break;
			}
			case date_year: {
				while (it != buf.end() && *it == ' ') {
					++it;
				}
				if (it == buf.end()) {
					state = end;
					break;
				}
				while (it != buf.end() && std::isdigit(*it)) {
					temp_string += *it;
					++it;
				}
				if (it == buf.end()) {
					log_("Error", "csv date_year error");
					state = error;
				} else if (*it == '-' && temp_string.size() == 4) {
					date_string += temp_string + "-";
					state	   = next_state;
					next_state = date_day;
					++it;
				} else {
					log_("Error", "csv date_year error");
					state = error;
				}
				temp_string.clear();
				prev_state = state;
				break;
			}
			case date_month: {
				while (it != buf.end() && std::isdigit(*it)) {
					temp_string += *it;
					++it;
				}
				if (it == buf.end()) {
					log_("Error", "csv date_month error");
					state = error;
				} else if (*it == '-' && temp_string.size() == 2) {
					date_string += temp_string + "-";
					state	   = next_state;
					next_state = value;
					++it;
				} else {
					log_("Error", "csv date_month error");
					state = error;
				}
				temp_string.clear();
				prev_state = state;
				break;
			}
			case date_day: {
				while (it != buf.end() && std::isdigit(*it)) {
					temp_string += *it;
					++it;
				}
				if (it == buf.end()) {
					log_("Error", "csv date_day error");
					state = error;
				} else if (*it == ',' && temp_string.size() == 2) {
					date_string += temp_string;
					state	   = next_state;
					next_state = newline;
					++it;
				} else {
					log_("Error", "csv date_day error");
					state = error;
				}
				temp_string.clear();
				prev_state = state;
				break;
			}
			case value: {
				int comma_count = 0;
				while (it != buf.end() && syntax_(value_, *it)) {
					if (*it == '.') {
						comma_count++;
					}
					if (comma_count > 1) {
						log_("Error", "csv value error");
						state = error;
						break;
					}
					temp_string += *it;
					++it;
				}
				if (it == buf.end()) {
					state = end;
				} else if (*it == '\n') {
					state	   = next_state;
					next_state = date_year;
				} else {
					log_("Error", "csv date_day error");
					state = error;
				}
				if (state != error) {
					ss << temp_string;
					double value;
					ss >> value;
					ss.clear();
					data.insert(std::make_pair(date_string, value));
					temp_string.clear();
					date_string.clear();
				}
				prev_state = state;
				break;
			}
			case newline: {
				if (it == buf.end()) {
					state = end;
				} else if (*it == '\n') {
					++new_line_count;
					state	   = next_state;
					next_state = date_month;
					++it;
				} else {
					log_("Error", "csv newline error");
					state = error;
				}
				prev_state = state;
				break;
			}
			case end: {
				break;
			}
			case error: {
				std::cout << "Error line : " << new_line_count << std::endl;
				exit(1);
			}
			default: {
				log_("Error", "state error");
				exit(1);
			}
			}
		}
		return data;
	}

	inline std::map<std::string, std::string>
	input_check_(std::string buf) {
		if (buf.empty()) {
			log_("Error", "input error");
			exit(1);
		}

		std::map<std::string, std::string> input;
		std::string::iterator			   it = buf.begin();

		std::string		  temp_string;
		std::string		  date_string;
		std::stringstream ss;

		enum {
			start,
			date,
			separator,
			value,
			newline,
			skip,
			end
		} state,
			prev_state, next_state;

		state = start;
		while (state != end) {
			switch (state) {
			case start: {
				if ("date | value" == buf.substr(0, 13)) {
					state	   = newline;
					next_state = date,
					it += 13;
				} else {
					log_("Error", "input start_line error");
					exit(1);
				}
				prev_state = state;
				break;
			}
			case date: {
				while (it != buf.end() && !syntax_(sep_, *it) && *it != '\n') {
					temp_string += *it;
					++it;
				}
				if (it == buf.end()) {
					input.insert(std::make_pair(temp_string, ""));
					state = end;
				} else if (syntax_(sep_, *it) && temp_string.size() == 10) {
					date_string = temp_string;
					state		= next_state;
					next_state	= value;
				} else {
					input.insert(std::make_pair(date_string, ""));
					state = skip;
				}
				temp_string.clear();
				prev_state = state;
				break;
			}
			case separator: {
				while (it != buf.end() && *it == ' ') {
					++it;
				}
				if (it == buf.end()) {
					input.insert(std::make_pair(date_string, ""));
					state = end;
				} else if (*it == '|') {
					state	   = next_state;
					next_state = newline;
					++it;
				} else {
					input.insert(std::make_pair(date_string, ""));
					state = skip;
				}
				while (it != buf.end() && *it == ' ') {
					++it;
				}
				prev_state = state;
			}
			case value: {
			}
			case skip: {
				while (it != buf.end() && *it != '\n') {
					++it;
				}
				if (it == buf.end()) {
					state = end;
				} else if (*it == '\n') {
					state	   = newline;
					next_state = date;
				}
				break;
			}
			case newline: {
				if (it == buf.end()) {
					state = end;
				} else if (*it == '\n') {
					state	   = next_state;
					next_state = separator;
					++it;
				} else {
					state	   = skip;
					next_state = newline;
				}
				prev_state = state;
				break;
			}
			case end: {
				break;
			}
			default: {
				log_("Error", "state error");
				exit(1);
			}
			}
			return input;
		}
	}

} // namespace

__NS__::BitcoinExchange(const char* csv_file) {
	std::fstream file;

	file.open(csv_file, std::ios_base::in);

	if (file.is_open()) {
		std::stringstream ss;

		ss << file.rdbuf();
		if (ss.fail()) {
			file.close();
			log_("Error", "ss error");
			exit(1);
		}

		data_ = parse_csv_file_(ss.str());
		// for (container::const_iterator it = data_.begin(); it != data_.end(); ++it) {
		// 	std::cout << std::cout.precision(12) << it->first << " " << it->second << std::endl;
		// }
	} else {
		log_("Error", "could not open csv file.");
		exit(1);
	}
	file.close();
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
__NS__::exchange(const char* input) {
	std::fstream file;

	file.open(input, std::ios_base::in);

	if (file.is_open()) {
		std::stringstream ss;

		ss << file.rdbuf();
		if (ss.fail()) {
			file.close();
			log_("Error", "ss error");
			exit(1);
		}
		std::map<std::string, std::string> input = input_check_(ss.str());
		for (std::map<std::string, std::string>::const_iterator it = input.begin(); it != input.end(); ++it) {

			std::cout << it->first << " " << it->second << std::endl;
		}

	} else {
		log_("Error", "could not open file.");
		exit(1);
	}
	file.close();
}

#undef __NS__
