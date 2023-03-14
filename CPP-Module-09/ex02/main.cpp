#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>

namespace {
	inline void
	log_(const char* s1, const char* s2 = NULL) {
		std::cout << s1;
		if (s2 != NULL) {
			std::cout << ": " << s2;
		}
		std::cout << std::endl;
	}

	inline bool
	is_positive_number_(const char* s) {
		if (s == NULL) {
			return false;
		}
		for (int i = 0; s[i] != '\0'; ++i) {
			if (!std::isdigit(s[i])) {
				return false;
			}
		}
		return true;
	}

	inline void
	print_before_(int argc, char** argv) {
		std::cout << "Before: \t";
		for (int i = 1; i < argc; ++i) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
	}

} // namespace

int
main(int argc, char** argv) {
	if (argc != 2) {
		log_("Error", "./PmergeMe \"numbers...\"");
	}

	posi_vector vector;
	posi_deque	deque;

	for (int i = 1; i < argc; ++i) {
		if (is_positive_number_(argv[i])) {
			vector.push_back(std::atoi(argv[i]));
			deque.push_back(std::atoi(argv[i]));
		} else {
			log_("Error");
			exit(1);
		}
	}
	print_before_(argc, argv);
	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << " ";
	}

	PmergeMe<posi_vector> vector_merge(vector, print_on);
	PmergeMe<posi_deque>  deque_merge(deque, print_off);

	return 0;
}
