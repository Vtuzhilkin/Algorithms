#include <iostream>


int EvenAndOdd() {
	int a, b, c;
	std::cin >> a >> b >> c;
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (c < 0) c = -c;
	if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		std::cout << "WIN";
	}
	else if(a % 2 == 1 && b % 2 == 1 && c % 2 == 1) {
		std::cout << "WIN";
	}
	else {
		std::cout << "FAIL";

	}
	return 0;
}