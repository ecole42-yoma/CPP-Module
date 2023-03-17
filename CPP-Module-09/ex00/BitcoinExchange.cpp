#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#define __NS__ BitcoinExchange

namespace {

inline bool syntax_(const int table[8], char c) {
  return (table[(c >> 5)] & (1U << (c & 0x1f)));
}

const int date_[] = {
    0x00000000, /*	0000 0000 0000 0000  0000 0000 0000 0000 */
    /*				?>=< ;:98 7654 3210  /.-, +*)( '&%$ #"!  */
    0x03ff0000, /*	0000 0011 1111 1111  0000 0000 0000 0000 */
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
    0x03ff0000, /*	0000 0011 1111 1111  0000 0000 0000 0000 */
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
inline void log_(const char *s1, const _Tp s2, std::string s3 = ":") {
  std::cout << COLOR_RED << s1 << COLOR_RESET << s3 << " " << s2 << std::endl;
}

inline void log_line_(std::string file_name, size_t line_number,
                      std::string message) {
  std::cout << file_name << ":" << line_number << ": " << COLOR_RED
            << "error: ";
  std::cout << COLOR_YELLOW << message << COLOR_RESET << std::endl;
}

inline void result_log_(const check_t &check, double value = 0) {
  switch (check.error_state) {
  case bad_date: {
    log_("Error: bad input : date ", check.date, "=>");
    break;
  }
  case bad_value: {
    log_("Error: bad input : value ", check.date, "=>");
    break;
  }
  case too_large: {
    log_("Error: too large a number. ", check.value);
    break;
  }
  case negative: {
    log_("Error: not a positive number. ", check.value);
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

inline bool is_valid_date_(size_t year, size_t month, size_t day) {
  if (year < 2009 || year > 2023) {
    return false;
  } else if (month < 1 || month > 12) {
    return false;
  } else if (day < 1 || day > 31) {
    return false;
  } else if (month == 2) {
    if (day > 29) {
      return false;
    } else if (day == 29) {
      if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
        return false;
      }
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      return false;
    }
  }
  return true;
}

inline bool is_file_of_(std::string extension, std::string file,
                        void (*log)(const char *, const char *,
                                    std::string) = NULL) {
  if (file.size() > extension.size() &&
      file.substr(file.size() - 4, 4) == extension) {
    return true;
  } else if (log != NULL) {
    log("Error: not a valid file name", file.c_str(), ":");
  }
  return false;
}

inline bool check_start_line_(std::string buf, std::string s1, std::string s2,
                              std::string delim) {
  if (buf == s1 + delim + s2) {
    return true;
  }
  return false;
}

inline bool check_date_(const std::string &date) {
  if (date.size() != 10) {
    return false;
  }
  enum {
    v_year,
    v_dash_1,
    v_month,
    v_dash_2,
    v_day,
    v_error,
    v_end
  } state = v_year;

  std::string year, month, day;
  std::string::const_iterator it = date.begin();
  while (state != v_end) {
    switch (state) {
    case v_year: {
      while (it != date.end() && syntax_(date_, *it)) {
        ++it;
      }
      if (it == date.end()) {
        state = v_error;
      } else if (*it == '-') {
        year = date.substr(0, 4);
        state = v_dash_1;
      } else {
        state = v_error;
      }
      break;
    }
    case v_dash_1: {
      if (*it == '-') {
        ++it;
        state = v_month;
      } else {
        state = v_error;
      }
      break;
    }
    case v_month: {
      while (it != date.end() && syntax_(date_, *it)) {
        ++it;
      }
      if (it == date.end()) {
        state = v_error;
      } else if (*it == '-') {
        state = v_dash_2;
        month = date.substr(5, 2);
      } else {
        state = v_error;
      }
      break;
    }
    case v_dash_2: {
      if (*it == '-') {
        ++it;
        state = v_day;
      } else {
        state = v_error;
      }
      break;
    }
    case v_day: {
      while (it != date.end() && syntax_(date_, *it)) {
        ++it;
      }
      if (it == date.end()) {
        state = v_end;
        day = date.substr(8, 2);
      } else {
        state = v_error;
      }
      break;
    }
    case v_end: {
      break;
    }
    case v_error:
    default: {
      return false;
    }
    }
  }
  if (!is_valid_date_(std::atoi(year.c_str()), std::atoi(month.c_str()),
                      std::atoi(day.c_str()))) {
    return false;
  }
  return true;
}

inline bool check_value_(const std::string &value, double &output_value,
                         error_state_e &error, number_over_t &over_flag) {
  enum { v_number, v_dot, v_error, v_end } state = v_number;

  bool dot = false;
  std::string::const_iterator it = value.begin();

  while (state != v_end) {
    switch (state) {
    case v_number: {
      if (*it == '-') {
        error = negative;
        ++it;
      }
      while (it != value.end() && syntax_(value_, *it)) {
        ++it;
      }
      if (it == value.end()) {
        state = v_end;
      } else {
        state = v_dot;
      }
      break;
    }
    case v_dot: {
      if (it == value.end()) {
        state = v_end;
      } else if (*it == '.' && !dot) {
        dot = true;
        ++it;
        state = v_number;
      } else {
        state = v_error;
        error = bad_value;
      }
      break;
    }
    case v_end: {
      break;
    }
    case v_error:
    default: {
      return false;
    }
    }
  }
  std::stringstream ss;
  ss << value;
  ss >> output_value;
  if (ss.fail()) {
    error = bad_value;
    return false;
  } else if (output_value < 0) {
    error = negative;
    return false;
  } else if (output_value > 2147483647) {
    error = too_large;
    return false;
  } else if (over_flag == on && (output_value >= 1000 || output_value <= 0)) {
    error = bad_value;
    return false;
  }
  return true;
}

inline check_t check_basic_line_(std::string buf, std::string delim,
                                 number_over_t over_flag) {
  check_t check;
  check.error_state = none;
  check.value = 0;
  check.date = buf;

  std::string::size_type pos = buf.find(delim);
  if (pos == std::string::npos) {
    check.error_state = bad_date;
    return check;
  }
  std::string date = buf.substr(0, pos);
  std::string value =
      buf.substr(pos + delim.size(), buf.size() - pos - delim.size());
  check.date = date;
  if (!check_date_(date)) {
    check.error_state = bad_date;
    return check;
  }
  if (!check_value_(value, check.value, check.error_state, over_flag)) {
    check.date = value;
  }
  return check;
}
} // namespace

__NS__::BitcoinExchange(char **argv) {
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
    std::cout << "Info: " << argv[0] << " is used as database" << std::endl;
    argv = &argv[1];
  } else {
    init_db_("data.csv");
    std::cout << COLOR_BLUE << "Info: ./data.csv is used as database"
              << COLOR_RESET << std::endl;
  }
  for (size_t i = 0; argv[i] != NULL; ++i) {
    exchange_(argv[i]);
  }
}

__NS__::~BitcoinExchange() {}

__NS__::BitcoinExchange(__NS__::const_reference from) { *this = from; }

__NS__::reference __NS__::operator=(__NS__::const_reference from) {
  if (this != &from) {
    data_ = from.data_;
  }
  return *this;
}

void __NS__::init_db_(std::string db_file) {
  std::fstream file(db_file.c_str(), std::ios::in);
  if (!file.is_open()) {
    log_("Error: can't open file", db_file.c_str());
    exit(1);
  }

  std::string buf;
  size_t line_number = 0;
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
    } else if (buf[0] == '#' || buf[0] == '\n' || buf.size() == 0) {
      continue;
    } else {
      check_t check = check_basic_line_(buf, ",", off);
      switch (check.error_state) {
      case none: {
        data_.insert(std::make_pair(check.date, check.value));
        break;
      }
      case bad_date: {
        log_line_(db_file, line_number, "invalid date [0000-00-00]");
        break;
      }
      case bad_value: {
        log_line_(db_file, line_number, "invalid value");
        break;
      }
      case too_large: {
        log_line_(db_file, line_number, "invalid value [too large]");
        break;
      }
      case negative: {
        log_line_(db_file, line_number, "invalid value [negative]");
        break;
      }
      case end:
      default: {
        log_line_(db_file, line_number, "invalid state");
        break;
      }
      }
      // TODO : should i check leak?
    }
  }
  file.close();
}

void __NS__::find_and_exchange_(check_t check) {
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

void __NS__::exchange_(const char *input) {
  std::cout << '\n'
            << COLOR_GREEN << input << "'s result" << COLOR_RESET << std::endl;
  if (input == NULL || input[0] == '\0' || !is_file_of_(".txt", input, log_)) {
    return;
  }
  std::fstream file(input, std::ios::in);
  if (!file.is_open()) {
    log_("Error: can't open file", input);
    return;
  }

  std::string buf;
  size_t line_number = 0;
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
    } else if (buf[0] == '#' || buf[0] == '\n' || buf.size() == 0) {
      std::cout << std::endl;
      continue;
    } else {
      check_t check = check_basic_line_(buf, " | ", on);
      if (check.error_state == none) {
        find_and_exchange_(check);
      } else {
        result_log_(check);
      }
    }
  }
  if (line_number == 0) {
    log_("Error: empty file", input);
  }
  file.close();
  std::cout << std::endl;
}

#undef __NS__
