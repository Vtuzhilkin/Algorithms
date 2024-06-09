#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

std::vector<std::vector<int>> read(const int& number_node, const int& number_edge) {
	std::vector<std::vector<int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to;
		std::cin >> from >> to;
		table[from].push_back(to);
	}
	for (std::vector<int>& nodes : table) {
		std::sort(nodes.rbegin(), nodes.rend());
	}
	return table;
}

void dfs(const int& start_node, const std::vector<std::vector<int>>& table, std::vector<char>& colors, std::stack<int>& topological_sorting) {
	std::stack<int> stack;
	stack.push(start_node);

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		if (colors.at(node) == 'w') {
			colors[node] = 'g';
			stack.push(node);

			for (const int& connected_node : table.at(node)) {
				if (colors.at(connected_node) == 'w') {
					stack.push(connected_node);
				}
			}
		}
		else if (colors.at(node) == 'g') {
			topological_sorting.push(node);
			colors[node] = 'b';
		}
	}
}

std::stack<int> topologicalSorting(const int& number_node, const std::vector<std::vector<int>>& table) {
	std::stack<int> topological_sorting;
	std::vector<char> colors(table.size() + 1, 'w');
	for (int node = 1; node <= number_node; node++) {
		if (colors.at(node) == 'w') {
			dfs(node, table, colors, topological_sorting);
		}
	}
	return topological_sorting;
}


int topologicalSorting() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::vector<int>> table = read(number_node, number_edge);
	std::stack<int> topological_sorting = topologicalSorting(number_node, table);
	while(!topological_sorting.empty()) {
		std::cout << topological_sorting.top() << " ";
		topological_sorting.pop();
	}

	return 0;
}