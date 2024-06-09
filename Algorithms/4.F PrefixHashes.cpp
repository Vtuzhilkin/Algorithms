#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdint>
#include <cmath>


std::pair<std::vector<int64_t>, std::vector<int64_t>> calculate_hash(const std::string& sequance, uint64_t a, const uint64_t& m) {
	std::vector<int64_t> hashes;
	std::vector<int64_t> coefs;
	hashes.push_back(0);
	coefs.push_back(1);
    int64_t hash = 0;
    for (const char& symbol : sequance) {
		coefs.push_back(coefs.back() * a % m);
        hash *= a;
        hash += symbol;
        hash %= m;
		hashes.push_back(hash);
    }
    return std::make_pair(hashes,coefs);
}


int prefixHashes() {
	int a, m, t;
	std::string sequance;
	std::cin >> a >> m >> sequance >> t;
	auto pairs = calculate_hash(sequance, a, m);
	std::vector<int64_t> hashes = pairs.first;
	std::vector<int64_t> coefs = pairs.second;
	for (int i = 0; i < t; i++) {
		int index_start, index_end;
		std::cin >> index_start >> index_end;
		index_start--;
		int64_t start = hashes.at(index_start) * coefs.at(index_end - index_start) % m;
		int64_t end = hashes.at(index_end);
		int64_t hash = (m + end - start) % m;
		if (hash < 0) hash = -hash;
		std::cout << hash << std::endl;
	}
	
	return 0;
}