#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

std::vector<std::unordered_map<int, int>> read(const int& number_node, const int& number_edge) {
	std::vector<std::unordered_map<int, int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to, distance;
		std::cin >> from >> to >> distance;
		if (table.at(from).find(to) == table.at(from).end() || distance < table.at(from).at(to)) {
			table[from][to] = distance;
			table[to][from] = distance;
		}
	}
	return table;
}

int findMin(const std::vector<int>& distances, const std::vector<bool>& visited) {
	int minNode = 0;
	for (int node = 1; node < distances.size(); node++) {
		if (!visited.at(node) && distances.at(node) != -1) {
			if (minNode == 0 || distances.at(node) < distances.at(minNode)) {
				minNode = node;
			}
		}
	}
	return minNode;
}

void relax(const int& node, const int& connected_node, const int& distance, std::vector<int>& distances, std::vector<int>& previous_node) {
	if (distances.at(connected_node) == -1 || distances.at(connected_node) > distances.at(node) + distance) {
		distances[connected_node] = distances.at(node) + distance;
		previous_node[connected_node] = node;
	}
}

std::vector<int> dijkstra(const int& start_node, const std::vector<std::unordered_map<int, int>>& table) {
	std::vector<int> distances(table.size(), -1);
	std::vector<int> previous_node(table.size(), -1);
	std::vector<bool> visited_nodes(table.size(), false);
	distances[start_node] = 0;
	visited_nodes[start_node] = true;
	for (auto const& [node, distance] : table.at(start_node)) {
		distances[node] = distance;
		previous_node[node] = start_node;
	}
	int minNode = 1;
	while (minNode) {

		minNode = findMin(distances, visited_nodes);
		visited_nodes[minNode] = true;

		for (auto const& [connected_node, distance] : table.at(minNode)) {
			relax(minNode, connected_node, distance, distances, previous_node);
		}

	}
	return distances;
}

int attrations() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::unordered_map<int, int>> table = read(number_node, number_edge);
	for (int node = 1; node <= number_node; node++) {
		std::vector<int> distances = dijkstra(node, table);
		for (int connected_node = 1; connected_node <= number_node; connected_node++) {
			std::cout << distances.at(connected_node) << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}