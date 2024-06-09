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

void bfs(const int& start_node, const std::vector<std::vector<int>>& table) {
	std::vector<char> colors(table.size(), 'w');
	std::queue<int> queue;
	queue.push(start_node);
	
	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();
		colors[node] = 'b';
		std::cout << node << " ";
		for (const int& connected_node : table.at(node)) {
			if (colors.at(connected_node) == 'w') {
				queue.push(connected_node);
				colors[connected_node] = 'g';
			}
		}
	}
}

int bfs_() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::vector<int>> table = read(number_node, number_edge);
	int start_node;
	std::cin >> start_node;
	bfs(start_node, table);
	return 0;
}