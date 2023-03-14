#include "PmergeMe.hpp"

void
log_(const char* s1, const char* s2 = NULL) {
	std::cout << s1;
	if (s2 != NULL) {
		std::cout << ": " << s2;
	}
	std::cout << std::endl;
}
