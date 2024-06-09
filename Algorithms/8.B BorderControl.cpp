#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int calculate_sufix(const std::string& first, const std::string& second) {
	int size = std::min(first.size(), second.size());
	int i = 1;
	for (; i <= size; i++) {
		if (first.at(first.size() - i) != second.at(second.size() - i)) {
			break;
		}
	}
	return std::max(first.size(), second.size()) - i;
}

int calculate_prefix(const std::string& first, const std::string& second) {
	int size = std::min(first.size(), second.size());
	for (int i = 0; i < size; i++) {
		if (first.at(i) != second.at(i)) {
			return i;
		}
	}
	return size;
}

int borderControl() {
	std::string first_word, second_word;
	std::cin >> first_word >> second_word;
	int prefix = calculate_prefix(first_word, second_word);
	if (prefix == first_word.size() && prefix == second_word.size()) {
		std::cout << "OK";
	}
	else {
		int sufix = calculate_sufix(first_word.substr(prefix, first_word.size()), second_word.substr(prefix, second_word.size()));
		if (sufix == 1 || sufix == 0) {
			std::cout << "OK";
		}
		else {
			std::cout << "FAIL";
		}
	}
	return 0;
}