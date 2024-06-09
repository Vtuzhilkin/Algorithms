#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <functional>

int64_t calc_key(std::string& st) {
	std::hash<std::string> hasher;
	std::sort(st.begin(), st.end());
	return hasher(st);
}

int anagramGrouping() {
	std::unordered_map<int64_t, int> keys;
	std::vector<std::vector<int>> indexes;
	int key = -1;
	int number_strings;
	std::cin >> number_strings;
	for (int i = 0; i < number_strings; i++) {
		std::string st;
		std::cin >> st;
		int64_t table_key = calc_key(st);
		if (keys.find(table_key) == keys.end()) {
			key++;
			keys[table_key] = key;
		}
		if (indexes.size() > keys[table_key]) {
			indexes[keys[table_key]].push_back(i);
		}
		else {
			indexes.push_back({ i });
		}
	}
	for (const std::vector<int> part_indexes : indexes) {
		for (const int& index : part_indexes) {
			std::cout << index << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}