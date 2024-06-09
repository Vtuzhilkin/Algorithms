#include <iostream>
#include <vector>

// 7 5 4 2

int calculate_profit(const std::vector<int> share_price) {
	int profit = 0;
	int purchase = -1, sale = -1;
	for (const int& price : share_price) {
		if (purchase == -1 || purchase > price && sale == -1) {
			purchase = price;
		}
		else if (sale < price) {
			sale = price;
		}
		else if (sale > price) {
			profit += sale - purchase;
			purchase = price;
			sale = -1;
		}
		
	}
	if (sale != -1) {
		profit += sale - purchase;
	}
	return profit;
}

int stockMarket() {
	int number_days;
	std::cin >> number_days;
	std::vector<int> share_price;
	for (int day = 0; day < number_days; day++) {
		int price;
		std::cin >> price;
		share_price.push_back(price);
	}
	std::cout << calculate_profit(share_price);
	return 0;
}