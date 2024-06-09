// https://contest.yandex.ru/contest/22450/run-report/108799421/
#include <iostream>


int sleightHand() {
	int digits[9] = { 0 };
	int fingers;
	std::cin >> fingers;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char digit;
			std::cin >> digit;
			if (digit != '.') {
				digits[digit - 49]++;
			}
		}
	}
	int scores = 0;
	for (int i = 1; i <= 9; i++) {
		if (digits[i-1] <= 2 * fingers && digits[i - 1] != 0) {
			scores++;
		}
	}
	std::cout << scores;
	return 0;
}