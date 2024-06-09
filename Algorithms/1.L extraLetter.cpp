#include <iostream>
#include <unordered_map>

int extraLetter() {
	std::unordered_map<char, int> letters;
	std::string first;
	std::string second;
	std::cin >> first >> second;
	for (char& ch : first) {
		ch = tolower(ch);
		if (letters.find(ch) != letters.end()) {
			letters[ch] += 1;
		}
		else {
			letters[ch] = 1;
		}
	}
	for(char& ch: second){
		ch = tolower(ch);
		if (letters.find(ch) != letters.end()) {
			if (letters.at(ch) != 0) {
				letters[ch]--;
			}
			else {
				std::cout << ch;
				break;
			}
		}
		else {
			std::cout << ch;
			break;
		}
	}
	return 0;
}