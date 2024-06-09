#include <iostream>
#include <vector>
#include <algorithm>

int perimeterTriangle() {
	int number_sides;
	std::cin >> number_sides;
	std::vector<int> sides;

	for (int i = 0; i < number_sides; i++) {
		int side;
		std::cin >> side;
		sides.push_back(side);
	}

	std::sort(sides.begin(), sides.end());
	std::vector<int>::const_reverse_iterator side = sides.crbegin();
	int perimeter = 0;
	for (; side != (sides.crend()-2); side++) {
		if (*side < *(side + 1) + *(side + 2)) {
			perimeter = *side + *(side + 1) + *(side + 2);
			break;
		}
	}
	std::cout << perimeter;
	return 0;
}