// https://contest.yandex.ru/contest/25070/run-report/114407737/
// ������� ������
// ������� ������ ������������� ���������� ������ ������� �� ��������� �����.
// 1. ���������� �������� �������(� ������ ���������� - 1).
// 2. � ������������ ������� ����������� ��� ��������� �� ���� ������� �����.
// 3. ���������� ����� � ������������ �����.
// 4. ����������� � ������������ ������� ����� ��������� �� ����� �������.
// 5. ����������� ������ 2 - 3 ���� ��� ������� �� ����� ��������.
// 
// �������������� ������������.
// �� ���������� ��������� �������, ��� �� ������ �������� ���������� ����� � ������������ �����, �������������� ���������� ��������
// ������ ����� ����������� ���������� ����.
// 
// ��������� ���������
// ���������� ������ ����.
// �� ������ �������� ����������� :
// 1. ���������� ����� ����� � ������������ �������. ��������� ��������� ���������� ������ �����(����������� ����)
// � ������������ ������� O(log|V|), �������������� ����� ��������� ��������� ���������� ����� �� ������ �������� - O(|V|*log|V|).
// 
// ���������� ������ ��������, ��� ��� ���� �������� ������, �� ������ ������� ��������� � �� ����� ����������� (|V|-1 ������).
// �.�. ���������� ����� ����������� � ������������ ������� �� ������ �������� ����� ����� V-1. ������� � ������� ���������� ����������
// ����� �������� O(log(V)), � ���������� ���� ��������� �������� O(|V|*log|V|).
// 
// �� ��������� �������� ���������� ����� �������� |V|-2 �����. ��� ��� ����������� ���� ����� (����������), � ����������� V-2 (����� V-3 � �. �.),
// �� ����� �������� ����� ����� ��������� �� ~ O(log|E|). log|E| ~ log|V^2|, �������������� O(log|E|) ~ O(2*log|V|) ~ O(log|V|).
// ������������� ����� ������� ��� �� ������ �������� � ������� ����� ���������� ���� ����� ����� ������ O(|V|*log|V|).
// 
// 2. ��������� ������������� ����� - O(1).
// 
// ���������� �������� ���������� V �������������� ����� ��������� ��������� ����� O(|V|^2*log(|V|).
// ��� ��� |E| = |V| *(|V| -1) / 2, ������ |E| ~|V| ^ 2, ��
// ����� ��������� ��������� ��������� ����� ���������� O(|E| *log(|V|), ��� |E| -���������� �����, |V| - ���������� ������
// 
// ���������������� ���������.
// ��� ���������� ��������� ����� ������������ �������������� ������, ��������� ����� �������� � ������������ �������, � ����� ������������
// ������ ��� ������������ ���������� ������.������ ����� ���������������� ��������� ���������� O(E + V), ��� ��� E >> V, ��
// ��������� ���������� O(E), ��� | E | -���������� ����� �����, | V | -���������� ������.



#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>

std::vector<std::unordered_map<int, int>> read(const int& number_node, const int& number_edge) {
	std::vector<std::unordered_map<int, int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to, distance;
		std::cin >> from >> to >> distance;
		if (table.at(from).find(to) == table.at(from).end() || distance > table.at(from).at(to)) {
			table[from][to] = distance;
			table[to][from] = distance;
		}
	}
	return table;
}

void findMaxSpanningTree(const std::vector<std::unordered_map<int, int>>& table, const int& start_node = 1) {
	int result = 0;
	std::priority_queue<std::pair<int, int>> edges;

	std::vector<bool> visited(table.size(), false);
	visited[start_node] = true;
	int number_visited = 1;

	for (auto const& [node, distance] : table.at(start_node)) {
		edges.push(std::make_pair(distance, node));
	}

	while (number_visited != visited.size()-1 && !edges.empty()) {
		auto const [maxDistance, maxNode] = edges.top();
		if (!visited.at(maxNode)) {
			visited[maxNode] = true;
			result += maxDistance;
			number_visited++;
		}
		edges.pop();
		for (auto const& [node, distance] : table.at(maxNode)) {
			if (!visited.at(node)) {
				edges.push(std::make_pair(distance, node));
			}
		}
	}

	if (number_visited == visited.size() - 1) {
		std::cout << result;
	}
	else {
		std::cout << "Oops! I did it again";
	}
}

int roadNetwork() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::unordered_map<int, int>> table = read(number_node, number_edge);
	findMaxSpanningTree(table);
	return 0;
}