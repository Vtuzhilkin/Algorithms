#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> read(const int& number_node, const int& number_edge) {
	std::vector<std::vector<int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to;
		std::cin >> from >> to;
		table[from].push_back(to);
		table[to].push_back(from);
	}
	for (std::vector<int>& nodes: table) {
		std::sort(nodes.begin(), nodes.end());
	}
	return table;
}

int bfs(const int& start_node, const std::vector<std::vector<int>>& table) {
	int max_level = 0;
	std::vector<char> colors(table.size(), 'w');
	std::vector<int> level(table.size(), 0);
	std::queue<int> queue;
	queue.push(start_node);
	
	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();
		colors[node] = 'b';
		for (const int& connected_node : table.at(node)) {
			int distance = level.at(node) - level.at(connected_node);
			if (colors.at(connected_node) == 'w') {
				queue.push(connected_node);
				colors[connected_node] = 'g';
				level[connected_node] = level[node] + 1;
				max_level = std::max(max_level, level.at(connected_node));
			}
		}
	}
	return max_level;
}

int maxDistace() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::vector<int>> table = read(number_node, number_edge);
	int start_node;
	std::cin >> start_node;
	std::cout << bfs(start_node, table);
	return 0;
}