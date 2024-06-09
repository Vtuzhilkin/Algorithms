#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int insertStrings() {
	std::string basic_string;
	std::getline(std::cin, basic_string);
	int number_new_string;
	std::cin >> number_new_string;
	std::vector<std::pair<int, std::string>> new_strings;
	for (int i = 0; i < number_new_string; i++) {
		std::string new_string;
		int position;
		std::cin >> new_string >> position;
		new_strings.push_back({ position, new_string });
	}
	std::sort(new_strings.begin(), new_strings.end());

	int start = 0;
	for (auto const& [position, new_string] : new_strings) {
		if (position <= basic_string.size()) {
			std::cout << basic_string.substr(start, position-start);
			start = position;
		}
		else {
			std::cout << basic_string.substr(start, basic_string.size());
		}
		std::cout << new_string;
	}
	if (start != basic_string.size()) {
		std::cout << basic_string.substr(start, basic_string.size());
	}
	return 0;
}