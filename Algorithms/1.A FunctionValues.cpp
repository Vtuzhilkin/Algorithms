#include <iostream>

int FunctionValus() {
	int a, b, c, x;
	std::cin >> a >> x >> b >> c;
	int y = a * x * x + b * x + c;
	std::cout << y;
	return 0;
}