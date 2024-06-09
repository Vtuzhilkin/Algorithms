#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

std::pair<int, int> operation_time(const std::string& time) {
	int hour = 0, minutes = 0;
	int position_point = time.find('.');
	if (position_point != -1) {
		hour = stoi(time.substr(0, position_point));
		minutes = stoi(time.substr(position_point + 1));
	}
	else {
		hour = stoi(time);
	}
	return std::make_pair(hour, minutes);
}

int schedule() {
	int number_lessons;
	std::cin >> number_lessons;
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lessons;
	for (int lesson = 0; lesson < number_lessons; lesson++) {
		std::string time_start, time_end;
		std::cin >> time_start >> time_end;
		lessons.push_back(std::make_pair(operation_time(time_end), operation_time(time_start)));
	}
	std::sort(lessons.begin(), lessons.end());
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> need_lessons;
	for (auto const& lesson: lessons) {
		if (!need_lessons.empty()) {
			auto const& end_previous = need_lessons.rbegin()->first;
			auto const& start_previous = need_lessons.rbegin()->second;

			auto const& end = lesson.first;
			auto const& start = lesson.second;

			if (end >= end_previous && start >= end_previous) {
				need_lessons.push_back(lesson);
			}
		}
		else {
			need_lessons.push_back(lesson);
		}
	}
	std::cout << need_lessons.size() << std::endl;
	for (auto const& [end, start] : need_lessons) {
		std::cout << start.first;
		if (start.second != 0) {
			std::cout << '.' << start.second;
		}
		std::cout << ' ' << end.first;
		if (end.second != 0) {
			std::cout << '.' << end.second;
		}
		std::cout << std::endl;
	}
	return 0;
}

