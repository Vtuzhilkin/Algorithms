#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int buyingHouse() {
	int number_houses, money;
	std::cin >> number_houses >> money;
	std::vector<int> cost_houses;
	int houses = 0;
	for (int i = 0; i < number_houses; i++) {
		int cost_house;
		std::cin >> cost_house;
		cost_houses.push_back(cost_house);
	}
	std::sort(cost_houses.begin(), cost_houses.end());
	for (const int& cost_house : cost_houses) {
		if (money >= cost_house) {
			houses++;
			money -= cost_house;
		}
		else {
			break;
		}
	}
	std::cout << houses;
	return 0;
}