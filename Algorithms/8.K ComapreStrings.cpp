#include <iostream>
#include <string>
#include <sstream>

bool remaining(const std::string& st, int index) {
	for (; index < st.size(); index++) {
		if (st.at(index) % 2 == 0) {
			return false;
		}
	}
	return true;
}

void compare(const std::string& first_string, const std::string& second_string) {
	int i = 0, j = 0;
	while (i != first_string.size() && j != second_string.size()) {
		if (first_string.at(i) % 2 == 0 && second_string.at(j) % 2 == 0) {
			if (first_string.at(i) > second_string.at(j)) {
				std::cout << 1 << std::endl;
				return;
			}
			else if (first_string.at(i) < second_string.at(j)) {
				std::cout << -1 << std::endl;
				return;
			}
			i++;
			j++;
		}
		else {
			if (first_string.at(i) % 2 != 0) {
				i++;
			}
			if (second_string.at(j) % 2 != 0) {
				j++;
			}
		}
	}
	bool equality = remaining(first_string, i) && remaining(second_string, j);
	if (equality) {
		std::cout << 0 << std::endl;
	}
	else if (i != first_string.size()) {
		std::cout << 1 << std::endl;
	}
	else if (j != second_string.size()) {
		std::cout << -1 << std::endl;
	}
}

int comapreStrings() {
	std::string first_string, second_string;
	std::getline(std::cin, first_string);
	std::getline(std::cin, second_string);
	compare(first_string, second_string);
	return 0;
}