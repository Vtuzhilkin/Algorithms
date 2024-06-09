#include <iostream>
#include <string>

std::string start_prefix(const std::string& first_string, const std::string& second_string) {
	std::string prefix;
	for (int i = 0; i < std::min(first_string.size(), second_string.size()); i++) {
		if (first_string.at(i) == second_string.at(i)) {
			prefix += first_string.at(i);
		}
		else {
			break;
		}
	}
	return prefix;
}

int commonPrefix() {
	int number_strings;
	std::cin >> number_strings;
	std::string prefix;
	if (number_strings == 1) {
		std::cin >> prefix;
	}
	else if (number_strings >= 2) {
		std::string first_string, second_string;
		std::cin >> first_string >> second_string;
		prefix = start_prefix(first_string, second_string);

		for (int i = 2; i < number_strings; i++) {
			std::cin >> second_string;
			prefix = start_prefix(prefix, second_string);
		}
	}

	std::cout << prefix.size();
	return 0;
}