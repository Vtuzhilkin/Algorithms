#include <iostream>
#include <vector>

int edgesToAdjacency() {
	int number_vertex, number_edge;
	std::cin >> number_vertex >> number_edge;
	std::vector<int> edges(number_vertex, 0);
	std::vector<std::vector<bool>> adjacency_list(number_vertex, std::vector<bool>(number_vertex, false));
	for (int i = 0; i < number_edge; i++) {
		int vertex_from, vertex_to;
		std::cin >> vertex_from >> vertex_to;
		vertex_from--;
		vertex_to--;
		adjacency_list[vertex_from][vertex_to] = true;
	}
	for (const std::vector<bool> vertexes : adjacency_list) {
		for (int i = 0; i < vertexes.size(); i++) {
			std::cout << vertexes.at(i) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}