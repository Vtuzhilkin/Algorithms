//https://contest.yandex.ru/contest/24414/run-report/111918184/
//
// Принцип работы данного алгоритма основан на хэш-таблицы unordered_map из стандартной библиотеки stl. В хэш-таблицы хранятся слова, которые
// встречаются во всех документам, номер документа и количество слов в определенном документе
// 
// 
// -- Доказательство корректности -- 
// При считывании документа в хэш-таблицу добавляются все слова, входящий в данный документ, и записываются в хэш-таблицу.
// Ключом является само слово, а значением хэш-таблица, в которой ключом является номер документа, в котором находится данное слово, 
// а значением количество данных слов в документе.
// 
// После считывания запроса, считывается каждое слово из запроса и определяется в каком документе есть данные слова. Затем записывается
// в хэш-таблицу значения, где ключом является номер документа, а значением его релевантности. После прохождения по всем словам из запроса.
// определяется номер документа, у которого релевантность наибольшая и выводится в стандартный потом, затем его релевантность приравнивается 0 и
// снова определяется максимум.
// 
// -- Временная сложность --
// Считывание документа. При считывании документа происходит добавление или изменение значения в хэш-таблице. 
// Временная сложность добавление нового или изменение старого значения - О(L) (так как ключ строка). Поэтому временная сложность считывания 
// всех документов составляется - O(M*N*L), где M - количество документов, N - среднее количество слов в документе, L - средняя длина слова.
//  
// Считывание запроса. При считывании запроса происходит итерация по каждому слову запроса, затем итерация по всем документам, в которых
// есть данное слово и добавление или изменение значения в хэш таблицу.
// После прохождения по все словам, осуществляется поиск номера документа с максимальной релевантностью, данная операция выполняется 5 или менее раз.
// Поэтому общая временная сложность считывания запроса составляется - О(K*(V*R*L + 5*R) = О(K*V*R + 5*K*R) = О(K*V*R*L), 
// где K - количество запросов, V - среднее количество слов в запросе, 
// R - среднее количество документов в которых встречается каждое слово из запроса, L - средняя длина слова.
//
// Общая временная сложность работы данного алгоритма составляет: O(L*(M*N + K*V*R)), 
// где M - количество документов, N - среднее количество слов в документе, K - количество запросов, V - среднее количество слов в запросе, 
// R - среднее количество документов в которых встречается каждое слово из запроса
// 
// -- Пространственная сложность -- 
// Для работы данного алгоритма используются две хэш-таблицы.
// Одна для хранения всех слов из документов, номеров документов и количество слов в документе каждый элемент - О(L + 1 + 1) = О(L)
// , где L - средняя длина слова. Другая хэш-таблица для хранения номеров документов и их релевантность. Каждый элемент O(1).
// Поэтому общая пространственная сложность составляет O(M*N*L + R) = O(M*N*L), где M - количество документов, 
// N - среднее количество слов в документе, R - среднее количество документов в которых встречается каждое слово из запроса
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