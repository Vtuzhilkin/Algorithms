#include <iostream>
#include <string>
#include <unordered_map>

struct Node {
	Node() {};
	Node(std::string prt) : partString(prt) {};
	std::string partString;
	std::unordered_map<char, std::vector<Node*>> nodes;
};


int camelCase() {
	int number_strings;
	std::cin >> number_strings;
	std::vector<Node> nodes;
	Node root;
	for (int i = 0; i < number_strings; i++) {
		Node* current_node = &root;

		std::string new_string;
		std::cin >> new_string;

		std::string part_string;
		for (const char& symbol : new_string) {
			part_string += symbol;
			if (isupper(symbol)) {
				if(current_node->nodes.find(symbol))
			}
		}
	}
	return 0;
}