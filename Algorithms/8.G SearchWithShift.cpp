#include <iostream>
#include <vector>

std::vector<int> read(const int& size) {
	std::vector<int> different_temperatures;
	int temperature;

	if (size != 0) {
		std::cin >> temperature;
	}
	for (int i = 1; i < size; i++) {
		int next_temperature;
		std::cin >> next_temperature;
		different_temperatures.push_back(temperature - next_temperature);
		temperature = next_temperature;
	}
	return different_temperatures;
}

int searchWithShift() {
	int number_days, size_template;
	std::cin >> number_days;
	std::vector<int> different_temperatures = read(number_days);
	std::cin >> size_template;
	std::vector<int> different_templates = read(size_template);
	if (size_template == 1) {
		for (int i = 0; i < number_days; i++) {
			std::cout << i << " ";
		}
	}
	else if(size_template != 0 && number_days != 0){
		for (int i = 0; i <= int(different_temperatures.size()) - int(different_templates.size()); i++) {
			bool coincidence = true;
			for (int j = 0; j < different_templates.size(); j++) {
				if (different_temperatures.at(i + j) != different_templates.at(j)) {
					coincidence = false;
					break;
				}
			}
			if (coincidence) {
				std::cout << i + 1 << " ";
			}
		}
	}

}