#include <iostream>
#include <vector>
#include <sstream>

bool is_correct_bracket_seq(std::string& bracketSequence) {
	std::vector<char> brackets;
	for (const char& bracket: bracketSequence) {
		if (bracket == '(' || bracket == '[' || bracket == '{') {
			brackets.push_back(bracket);
		}
		else if (brackets.size() != 0) {
			if (bracket == ')') {
				if (*--brackets.cend() == '(') {
					brackets.pop_back();
				}
				else {
					return false;
				}
			}
			else if (bracket == ']') {
				if (*--brackets.cend() == '[') {
					brackets.pop_back();
				}
				else {
					return false;
				}
			}if (bracket == '}') {
				if (*--brackets.cend() == '{') {
					brackets.pop_back();
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	if (brackets.size() != 0) {
		return false;
	}
	return true;
}

int bracketSequence() {
	std::string bracketSequence;
	std::getline(std::cin, bracketSequence);
	if (is_correct_bracket_seq(bracketSequence)) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}
	return 0;
}