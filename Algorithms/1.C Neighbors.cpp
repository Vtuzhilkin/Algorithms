#include <iostream>
#include <vector>
#include <algorithm>

int Neighbors() {
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int number;
			std::cin >> number;
			matrix[i][j] = number;
		}
	}
	int index_i, index_j;
	std::cin >> index_i >> index_j;
	std::vector<int> neighbors;
	if (index_i - 1 >= 0) neighbors.push_back(matrix.at(index_i - 1).at(index_j));
	if (index_j - 1 >= 0) neighbors.push_back(matrix.at(index_i).at(index_j - 1));
	if (index_i + 1 < N) neighbors.push_back(matrix.at(index_i + 1).at(index_j));
	if (index_j + 1 < M) neighbors.push_back(matrix.at(index_i).at(index_j + 1));
	sort(neighbors.begin(), neighbors.end());
	for (std::vector<int>::iterator iter = neighbors.begin(); iter != neighbors.end(); iter++) {
		std::cout << *iter << " ";
	}
	return 0;
}