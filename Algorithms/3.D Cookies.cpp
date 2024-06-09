#include <iostream>
#include <vector>
#include <algorithm>


int cookies() {
	int number_children;
	std::cin >> number_children;
	std::vector<int> greed_factors;
	for (int i = 0; i < number_children; i++) {
		int greed_factor;
		std::cin >> greed_factor;
		greed_factors.push_back(greed_factor);
	}
	int	number_cookies;
	std::cin >> number_cookies;
	std::vector<int> cookies;
	for (int i = 0; i < number_cookies; i++) {
		int cookie;
		std::cin >> cookie;
		cookies.push_back(cookie);
	}
	std::sort(greed_factors.begin(), greed_factors.end());
	std::sort(cookies.begin(), cookies.end());
	int number_satisfied = 0;
	int number_cookie = 0;
	for (const int& greed_factor : greed_factors) {
		if (number_cookie == cookies.size()) break;
		while (number_cookie != cookies.size()) {
			if (greed_factor <= cookies.at(number_cookie)) {
				number_satisfied++;
				number_cookie++;
				break;
			}
			number_cookie++;
		}
	}
	std::cout << number_satisfied;
	return 0;
}
