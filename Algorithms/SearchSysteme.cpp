//#include <iostream>
//#include <unordered_map>
//#include <cstdint>
//#include <string>
//#include <sstream>
//#include <unordered_set>
//#include <tuple>
//
//void document_processing(std::vector<std::unordered_map<char, std::vector<int>>>& symbols_documents,
//		std::vector<std::vector<uint64_t>>& prefix_hashes_documents,
//		std::vector<std::vector<uint64_t>>& coefs_hashes_documents, 
//		const std::string& document,const uint64_t& a, const uint64_t m) {
//	
//	uint64_t hash = 0;
//	uint64_t coef = 1;
//
//	std::vector<uint64_t> hashes = { hash };
//	std::vector<uint64_t> coefs = { coef };
//	std::unordered_map<char, std::vector<int>> index_symbols;
//
//	for (int i = 0; i < document.size(); i++) {
//		char symbol = document.at(i);
//		index_symbols[symbol].push_back(i);
//
//		hash *= a;
//		hash += symbol;
//		hash %= m;
//		hashes.push_back(hash);
//
//		coef *= a;
//		coef %= m;
//		coefs.push_back(coef);
//	}
//	symbols_documents.push_back(index_symbols);
//	prefix_hashes_documents.push_back(hashes);
//	coefs_hashes_documents.push_back(coefs);
//}
//
//uint64_t calculate_hash(const std::string& word, const uint64_t& a, const uint64_t& m) {
//	uint64_t hash = 0;
//	for (const char& symbol : word) {
//		hash *= a;
//		hash += symbol;
//		hash %= m;
//	}
//	return hash;
//}
//
//uint64_t calculate_prefix_hash(std::vector<uint64_t>& hashes, std::vector<uint64_t>& coefs, 
//	const int& index_start, const int& index_end, const uint64_t& m) {
//
//	int64_t start = hashes.at(index_start) * coefs.at(index_end - index_start) % m;
//	int64_t end = hashes.at(index_end);
//	int64_t hash = (m + end - start) % m;
//	if (hash < 0) hash = -hash;
//	std::cout << hash << std::endl;
//}
//
//int word_processing(std::unordered_map<char, std::vector<int>>& symbols_documents,
//	std::vector<uint64_t>& prefix_hashes_documents,
//	std::vector<uint64_t>& coefs_hashes_documents,
//	const std::string& request) {
//
//	int size_document = prefix_hashes_documents.size() - 1;
//
//	for (const int& index : symbols_documents.at(request.at(0))) {
//		if (index + request.size() < size_document) {
//
//		}
//	}
//}
//
//int request_processing(std::vector<std::unordered_map<char, std::vector<int>>>& symbols_documents,
//	std::vector<std::vector<uint64_t>>& prefix_hashes_documents,
//	std::vector<std::vector<uint64_t>>& coefs_hashes_documents,
//	const std::vector<std::string>& request, const uint64_t& a, const uint64_t& m) {
//	
//	int relevance = 0;
//	for (const std::string& word : request) {
//		uint64_t hash_word = calculate_hash(word, a, m);
//
//	}
//
//}
//
//int main() {
//	uint64_t a = 3571;
//	uint64_t m = 4294967296;
//	int number_documents;
//	std::cin >> number_documents;
//	std::vector<std::unordered_map<char, std::vector<int>>> symbols_documents;
//	std::vector<std::vector<uint64_t>> prefix_hashes_documents;
//	std::vector<std::vector<uint64_t>> coefs_hashes_documents;
//	for (int i = 0; i < number_documents; i++) {
//		std::string document;
//		std::getline(std::cin, document);
//		document_processing(symbols_documents, prefix_hashes_documents, coefs_hashes_documents, document, a, m);
//	}
//
//	int number_requests;
//	std::cin >> number_requests;
//	for (int i = 0; i < number_requests; i++) {
//		std::string request;
//		std::getline(std::cin, request);
//		std::istringstream stream_expression(request);
//		std::istream_iterator<std::string> input(stream_expression), eof;
//		std::vector<std::string> vec_request(input, eof);
//		request_processing(symbols_documents, prefix_hashes_documents, coefs_hashes_documents, vec_request);
//	}
//	return 0;
//}