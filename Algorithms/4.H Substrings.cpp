#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int calculate_length_substr(const std::string& stroka) {
	std::unordered_map<char, int> symbols;
	int start = 0;
	int length = 0;
	for (int end = 0; end < stroka.size(); end++) {
		char symbol = stroka.at(end);
		if (symbols.find(symbol) != symbols.end() && symbols[symbol] >= start) {
			start = symbols.find(symbol)->second + 1;
		}
		symbols[symbol] = end;
		length = std::max(length, end - start + 1);
		
	}
	return length;
}

int substrings() {
	std::string stroka;
	std::cin >> stroka;
	std::cout << calculate_length_substr(stroka);
	return 0;
}