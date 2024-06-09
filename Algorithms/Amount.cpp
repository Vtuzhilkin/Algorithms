#include <iostream>
#include <string>

std::string binary_sum(std::string& first, std::string& second) {
	int inMind = 0;
	std::string sum;
	for (int i = second.size() - 1, j = first.size()-1; i >= 0; i--, j--) {
		if (first.at(j) == '0' && second.at(i) == '0') {
			if (inMind == 0) {
				sum += '0';
			}
			else {
				sum += '1';
				inMind--;
			}
		}
		else if ((first.at(j) == '0' && second.at(i) == '1') || (first.at(j) == '1' && second.at(i) == '0')) {
			if (inMind == 0) {
				sum += '1';
			}
			else {
				sum += '0';
			}
		}
		else {
			if (inMind == 0) {
				sum += '0';
				inMind++;
			}
			else {
				sum += '1';
			}
		}
	}
	for (int i = first.size() - second.size() - 1; i >= 0; i--) {
		if (inMind == 0) {
			sum += first.at(i);
		}
		else {
			if (first.at(i) == '0') {
				sum += '1';
				inMind--;
			}
			else {
				sum += '0';
			}
		}
	}
	if (inMind != 0) {
		sum += '1';
	}
	return sum;
}


int flowerBeds() {
	std::string number_two;
	std::string number_one;
	std::string result;
	std::cin >> number_one >> number_two;
	if (number_one.size() > number_two.size()) {
		result = binary_sum(number_one, number_two);
	}
	else {
		result = binary_sum(number_two, number_one);
	}
	for (int i = result.size() - 1; i >= 0; i--) {
		std::cout << result.at(i);
	}
	return 0;
}