#include <iostream>
#include <vector>

int ChaoticWeather() {
	int N;
	std::cin >> N;
	std::vector<int> temperatures;
	int chaotic = 0;
	for (int i = 0; i < N; i++) {
		int temperature;
		std::cin >> temperature;
		temperatures.push_back(temperature);
	}
	if (temperatures.size() != 1) {
		bool previous = true;
		for (std::vector<int>::const_iterator iter = temperatures.cbegin(); iter < temperatures.cend() - 1;) {
			if (previous) {
				if (*iter > *(iter + 1)) {
					chaotic++;
					previous = false;
					iter = iter + 2;
				}
				else if(*iter < *(iter + 1)){
					previous = true;
					iter++;
				}
				else {
					previous = false;
					iter++;
				}
			}
			else {
				if (*iter > *(iter - 1)) {
					if (*iter > *(iter + 1)) {
						chaotic++;
						previous = false;
						iter = iter + 2;
					}
					else if(*iter < *(iter+1)){
						previous = true;
						iter++;
					}
					else {
						previous = false;
						iter++;
					}
				}
				else {
					if (*iter > *(iter + 1)) {
						previous = false;
						iter = iter + 2;
					}
					else if (*iter < *(iter + 1)) {
						previous = true;
						iter++;
					}
					else {
						previous = false;
						iter++;
					}
				}
			}
		}
		if (*temperatures.rbegin() > *(temperatures.rbegin() + 1)) chaotic++;
	}
	else {
		chaotic++;
	}
	std::cout << chaotic;
	return 0;
}