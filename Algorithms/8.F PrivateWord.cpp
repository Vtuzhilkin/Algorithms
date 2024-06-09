#include <iostream>
#include <string>
#include <unordered_map>

int privateWord() {
	int number_strings;
	std::cin >> number_strings;
	std::unordered_map<std::string, int> dictionary;
	int frequency = 0;
	std::string frequency_word;
	for (int i = 0; i < number_strings; i++) {
		std::string new_string;
		std::cin >> new_string;
		dictionary[new_string]++;
		

		if (frequency == 0 || dictionary.at(new_string) > dictionary.at(frequency_word)) {
			frequency = dictionary.at(new_string);
			frequency_word = new_string;
		}
		else if (dictionary.at(new_string) == dictionary.at(frequency_word) && new_string < frequency_word) {
			frequency = dictionary.at(new_string);
			frequency_word = new_string;
		}


	}
	std::cout << frequency_word;
	return 0;
}