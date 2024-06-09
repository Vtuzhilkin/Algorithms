#include <iostream>
#include <vector>

int subsequence() {
	std::string subsequence, sequence;
	std::cin >> subsequence >> sequence;
	
	std::string::iterator iter = sequence.begin();
	int length_subsequence = subsequence.size();

	for (const char& symbol : subsequence) {
		for (; iter != sequence.end(); iter++) {
			if (*iter == symbol) {
				length_subsequence--;
				iter++;
				break;
			}
		}
		if (length_subsequence == 0) {
			break;
		}
	}
	if (!length_subsequence) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}

	return 0;
}