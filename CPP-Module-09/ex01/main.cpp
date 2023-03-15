#include "RPN.hpp"
#include <iostream>

int
main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Error: ./RPN \"...expressions\"" << std::endl;
		return 1;
	} else {
		RPN rpn(argv[1]);
	}
}
