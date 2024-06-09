#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

int mugs() {
	std::unordered_map<std::string, int> hobbies;
	std::vector<std::string> order_hobbies;
	int number;
	std::cin >> number;
	std::string hobby;
	std::getline(std::cin, hobby);
	for (int i = 0; i < number; i++) {
		std::getline(std::cin, hobby);
		if (hobbies.find(hobby) != hobbies.end()) {
			hobbies[hobby]++;
		}
		else {
			hobbies[hobby] = 1;
			order_hobbies.push_back(hobby);
		}

	}
	for (const std::string& hobby : order_hobbies) {
		std::cout << hobby << std::endl;
	}
	return 0;
}