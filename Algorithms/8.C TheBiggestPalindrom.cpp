#include <iostream>
#include <map>
#include <sstream>

std::string getPolindrom(std::map<char, int>& symbols, const int& size_string) {
	std::string result;
	char last_symbol = ' ';

	for (auto& [symbol, number] : symbols) {
		if (last_symbol == ' ' && number % 2 == 1) {
			last_symbol = symbol;
		}
		for (int i = 0; i < number / 2; i++) {
			result += symbol;
		}
		number = number / 2;
	}
	if (last_symbol != ' ') {
		result += last_symbol;
	}
	for (std::map<char, int>::reverse_iterator riter = symbols.rbegin(); riter != symbols.rend(); riter++) {
		while (riter->second) {
			riter->second--;
			result += riter->first;
		}
	}
	return result;
}

int theBiggestPalindrom() {
	std::map<char, int> symbols;
	std::string stroka;
	std::getline(std::cin, stroka);
	for (const char& symbol : stroka) {
		symbols[symbol]++;
	}

	std::cout << getPolindrom(symbols, int(stroka.size()));
	return 0;
}