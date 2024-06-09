#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

int jumpStairs() {
	int number_stairs, jump;
	std::cin >> number_stairs >> jump;
	std::vector<uint64_t> number_ways({0, 0, 1});
	uint64_t modul = pow(10, 9) + 7;
	for (int stair = 3; stair <= number_stairs + 1; stair++) {
		uint64_t ways = 0;
		for (int prev_start = 1; prev_start <= jump; prev_start++) {
			if (number_ways.size() > prev_start) {
				ways += number_ways[stair - prev_start];
			}
		}
		number_ways.push_back(ways % modul);
	}
		std::cout << number_ways.back();
	return 0;
}