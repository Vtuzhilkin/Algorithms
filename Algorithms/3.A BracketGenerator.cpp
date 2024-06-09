#include <iostream>
#include <string>
#include <vector>

void generation(int i, int j, std::string result, std::vector<std::string>& variations) {
	if (i == 0 && j == 0) {
		variations.push_back(result);
	}
	else {
		if (i != 0) {
			generation(i-1, j, result + '(', variations);
		}
		if (i < j) {
			generation(i, j-1, result + ')', variations);
		}
	}
}

int bracketGenerator() {
	std::vector<std::string> variations;
	std::string result;
	int number;
	std::cin >> number;
	generation(number, number, result, variations);
	for (const std::string& variation : variations) {
		std::cout << variation << std::endl;
	}

}

