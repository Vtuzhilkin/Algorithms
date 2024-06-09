//https://contest.yandex.ru/contest/26133/run-report/114957945/
// ������� ������
// ������ ������������� ��������� �������� ���������� ������.�� ��������� ������ ��������� ���������� ������, ����� � �������
// ������ ����������� ����������� ��������� ��������� ����� �� ��������.
// 
// �������������� ������������.
// ����� ���������� ���������� �������, �������� ����������� ���������� �� �������
//		���� ������� � ����� �������� ���, �� ��������� ����� �������
//		����� ��������� ������� ������� ������������ �� ������� � ������ ��������.
// 
// ����� �������� ����������� ������, ����������� ����������� ��������� ����� �� �������� � ������� ������������� ����������������.
// ��������� ������ dp �������� ����� ������ + 1 � dp[0] ������������� �������� true.
// ����� ���������� �������� �� ���� ����� ������.
//		���� dp[i] = true, �� �������� ���������� �� ����������� ������ � ���� ��������� ������� �������� ������������,
//			�� dp[number_root] ������������� �������� true.
// 
// ���� ����� ������ �� ����� �������� ���������� �������� � dp ����� true, ������ ����� ����� ��������� �� ��������� ��������.
// 
// ��������� ���������
// ��������� �������� � ��� �����.
// 1. �������� ����������� ������.��� ����� ���������� �������� ������� ������� ���� ��������.
//		������� ��������� ��������� ������� ����� ���������� - O(M * l), ��� M - ���������� ��������, l - ������� ����� �������.
//		��� O(L), ��� L - ��������� ����� ���� ��������.
// 2. � ������ ������ ���� ��������� ������� ��� ��� �������� ������� ������.����� �� ������ �������� ���������� ����� ����������
//		� ���� ������.���������� �������� ����� ����� ������, � ������� ������ ������ ����� �������� ����� ������, �������
//		��������� ��������� 2�� ����� ����� O(N * N / 2) ~O(N ^ 2), ��� N - ������ ������.
// 
// ����� ��������� ��������� ���������� O(M * l + N ^ 2).���� N >> l ��� N >> M, �� ����� ������ � O(N ^ 2).
// 
// ���������������� ���������.
// � ������ ������ ���������� ����� ������� �������(���� � ��� ��� �������������� ���������), ������� ����� ��������� ���������
// ���������� O(L), ��� L - ��������� ����� ���� ��������.
// 
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

struct Node {
	std::unordered_map<char, std::unique_ptr<Node>> nodes;
	bool terminalNode = false;
};

class PrefixTree {
private:
	Node root;
public:
	void addWord(const std::string& word) {
		Node* current_root = &root;
		for (const char& symbol : word) {
			if (current_root->nodes.find(symbol) == current_root->nodes.end()) {
				current_root->nodes[symbol] = std::make_unique<Node>();
			}
			current_root = current_root->nodes[symbol].get();
		}
		current_root->terminalNode = true;
	}
	bool searchWord(const std::string& word) {
		Node* current_root = &root;
		std::vector<int> dp(word.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i < word.size(); i++) {
			if (dp.at(i)) {
				int index = i;
				while (index < word.size() && current_root->nodes.find(word.at(index)) != current_root->nodes.end()) {
					current_root = current_root->nodes[word.at(index)].get();
					if (current_root->terminalNode) {
						dp[index + 1] = true;
					}
					index++;
				}
				current_root = &root;
			}
		}
		return dp.back();
	}
};

int chatSheet() {
	std::string text;
	std::cin >> text;
	int number_patterns;
	std::cin >> number_patterns;
	PrefixTree prefixTree;
	for (int i = 0; i < number_patterns; i++) {
		std::string new_pattern;
		std::cin >> new_pattern;
		prefixTree.addWord(new_pattern);
	}
	if (prefixTree.searchWord(text)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}