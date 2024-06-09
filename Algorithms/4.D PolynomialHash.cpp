#include <iostream>
#include <stdint.h>
#include <map>

uint64_t calculate_hash(const std::string& sequance, uint64_t a, uint64_t m) {
    uint64_t hash = 0;
    for (const char& symbol : sequance) {
        hash *= a;
        hash += symbol;
        hash %= m;
    }
    return hash % m;
}
std::string generateRandomString() {
    std::string result = "";
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 15; ++i) {
        result += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return result;
}
int polynomialHash() {
    std::string sequance;
    uint64_t a, m;
    //   std::cin >> a >> m;
    a = 1000;
    m = 123987123;
    std::map <int, std::string> hashes;
    while (1) {
        // std::cin >> sequance;
        sequance = generateRandomString();
        int hash = calculate_hash(sequance, a, m);
        if (hashes.find(hash) == hashes.end()) {
            hashes[hash] = sequance;
        }
        else {
            std::cout << hash << " " << sequance << std::endl;
            std::cout << hash << " " << hashes[hash] << std::endl;
        }
    }
    return 0;
}