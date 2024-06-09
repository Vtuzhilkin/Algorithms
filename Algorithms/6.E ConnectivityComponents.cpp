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
		table[to].push_back(from);
	}
	for (std::vector<int>& nodes : table) {
		std::sort(nodes.rbegin(), nodes.rend());
	}
	return table;
}

std::vector<int> dfs(const int& start_node, const std::vector<std::vector<int>>& table, std::vector<int>& colors, const int& color) {
	std::vector<int> component;
	std::stack<int> stack;
	stack.push(start_node);

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		if (colors.at(node) == -1) {
			colors[node] = 0;
			stack.push(node);
			component.push_back(node);

			for (const int& connected_node : table.at(node)) {
				if (colors.at(connected_node) == -1) {
					stack.push(connected_node);
				}
			}
		}
		else if (colors.at(node) == 0) {
			colors[node] = color;
		}
	}
	return component;
}

std::vector<std::vector<int>> connectivityComponents(const int& number_node, const std::vector<std::vector<int>>& table) {
	std::vector<std::vector<int>> components;
	std::vector<int> colors(table.size() + 1, -1);
	int color = 0;
	for (int node = 1; node <= number_node; node++) {
		if (colors.at(node) == -1) {
			components.push_back(dfs(node, table, colors, color++));
		}
	}
	return components;
}


int connectivityComponents() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::vector<int>> table = read(number_node, number_edge);
	std::vector<std::vector<int>> components = connectivityComponents(number_node, table);
	std::cout << components.size() << std::endl;
	for (std::vector<int> component : components) {
		std::sort(component.begin(), component.end());
		for (const int& node : component) {
			std::cout << node << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}