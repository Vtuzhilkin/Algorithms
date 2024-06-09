// https://contest.yandex.ru/contest/22450/run-report/108800710/
#include <iostream>
#include <vector>


int nearestZero() {
	int number;
	std::cin >> number;
	std::vector<int> distances;
	std::vector<int> empty_areas;
	int distance = -1;
	for (size_t i = 0; i < number; i++) {
		int number_house;
		std::cin >> number_house;
		if (number_house == 0) {
			empty_areas.push_back(i);
			distances.push_back(number_house);
			distance = 0;
		}
		else {
			if (distance != -1) {
				distance++;
			}
			distances.push_back(distance);
		}
	}
	for (const int& empty_area : empty_areas) {
		int left = empty_area;
		if (left > 0) left--;
		int distance = 1;
		while (left >= 0) {
			if (left >= 0) {
				if (distances.at(left) == -1) {
					distances[left] = distance;
					left--;
				}
				else if (distances.at(left) > distance) {
					distances[left] = distance;
					left--;
				}
				else {
					left = -1;
				}
			}
			distance++;
		}
	}
	for (std::vector<int>::const_iterator iter = distances.cbegin(); iter != distances.cend(); iter++) {
		std::cout << *iter << " ";
	}
	return 0;
}