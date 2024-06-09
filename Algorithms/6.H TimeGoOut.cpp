#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

std::vector<std::vector<int>> read(const int& number_node,const int& number_edge) {
	std::vector<std::vector<int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to;
		std::cin >> from >> to;
		table[from].push_back(to);
	}
	for (std::vector<int>& nodes: table) {
		std::sort(nodes.rbegin(), nodes.rend());
	}
	return table;
}

std::vector<std::pair<int, int>> dfs(const std::vector<std::vector<int>>& table) {
	std::vector<char> colors(table.size() + 1, 'w');

	std::vector<std::pair<int, int>> times(table.size(), std::pair<int, int>(-1, -1));
	int time = 0;

	std::stack<int> stack;
	stack.push(1);

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		if (colors.at(node) == 'w') {
			colors[node] = 'g';
			stack.push(node);
			
			times[node-1].first = time++;

			for (const int& connected_node: table.at(node)) {
				if (colors.at(connected_node) == 'w') {
					stack.push(connected_node);
				}
			}
		}
		else if (colors.at(node) == 'g') {
			colors[node] = 'b';
			times[node-1].second = time++;
		}
	}
	return times;
}

int timeGoOut() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::vector<int>> table = read(number_node, number_edge);
	for (const std::pair<int, int> times : dfs(table)) {
		if (times != std::pair<int, int>(-1, -1)) {
			std::cout << times.first << " " << times.second << std::endl;
		}
	}

	return 0;
}