// https://contest.yandex.ru/contest/26133/run-report/114938396/
// Принцип работы
// Для определения общего префикса у двух запакованных строк, сначала выполняется распаковка данных строк, а затем поиск их общего префикса.
// Затем считывается новая строка, распаковывается и определяется общий префикс между распакованной строкой и ранее полученный префиксом.
// 
// Доказательство корректности
// Первый этап - распаковка строки.
// Для распаковки строки сначала определяются индексы открытых скобок и соответствующих им закрытых скобок.
// Затем алгоритм посимвольно проходится по запакованной строке, при достижении открытой первой скобки вызывается рекурсивно
// функция которой в параметры передается изначальная строка, индекс открытой скобки и соответствующей ей закрытой.
// 
// Второй этап определение общего префикса
// После распаковки первых двух запакованных строк определяется их общий префикс.
// Затем считывается новая строка, распаковывается и определяется общий префикс новой распакованной строки и ранее вычисленного префикса
// 
// Временная сложность
// Распаковка строки включается в себя
//		поиск индексов открытых и закрытых скобок - O(N), где N - размер строки.
//		распаковка строки при помощи рекурсивной функции - O(M * K), где M - среднее значение всех номеров перед скобками, K - среднее
//			значение длины запакованной строки.O(M * K) ~O(R), где R - длина распакованной строки.
// Поиск общего префикса у двух строк - O(F), где F - длина наименьшей строки.
// Общая временная сложность - O(n * L), где n - количество строк, L - средняя длина распокованной строки.
// 
// Пространственная сложность
// Для реализации данного алгоритма используется дополнительная память :
// для хранения ранее вычисленного префикса, в худшем случае если все строки одинаковые - O(L), где L - длина распакованной строки.
// для хранения индексов скобок O(Nsk), где Nsk - количество скобок
// для хранения индексов открытых скобок O(Nosk) = O(Nsk / 2), где Nosk - количество открытых скобок.
// а также память на стэки при вызове рекурсивной функции O(Ng), где Ng - глубина рекурсии.
// O(L) >> O(Nsk) ~O(Nosk) >> O(Ng)
// Поэтому общая пространственная сложность O(L), где L - длина распакованной строки.
// 
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <stack>

std::string unpacked_recursion(const std::string& packed_string, const std::unordered_map<int, int>& brackets, int start, int end) {
	std::string result;

	for (int i = start; i < end; i++) {
		if (packed_string.at(i) == '[') {
			int number_repeat = result.back() - '0';
			result.pop_back();
			std::string part_result = unpacked_recursion(packed_string, brackets, i + 1, brackets.at(i));
			while (number_repeat--) {
				result += part_result;
			}
			i = brackets.at(i);
		}
		else {
			result += packed_string.at(i);
		}
	}
	return result;
}

std::string unpacked(const std::string& packed_string) {
	std::unordered_map<int, int> brackets;
	std::stack<int> open_brackets;
	for (int i = 0; i < packed_string.size(); i++) {
		if (packed_string.at(i) == '[') {
			open_brackets.push(i);
		}
		else if (packed_string.at(i) == ']') {
			brackets[open_brackets.top()] = i;
			open_brackets.pop();
		}
	}
	return unpacked_recursion(packed_string, brackets, 0, packed_string.size());
}


std::string common_prefix(const std::string& first_string, const std::string& second_string) {
	std::string prefix;
	int end_prefix = 0;
	for (; end_prefix < std::min(first_string.size(), second_string.size()); end_prefix++) {
		if (first_string.at(end_prefix) != second_string.at(end_prefix)) {
			break;
		}
	}
	return first_string.substr(0, end_prefix);
}

int packedPrefix() {
	int number_strings;
	std::cin >> number_strings;
	std::string prefix;
	if (number_strings == 1) {
		std::cin >> prefix;
		prefix = unpacked(prefix);
	}
	else if (number_strings >= 2) {
		std::string first_string, second_string;
		std::cin >> first_string >> second_string;
		prefix = common_prefix(unpacked(first_string), unpacked(second_string));
		for (int i = 2; i < number_strings; i++) {
			std::cin >> second_string;
			prefix = common_prefix(prefix, unpacked(second_string));
		}
	}
	std::cout << prefix;
	
	return 0;
}