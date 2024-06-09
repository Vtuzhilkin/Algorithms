#include <iostream>
#include <string>
#include <sstream>

int theLongestWord() {

	int length_sentece = 0;
	std::cin >> length_sentece;

	std::string sentece;
	std::getline(std::cin, sentece);
	std::getline(std::cin, sentece);

	int number_space = 0;
	int result = 0;
	int size_word = 0;
	int start_word = 0;
	for (int i = 0; i <= length_sentece; i++) {
		if (i == length_sentece || sentece.at(i) == ' ') {
			size_word = i - number_space;
			if (result < size_word) {
				start_word = number_space;
				result = size_word;
			}
			number_space = i + 1;
		}
	}
	std::cout << sentece.substr(start_word, result) << std::endl;
	std::cout << result;
	return 0;
}