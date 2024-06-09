//#include <iostream>
//#include <vector>
//
//int main() {
//	int number_chips;
//	std::cin >> number_chips;
//	std::vector<int> chips;
//	for (int i = 0; i < number_chips; i++) {
//		int number_chip;
//		std::cin >> number_chip;
//		chips.push_back(number_chip);
//	}
//	int hidden_number;
//	std::cin >> hidden_number;
//	int i = 0, j = chips.size() - 1;
//	while (true) {
//		int sum = chips.at(i) + chips.at(j);
//		if (sum == hidden_number) {
//			std::cout << chips.at(i) << " " << chips.at(j);
//			break;
//		}
//		else if (sum > hidden_number) {
//			j--;
//		}
//		else if (sum < hidden_number) {
//			i++;
//		}
//		if (i == j) {
//			std::cout << "None";
//			break;
//		}
//	}
//	return 0;
//}