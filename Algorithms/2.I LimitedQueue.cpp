#include <iostream>
#include <vector>

class Queue {
private:
	std::vector<int> queue;
	int head = 0;
	int tail = 0;
	int max_size;
	int size_ = 0;
public:
	Queue(int max_size_) : queue(std::vector<int>(max_size_)), max_size(max_size_) {};
	void push(int number) {
		if (head == max_size) head = 0;
		if (size_ != max_size) {
			queue[head] = number;
			head++;
			size_++;
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
	void pop() {
		if (size_ != 0) {
			std::cout << queue.at(tail) << std::endl;
			tail++;
			if (tail == max_size) { tail = 0; };
			size_--;
		}
		else {
			std::cout << "None" << std::endl;
		}
	}
	void peek() {
		if (size_ != 0) {
			std::cout << queue.at(tail) << std::endl;
		}
		else {
			std::cout << "None" << std::endl;
		}
	}
	void size() {
		std::cout << size_ << std::endl;
	}
};

int limitedQueue() {
	int number_command;
	int max_queue;
	std::cin >> number_command >> max_queue;
	Queue queue(max_queue);
	for (int i = 0; i < number_command; i++) {
		std::string command;
		std::cin >> command;
		if (command == "push") {
			int number;
			std::cin >> number;
			queue.push(number);
		}
		else if (command == "pop") {
			queue.pop();
		}
		else if (command == "peek") {
			queue.peek();
		}
		else if (command == "size") {
			queue.size();
		}
	}
	return 0;
}