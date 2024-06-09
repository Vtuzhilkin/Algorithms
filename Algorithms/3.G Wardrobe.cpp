#include <iostream>
#include <vector>

int wardrobe() {
	int N;
	std::cin >> N;
	std::vector<int> colors(3, 0);
	for (int i = 0; i < N; i++) {
		int color;
		std::cin >> color;
		colors[color]++;
	}
	for (int i = 0; i < colors.size(); i++) {
		for (int j = 0; j < colors[i]; j++) {
			std::cout << i << " ";
		}
	}
	return 0;
}