#include <iostream>
#include <map>
#include <utility>

int
main() {
	std::map<int, int> map;

	map.insert(std::pair<int, int>(1, 1));
	map.insert(std::pair<int, int>(2, 1));

	std::map<int, int>::iterator it = map.begin();
	--it;
	// if (it == map.end())
	// 	std::cout << "end" << std::endl;
	// else
	// 	std::cout << "not end" << std::endl;

	std::cout << it->first << it->second << std::endl;
}
