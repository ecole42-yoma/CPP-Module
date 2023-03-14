#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>

#define __NS__ BitcoinExchange

namespace {

	inline void
	log_(const char* s1, const char* s2 = NULL) {
		std::cout << s1;
		if (s2 != NULL) {
			std::cout << ": " << s2;
		}
		std::cout << std::endl;
	}

	inline void
	syntax_date_() { }

} // namespace

__NS__::BitcoinExchange(const char* csv_file) {
	std::fstream file;

	// db generator
	file.open(csv_file, std::ios_base::in);

	if (file.is_open()) {
		std::stringstream ss;

		ss << file.rdbuf();
		if (ss.fail()) {
			file.close();
			log_("Error", "ss error");
			exit(1);
		}

		std::string buf = ss.str();

		buf.erase(0, buf.find_first_of('\n') + 1);

		while (!buf.empty()) {
			std::string date = buf.substr(0, buf.find_first_of(','));

			std::string value = buf.substr()

									std::string::size_type valid_check
				= buf.find_first_of('\n');
			if (valid_check != std::string::npos) {
				buf.erase(0, valid_check + 1);
			} else {
				break;
			}
		}

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
		this->data_.insert(from.data_.begin(), from.data_.end());
	}
	return *this;
}

void
__NS__::exchange(const char* input) {
	std::fstream file;

	// db generator
	file.open(input, std::ios_base::in);

	if (file.is_open()) {
		// input_file process
		// open file
		// read per line
		// search db value
		// print calculate value
	} else {
		log_("Error", "could not open file.");
		exit(1);
	}
	file.close();
}

#undef __NS__
