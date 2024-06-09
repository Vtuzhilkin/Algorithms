#include <iostream>
#include <sstream>
#include <string>

bool isLetterDigit(const char& letter) {
	if (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z' || letter >= '0' && letter <= '9')
		return true;
	else
		return false;
}

bool palindrom(const std::string& sentence) {
	std::string new_sentence;
	int i = 0, j = sentence.size() - 1;
	while (i <= j) {
		if (isLetterDigit(sentence.at(i)) && isLetterDigit(sentence.at(j))) {
			if (tolower(sentence.at(i)) != tolower(sentence.at(j))) {
				return false;
			}
			i++;
			j--;
		}
		else {
			if (!isLetterDigit(sentence.at(i))) {
				i++;
			}
			if (!isLetterDigit(sentence.at(j))) {
				j--;
			}
		}
	}
	return true;
}

int Palindromn() {
	std::string sentence;
	std::getline(std::cin, sentence);
	if (palindrom(sentence)) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}
}