#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> prefix_function(const std::string& s) {
    int n = s.length();
    std::vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
        int k = pi[i - 1];
        while (k > 0 && s[k] != s[i]) {
            k = pi[k - 1];
        }
        if (s[k] == s[i]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& prefixes) {
    for (const int& prefix : prefixes) {
        os << prefix << " ";
    }
    return os;
}

int prefixFunction() {
	std::string stroka;
	std::cin >> stroka;
    std::cout << prefix_function(stroka);
	return 0;
}