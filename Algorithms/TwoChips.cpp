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
//	bool found = false;
//	for (std::vector<int>::const_iterator iter_first = chips.cbegin(); iter_first != (chips.cend()-2); iter_first++) {
//		for (std::vector<int>::const_iterator iter_second = (iter_first+1); iter_second != chips.cend(); iter_second++) {
//			if (*iter_first + *iter_second == hidden_number) {
//				std::cout << *iter_first << " " << *iter_second;
//				found = true;
//				if (found) break;
//			}
//		}
//		if (found) break;
//	}
//	if (!found) {
//		std::cout << "None";
//	}
//	return 0;
//}