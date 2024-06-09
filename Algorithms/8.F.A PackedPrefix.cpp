// https://contest.yandex.ru/contest/26133/run-report/114938396/
// ������� ������
// ��� ����������� ������ �������� � ���� ������������ �����, ������� ����������� ���������� ������ �����, � ����� ����� �� ������ ��������.
// ����� ����������� ����� ������, ��������������� � ������������ ����� ������� ����� ������������� ������� � ����� ���������� ���������.
// 
// �������������� ������������
// ������ ���� - ���������� ������.
// ��� ���������� ������ ������� ������������ ������� �������� ������ � ��������������� �� �������� ������.
// ����� �������� ����������� ���������� �� ������������ ������, ��� ���������� �������� ������ ������ ���������� ����������
// ������� ������� � ��������� ���������� ����������� ������, ������ �������� ������ � ��������������� �� ��������.
// 
// ������ ���� ����������� ������ ��������
// ����� ���������� ������ ���� ������������ ����� ������������ �� ����� �������.
// ����� ����������� ����� ������, ��������������� � ������������ ����� ������� ����� ������������� ������ � ����� ������������ ��������
// 
// ��������� ���������
// ���������� ������ ���������� � ����
//		����� �������� �������� � �������� ������ - O(N), ��� N - ������ ������.
//		���������� ������ ��� ������ ����������� ������� - O(M * K), ��� M - ������� �������� ���� ������� ����� ��������, K - �������
//			�������� ����� ������������ ������.O(M * K) ~O(R), ��� R - ����� ������������� ������.
// ����� ������ �������� � ���� ����� - O(F), ��� F - ����� ���������� ������.
// ����� ��������� ��������� - O(n * L), ��� n - ���������� �����, L - ������� ����� ������������� ������.
// 
// ���������������� ���������
// ��� ���������� ������� ��������� ������������ �������������� ������ :
// ��� �������� ����� ������������ ��������, � ������ ������ ���� ��� ������ ���������� - O(L), ��� L - ����� ������������� ������.
// ��� �������� �������� ������ O(Nsk), ��� Nsk - ���������� ������
// ��� �������� �������� �������� ������ O(Nosk) = O(Nsk / 2), ��� Nosk - ���������� �������� ������.
// � ����� ������ �� ����� ��� ������ ����������� ������� O(Ng), ��� Ng - ������� ��������.
// O(L) >> O(Nsk) ~O(Nosk) >> O(Ng)
// ������� ����� ���������������� ��������� O(L), ��� L - ����� ������������� ������.
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