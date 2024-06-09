#include <iostream>
#include <list>

void sumNumbers(const std::list<int>& first, const std::list<int>& second) {
	int inMind = 0;
	std::list<int> sum;
	std::list<int>::const_iterator f_iter = first.cbegin();
	for (std::list<int>::const_iterator s_iter = second.cbegin(); s_iter != second.cend(); s_iter++, f_iter++) {
		int number = *f_iter + *s_iter + inMind;
		inMind = 0;
		if (number >= 10) {
			inMind = number / 10;
			sum.push_front(number % 10);
		}
		else {
			sum.push_front(number);
		}
	}
	for(; f_iter != first.cend(); f_iter++) {
		if (inMind == 0) {
			sum.push_front(*f_iter);
		}
		else {
			sum.push_front(*f_iter + 1);
			inMind--;
		}
	}
	if(inMind != 0) sum.push_front(inMind);
	for (std::list<int>::const_iterator iter = sum.cbegin(); iter != sum.cend(); iter++) {
		std::cout << *iter << " ";
	}
}

int listForm() {
	int size_number_first = 0;
	std::cin >> size_number_first;
	std::list<int> numbers_first;
	for (int i = 0; i < size_number_first; i++) {
		int digit;
		std::cin >> digit;
		numbers_first.push_front(digit);
	}
	int size_number_second = 0;
	int number_second;
	std::cin >> number_second;
	std::list<int> numbers_second;
	while (number_second != 0) {
		numbers_second.push_back(number_second % 10);
		number_second = number_second / 10;
		size_number_second++;
	}
	if (size_number_first > size_number_second) {
		sumNumbers(numbers_first, numbers_second);
	}
	else {
		sumNumbers(numbers_second, numbers_first);
	}
	return 0;
}
