#include <iostream>
#include <string>
#include <vector>
#include <list>


std::vector<std::string> keys = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void generation(std::string numbers, std::string result, std::vector<std::string>& combinations) {
	if (numbers.size() == 0) {
		combinations.push_back(result);
	}
	else {
		char number = numbers.front();
		numbers.erase(0, 1);
		for (const char& letter : keys.at(number - 50)){
			generation(numbers, result + letter, combinations);
		}
	}
}

int combination() {
	std::string numbers;
	std::cin >> numbers;
	std::vector<std::string> combinations;
	generation(numbers, "", combinations);
	for (const std::string& combination : combinations) {
		std::cout << combination << " ";
	}
	return 0;
}