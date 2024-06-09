#include <iostream>
#include <list>

class ListQueue {
private:
	std::list<int> queue;
public:
	void get() {
		if (!queue.empty()) {
			std::cout << *queue.cbegin() << std::endl;
			queue.pop_front();
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
	void put(int number) {
		queue.push_back(number);
	}
	void size() {
		std::cout << queue.size() << std::endl;
	}
};

int listQueue() {
	int number_command;
	std::cin >> number_command;
	ListQueue queue;
	for (int i = 0; i < number_command; i++) {
		std::string command;
		std::cin >> command;
		if (command == "put") {
			int number;
			std::cin >> number;
			queue.put(number);
		}
		else if (command == "get") {
			queue.get();
		}
		else if (command == "size") {
			queue.size();
		}
	}
	return 0;
}