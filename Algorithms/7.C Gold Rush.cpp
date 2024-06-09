#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdint>

uint64_t calculate_cost(const std::vector<std::pair<uint64_t, uint64_t>>& heaps, int load_capacity) {
	uint64_t summ_cost = 0;
	for (auto const& [cost, mass] : heaps) {
		if (mass <= load_capacity) {
			summ_cost += cost * mass;
			load_capacity -= mass;
		}
		else {
			summ_cost += cost * load_capacity;
			break;
		}
	}
	return summ_cost;
}


int glodRush() {
	int load_capacity;
	int number_heaps;
	std::cin >> load_capacity >> number_heaps;
	std::vector<std::pair<uint64_t, uint64_t>> heaps;
	for (int i = 0; i < number_heaps; i++) {
		int mass, cost;
		std::cin >> cost >> mass;
		heaps.push_back({ cost, mass });
	}
	std::sort(heaps.rbegin(), heaps.rend());
	std::cout << calculate_cost(heaps, load_capacity);
	return 0;
}