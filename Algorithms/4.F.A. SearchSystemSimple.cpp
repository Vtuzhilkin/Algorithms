//https://contest.yandex.ru/contest/24414/run-report/111918184/
//
// ������� ������ ������� ��������� ������� �� ���-������� unordered_map �� ����������� ���������� stl. � ���-������� �������� �����, �������
// ����������� �� ���� ����������, ����� ��������� � ���������� ���� � ������������ ���������
// 
// 
// -- �������������� ������������ -- 
// ��� ���������� ��������� � ���-������� ����������� ��� �����, �������� � ������ ��������, � ������������ � ���-�������.
// ������ �������� ���� �����, � ��������� ���-�������, � ������� ������ �������� ����� ���������, � ������� ��������� ������ �����, 
// � ��������� ���������� ������ ���� � ���������.
// 
// ����� ���������� �������, ����������� ������ ����� �� ������� � ������������ � ����� ��������� ���� ������ �����. ����� ������������
// � ���-������� ��������, ��� ������ �������� ����� ���������, � ��������� ��� �������������. ����� ����������� �� ���� ������ �� �������.
// ������������ ����� ���������, � �������� ������������� ���������� � ��������� � ����������� �����, ����� ��� ������������� �������������� 0 �
// ����� ������������ ��������.
// 
// -- ��������� ��������� --
// ���������� ���������. ��� ���������� ��������� ���������� ���������� ��� ��������� �������� � ���-�������. 
// ��������� ��������� ���������� ������ ��� ��������� ������� �������� - �(L) (��� ��� ���� ������). ������� ��������� ��������� ���������� 
// ���� ���������� ������������ - O(M*N*L), ��� M - ���������� ����������, N - ������� ���������� ���� � ���������, L - ������� ����� �����.
//  
// ���������� �������. ��� ���������� ������� ���������� �������� �� ������� ����� �������, ����� �������� �� ���� ����������, � �������
// ���� ������ ����� � ���������� ��� ��������� �������� � ��� �������.
// ����� ����������� �� ��� ������, �������������� ����� ������ ��������� � ������������ ��������������, ������ �������� ����������� 5 ��� ����� ���.
// ������� ����� ��������� ��������� ���������� ������� ������������ - �(K*(V*R*L + 5*R) = �(K*V*R + 5*K*R) = �(K*V*R*L), 
// ��� K - ���������� ��������, V - ������� ���������� ���� � �������, 
// R - ������� ���������� ���������� � ������� ����������� ������ ����� �� �������, L - ������� ����� �����.
//
// ����� ��������� ��������� ������ ������� ��������� ����������: O(L*(M*N + K*V*R)), 
// ��� M - ���������� ����������, N - ������� ���������� ���� � ���������, K - ���������� ��������, V - ������� ���������� ���� � �������, 
// R - ������� ���������� ���������� � ������� ����������� ������ ����� �� �������
// 
// -- ���������������� ��������� -- 
// ��� ������ ������� ��������� ������������ ��� ���-�������.
// ���� ��� �������� ���� ���� �� ����������, ������� ���������� � ���������� ���� � ��������� ������ ������� - �(L + 1 + 1) = �(L)
// , ��� L - ������� ����� �����. ������ ���-������� ��� �������� ������� ���������� � �� �������������. ������ ������� O(1).
// ������� ����� ���������������� ��������� ���������� O(M*N*L + R) = O(M*N*L), ��� M - ���������� ����������, 
// N - ������� ���������� ���� � ���������, R - ������� ���������� ���������� � ������� ����������� ������ ����� �� �������
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

void processing_document(std::unordered_map<std::string, std::unordered_map<int, int>>& string_document, 
		const std::vector<std::string>& document, const int& number_document) {

	for (const std::string& word : document) {
		string_document[word][number_document]++;
	}
}

std::tuple<int, int> make_key(const std::pair<const int, int>& element) {
	return std::tuple<int, int>(element.second, -element.first);
}

bool compare(const std::pair<const int, int>& first, const std::pair<const int, int>& second) {
	return make_key(first) < make_key(second);
}

void calculete_relevance(const std::unordered_map<std::string, std::unordered_map <int, int>>& documents, const std::unordered_set<std::string>& request) {
	
	std::unordered_map<int, int> number_document_relevance;

	for (const std::string& word : request) {
		if (documents.find(word) != documents.end()) {
			for (const std::pair<const int, int>& document : documents.at(word)) {
				const int& number_document = document.first;
				const int& frequence_word = document.second;
				if (number_document_relevance.find(number_document) != number_document_relevance.end()) {
					number_document_relevance[number_document] += frequence_word;
				}
				else {
					number_document_relevance[number_document] = frequence_word;
				}
			}
		}
	}

	for (int i = 0; i < 5 && number_document_relevance.size() != 0; i++) {
		auto iter_max = std::max_element(number_document_relevance.begin(), number_document_relevance.end(), compare);
		if (iter_max->second != 0) {
			std::cout << iter_max->first + 1 << " ";
			number_document_relevance.erase(iter_max);
		}
		else {
			break;
		}
	}
	std::cout << std::endl;
}

int searchSystemSimple() {
	int number_documents;
	std::cin >> number_documents;
	std::unordered_map<std::string, std::unordered_map<int, int>> strings_documents;

	std::string document;
	std::getline(std::cin, document);

	for (int i = 0; i < number_documents; i++) {
		std::getline(std::cin, document);

		std::istringstream stream_expression(document);
		std::istream_iterator<std::string> input(stream_expression), eof;
		std::vector<std::string> vec_document(input, eof);

		processing_document(strings_documents, vec_document, i);
	}

	int number_request;
	std::cin >> number_request;

	std::string request;
	std::getline(std::cin, request);

	for (int i = 0; i < number_request; i++) {
		std::getline(std::cin, request);

		std::istringstream stream_expression(request);
		std::istream_iterator<std::string> input(stream_expression), eof;
		std::unordered_set<std::string> vec_request(input, eof);

		calculete_relevance(strings_documents, vec_request);
	}
	return 0;
}