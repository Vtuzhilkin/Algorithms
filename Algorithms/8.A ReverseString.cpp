#include <iostream>
#include <string>
#include <sstream>

void reverse(const std::string& st) {	
	int end = st.size();
	for (int start = st.size() - 1; start >= 0; start--) {
		if (st.at(start) == ' ') {
			std::cout << st.substr(start + 1, end - start - 1) << " ";
			end = start;
		}
	}
	std::cout << st.substr(0, end);
}

int reverseString() {
	std::string stroka;
	std::getline(std::cin, stroka);
	reverse(stroka);
	return 0;
}