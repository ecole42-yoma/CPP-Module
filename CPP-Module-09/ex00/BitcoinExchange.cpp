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

	// const int sep_[] = {
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
	// 	0x00000001, /*	0000 0000 0000 0000  0000 0000 0000 0001 */
	// 	/*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
	// 	0x00000000, /*	0000 0000 0000 0000. 0000 0000 0000 0000 */
	// 	/*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
	// 	0x10000000, /*	0001 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// };

	// const int input_value_[] = {
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	/*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
	// 	0x03ff6000, /*	0000 0011 1111 1111  0110 0000 0000 0000 */
	// 	/*				_^]\ [ZYX WVUT SRQP  ONML KJIH GFED CBA@ */
	// 	0x00000000, /*	0000 0000 0000 0000. 0000 0000 0000 0000 */
	// 	/*				 ~}| {zyx wvut srqp  onml kjih gfed cba` */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// 	0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
	// };

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

	inline void
	bad_date_(check_t check) {
		std::cout << "Error: bad input : date : => ";
		std::cout << check.date << std::endl;
	}
	inline void
	bad_value_(check_t check) {
		std::cout << "Error: bad input : value : => ";
		std::cout << check.date << std::endl;
	}
	inline void
	too_large_(check_t check) {
		std::cout << "Error: too large a number. : " << check.value << std::endl;
	}
	inline void
	negative_(check_t check) {
		std::cout << "Error: not a positive number : " << check.value << std::endl;
	}

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

	inline check_t
	parse_input_data_(std::string& buf) {
		check_t input;
		input.error_state = none;

		std::string::size_type pos = buf.find_first_of('\n');
		std::string			   temp_value;
		int					   value_error = 0;
		int					   skip_value  = 0;
		int					   count_comma = 0;

		if (pos == std::string::npos) {
			std::string::size_type pos = buf.find_first_of('|');
			if (pos == std::string::npos) {
				for (std::string::iterator it = buf.begin(); it != buf.end(); ++it) {
					input.date += *it;
				}
				skip_value = 1;
			} else {
				std::string date = buf.substr(0, pos);
				for (std::string::iterator it = date.begin(); it != date.end(); ++it) {
					if (*it != ' ') {
						input.date += *it;
					}
				}
				buf.erase(0, pos + 1);
				for (std::string::iterator it = buf.begin(); it != buf.end(); ++it) {
					if (*it == '.') {
						count_comma++;
					}
					if (count_comma > 1) {
						value_error = 1;
					}
					temp_value += *it;
				}
			}
			buf.clear();
		} else {
			std::string temp_line = buf.substr(0, pos);
			buf.erase(0, pos + 1);

			std::string::size_type pos_sep = temp_line.find_first_of('|');
			if (pos_sep == std::string::npos) {
				for (std::string::iterator it = temp_line.begin(); it != temp_line.end(); ++it) {
					if (*it != ' ') {
						input.date += *it;
					}
				}
				skip_value = 1;
			} else {
				std::string date = temp_line.substr(0, pos_sep);
				for (std::string::iterator it = date.begin(); it != date.end(); ++it) {
					if (*it != ' ') {
						input.date += *it;
					}
				}
				temp_line.erase(0, pos_sep + 1);
				for (std::string::iterator it = temp_line.begin(); it != temp_line.end(); ++it) {
					if (*it == '.') {
						count_comma++;
					}
					if (count_comma > 1) {
						value_error = 1;
					}
					temp_value += *it;
				}
			}
		}
		if (input.date.size() != 10) {
			input.error_state = bad_date;
		} else if (input.date.empty()) {
			input.error_state = end;
		} else if (value_error) {
			input.error_state = bad_value;
			input.date		  = temp_value;
		}
		if (!value_error) {
			std::stringstream ss;
			ss << temp_value;
			ss >> input.value;
			if (input.error_state == none) {
				if (ss.fail()) {
					if (!skip_value) {
						input.error_state = bad_value;
						input.date		  = temp_value;
					}
				}
				if (input.value < 0) {
					if (!skip_value) {
						input.error_state = negative;
					} else {
						input.value = 0;
					}
				}
				if (input.value > 1000) {
					input.error_state = too_large;
				}
			}
		}
		return input;
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
__NS__::find_and_exchange_(check_t check) {
	if (check.date[5] > '1' || check.date[8] > '3') {
		std::cout << "Error: bad input => " << check.date << std::endl;
		return;
	}
	container::iterator is_exist = data_.find(check.date);
	if (is_exist != data_.end()) {
		std::cout << check.date << " => " << check.value << " = ";
		std::cout << is_exist->second * check.value << std::endl;
	} else {
		container::iterator lower_data = data_.lower_bound(check.date);
		if (lower_data != data_.end()) {
			--lower_data;
			std::cout << check.date << " => " << check.value << " = ";
			std::cout << lower_data->second * check.value << std::endl;
		} else {
			std::cout << "Error: bad input => " << check.date << std::endl;
		}
	}
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

		void (*process_[7])(check_t) = {
			bad_date_,
			bad_value_,
			too_large_,
			negative_,
			NULL,
			NULL,
			NULL
		};

		std::string buf = ss.str();
		if (buf.empty()) {
			log_("Error", "buf is empty");
			exit(1);
		}
		std::string::size_type pos = buf.find_first_of('\n');
		if (buf.substr(0, pos) == "date | value") {
			buf.erase(0, pos + 1);
		} else {
			log_("Error", "bad start line of input file");
			exit(1);
		}

		while (!buf.empty()) {
			check_t check = parse_input_data_(buf);
			if (check.error_state != none && check.error_state != end) {
				process_[check.error_state](check);
			} else if (check.error_state == none) {
				find_and_exchange_(check);
			} else {
				break;
			}
		}

	} else {
		log_("Error", "could not open file.");
		exit(1);
	}
	file.close();
}

#undef __NS__
