#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <set>

std::pair<uint64_t, uint64_t> calculate_first_hash(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end, const int64_t& a, const int64_t& m) {
	uint64_t hash = 0;
	uint64_t coef = 1;
	for (; start != end; start++) {
		if (start + 1 != end) {
			coef *= a;
			coef %= m;
		}
		hash *= a;
		hash += *start;
		hash %= m;
	}
	return std::make_pair(hash, coef);
}

uint64_t calcute_next_hash(const int64_t& hash, int previous_point, int next_point, const int64_t& coef, const int64_t& a, const int64_t& m) {
	int64_t next_hash = ((hash - previous_point * coef % m) * a % m + next_point) % m;
	return next_hash;
}

bool equal(const std::vector<int>& first_team, const std::vector<int>& second_team, const int& length) {
	uint64_t a = 3571;
	uint64_t m = 4294967296;
	std::set<uint64_t> first_team_hashes;
	auto first_team_hash_coef = calculate_first_hash(first_team.cbegin(), first_team.cbegin() + length, a, m);
	uint64_t first_team_hash = first_team_hash_coef.first;
	uint64_t coef = first_team_hash_coef.second;
	first_team_hashes.insert(first_team_hash);
	for (int i = 1; i <= first_team.size() - length; i++) {
		first_team_hash = calcute_next_hash(first_team_hash, first_team.at(i - 1), first_team.at(i + length - 1), coef, a, m);
		first_team_hashes.insert(first_team_hash);
	}
	auto second_team_hash_coef = calculate_first_hash(second_team.cbegin(), second_team.cbegin() + length, a, m);
	uint64_t second_team_hash = second_team_hash_coef.first;
	if (first_team_hashes.find(second_team_hash) != first_team_hashes.end()) return true;
	for (int j = 1; j <= second_team.size() - length; j++) {
		second_team_hash = calcute_next_hash(second_team_hash, second_team.at(j - 1), second_team.at(j + length - 1), coef, a, m);
		if (first_team_hashes.find(second_team_hash) != first_team_hashes.end()) return true;
	}
	return false;
}

int find_submass(const std::vector<int>& first_team, const std::vector<int>& second_team) {
	int start = 0, end = first_team.size();
	int find_length = (first_team.at(0) == second_team.at(0));
	int length;
	while (start != end - 1) {
		length = start + (end - start) / 2;
		bool isTrue = equal(first_team, second_team, length);
		if (isTrue) {
			start = length;
			find_length = length;
		}
		else {
			end = length;
		}
	}
	return find_length;
}

int commonSubarray() {
	int number_games;
	std::cin >> number_games;
	std::vector<int> first_team(number_games);
	for (int i = 0; i < number_games; i++) {
		int points;
		std::cin >> points;
		first_team[i] = points;
	}
	std::cin >> number_games;
	std::vector<int> second_team(number_games);
	for (int i = 0; i < number_games; i++) {
		int points;
		std::cin >> points;
		second_team[i] = points;
	}
	if (first_team.size() > second_team.size()) {
		std::cout << find_submass(second_team, first_team);
	}
	else {
		std::cout << find_submass(first_team, second_team);

	}
	return 0;
}