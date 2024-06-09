#include <iostream>
#include <vector>

int adjacencyList() {
	int number_vertex, number_edge;
	std::cin >> number_vertex >> number_edge;
	std::vector<int> edges(number_vertex, 0);
	std::vector<std::vector<bool>> adjacency_list(number_vertex, std::vector<bool>(number_vertex, false));
	for (int i = 0; i < number_edge; i++) {
		int vertex_from, vertex_to;
		std::cin >> vertex_from >> vertex_to;
		vertex_from--;
		vertex_to--;
		if (!adjacency_list.at(vertex_from).at(vertex_to)) {
			edges[vertex_from]++;
		}
		adjacency_list[vertex_from][vertex_to] = true;
	}
	for (int i = 0; i < number_vertex; i++) {
		std::cout << edges.at(i) << " ";
		for (int j = 0; j < number_vertex; j++) {
			if (adjacency_list.at(i).at(j)) std::cout << j + 1 << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}