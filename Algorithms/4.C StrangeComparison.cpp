#include <iostream>
#include <unordered_map>

bool comparison(const std::string& first_string, const std::string& second_string) {
	std::unordered_map<char, char> accordance;
	bool equal = true;
	if (first_string.size() == second_string.size()) {
		for (size_t i = 0; i < first_string.size(); i++) {
			if (accordance.find(first_string.at(i)) == accordance.end()) {
				accordance[first_string.at(i)] = second_string.at(i);
			}
			else {
				if (accordance[first_string.at(i)] != second_string.at(i)) {
					equal = false;
					break;
				}
			}
		}
	}
	else {
		equal = false;
	}
	return equal;
}

int strangeComparison() {
	std::string first_string, second_string;
	std::cin >> first_string >> second_string;
	if (comparison(first_string, second_string) && comparison(second_string, first_string)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}