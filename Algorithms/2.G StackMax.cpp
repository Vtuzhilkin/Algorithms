#include <iostream>
#include <vector>

class StackMax {
private:
	std::vector<int> stack;
	std::vector<int> stackmax;

public:
	void push(int number) {
		if (stack.size() == 0 || *(--stackmax.cend()) <= number) {
			stackmax.push_back(number);
		}
		stack.push_back(number);
	}

	void pop() {
		if (stack.size() != 0) {
			if (*(--stackmax.cend()) == *(--stack.cend())) {
				stackmax.pop_back();
			}
			stack.pop_back();
		}
		else {
			std::cout << "error" << std::endl;
		}
	}

	void get_max() {
		if (stack.size() != 0) {
			std::cout << *(--stackmax.cend()) << std::endl;
		}
		else {
			std::cout << "None" << std::endl;
		}
	}

	void top() {
		if (stack.size() != 0) {
			std::cout << *(--stack.cend()) << std::endl;
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
};

int stackMax() {
	StackMax stackmax;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string command;
		std::cin >> command;
		if (command == "get_max") {
			stackmax.get_max();
		}
		else if(command == "push") {
			int number;
			std::cin >> number;
			stackmax.push(number);
		}
		else if (command == "pop") {
			stackmax.pop();
		}
		else if (command == "top") {
			stackmax.top();
		}
	}
	return 0;
}