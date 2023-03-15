#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <set>

namespace {
	inline void
	log_(const char* s1, const char* s2 = NULL) {
		std::cout << s1;
		if (s2 != NULL) {
			std::cout << ": " << s2;
		}
		std::cout << std::endl;
		std::exit(1);
	}

	inline bool
	is_number_(const char* s) {
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

} // namespace

int
main(int argc, char** argv) {
	if (argc == 1) {
		log_("Error", "./PmergeMe \"...numbers\"");
	}

	posi_vector		 vector;
	posi_deque		 deque;
	std::set<size_t> set_for_dup;

	for (int i = 1; i < argc; ++i) {
		if (is_number_(argv[i])) {
			size_t temp = std::atoi(argv[i]);
			if (temp <= 0) {
				log_("Error", "Number must be positive");
			}
			if (set_for_dup.find(temp) != set_for_dup.end()) {
				log_("Error", "Duplicate number");
			}
			set_for_dup.insert(temp);
			vector.push_back(temp);
			deque.push_back(temp);
		} else {
			log_("Error", "digit only");
		}
	}

	PmergeMe<posi_vector> vector_merge(vector, print_on);
	PmergeMe<posi_deque>  deque_merge(deque, print_off);

	return 0;
}
