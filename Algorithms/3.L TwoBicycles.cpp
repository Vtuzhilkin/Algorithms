#include <iostream>
#include <vector>

int search(const int& money, const std::vector<int>& summ_day) {
	int start = -1;
	int end = summ_day.size();
	int i = (end-start) / 2;
	while (i != 0 && i != summ_day.size()-1) {
		if (money > summ_day.at(i - 1) && money <= summ_day.at(i)) {
			return i + 1;
		}
		else if(money <= summ_day.at(i)){
			end = i;
			i = i - (end - start) / 2;
		}
		else if (money > summ_day.at(i)) {
			start = i;
			i = i + (end - start) / 2;
		}
	}
	if (money <= summ_day.at(i)) {
		return i + 1;
	}
	return -1;
}

int twoBicycles() {
	int number_days;
	std::cin >> number_days;
	std::vector<int> summ_day(number_days, 0);
	for (int i = 0; i < number_days; i++) {
		int money;
		std::cin >> money;
		summ_day[i] = money;
	}
	int money;
	std::cin >> money;
	std::cout << search(money, summ_day) << " ";
		std::cout << search(2 * money, summ_day);
	return 0;
}