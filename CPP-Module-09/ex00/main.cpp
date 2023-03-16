#include "BitcoinExchange.hpp"
#include <utility>

int
main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Error: ./btc [some.csv] ...txt" << std::endl;
		std::exit(1);
	}

	BitcoinExchange bitcoin(&argv[1]);
	return 0;
}
