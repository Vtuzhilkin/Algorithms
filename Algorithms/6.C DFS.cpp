#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<std::vector<int>> read(const int& number_node,const int& number_edge) {
	std::vector<std::vector<int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to;
		std::cin >> from >> to;
		table[from].push_back(to);
		table[to].push_back(from);
	}
	for (std::vector<int>& nodes: table) {
		std::sort(nodes.rbegin(), nodes.rend());
	}
	return table;
}

void dfs(const std::vector<std::vector<int>>& table, const int& start_node) {
	std::vector<char> colors(table.size() + 1, 'w');
	std::stack<int> stack;
	std::vector<bool> is_stack(table.size() + 1, false);
	stack.push(start_node);
	is_stack[start_node] = true;

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		if (colors.at(node) == 'w') {
			colors[node] = 'g';
			stack.push(node);
			std::cout << node << " ";

			for (const int& connected_node: table.at(node)) {
				if (colors.at(connected_node) == 'w') {
					stack.push(connected_node);
					is_stack[connected_node] = true;
					//std::cout << connected_node + 1 << " ";
				}
			}
		}
		else if (colors.at(node) == 'g') {
			colors[node] = 'b';
		}
	}
}

int dfs_() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::vector<int>> table = read(number_node, number_edge);
	int start_node;
	std::cin >> start_node;
	dfs(table, start_node);

	return 0;
}