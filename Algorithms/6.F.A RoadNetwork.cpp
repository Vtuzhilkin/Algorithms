// https://contest.yandex.ru/contest/25070/run-report/114407737/
// Принцип работы
// Принцип поиска максимального остновного дерева основан на алгоритме Прима.
// 1. Выбирается исходная вершина(в данной реализации - 1).
// 2. В приоритетную очередь добавляются все исходящие из этой вершины ребра.
// 3. Выбирается ребро с максимальным весом.
// 4. Добавляется к приоритетной очереди ребра исходящие из новой вершины.
// 5. Повторяются пункты 2 - 3 пока все вершины не будут посещены.
// 
// Доказательство корректности.
// Из описанного алгоритма следует, что на каждой итерации выбирается ребро с максимальным весом, соответственно полученное остовное
// дерево будет максимально возможного веса.
// 
// Временная сложность
// Рассмотрим полный граф.
// На каждой итерации происходить :
// 1. Добавление новых ребер в приоритетную очередь. Временная сложность добавление одного ребра(просеивание вниз)
// в приоритетную очередь O(log|V|), соответственно общая временная сложность добавление ребер на первой итерации - O(|V|*log|V|).
// 
// Рассмотрим первую итерацию, так как граф является полным, то первая вершина соединена с со всеми оставшимися (|V|-1 вершин).
// Т.е. количество ребер добавленных в приоритетную очередь на первой итерации будет равно V-1. Поэтому в среднем добавление очередного
// ребра занимает O(log(V)), а добавление всех исходящих занимает O(|V|*log|V|).
// 
// На следующей итерации необходимо будет добавить |V|-2 ребер. Так как извлекается одно ребро (наибольшее), а добавляется V-2 (затем V-3 и т. д.),
// то самое последее ребро будет добавлено за ~ O(log|E|). log|E| ~ log|V^2|, соответственно O(log|E|) ~ O(2*log|V|) ~ O(log|V|).
// Соответсвенно можно сказать что на каждой итерации в среднем время добавление всех новых ребер займет O(|V|*log|V|).
// 
// 2. Получение максимального ребра - O(1).
// 
// Количество итераций составляет V соответственно общая временная сложность равна O(|V|^2*log(|V|).
// Так как |E| = |V| *(|V| -1) / 2, значит |E| ~|V| ^ 2, то
// Общая временная сложность алгоритма прима составляет O(|E| *log(|V|), где |E| -количество ребер, |V| - количество вершин
// 
// Пространственная сложность.
// Для реализации алгоритма Прима используется дополнительная память, исходящие ребра хранятся в приоритетной очереди, а также используется
// память для отслеживания посещенных вершин.Значит общая пространственная сложность составляет O(E + V), так как E >> V, то
// сложность составляет O(E), где | E | -количество ребер графа, | V | -количество вершин.



#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>

std::vector<std::unordered_map<int, int>> read(const int& number_node, const int& number_edge) {
	std::vector<std::unordered_map<int, int>> table(number_node + 1);
	for (size_t i = 0; i < number_edge; i++) {
		int from, to, distance;
		std::cin >> from >> to >> distance;
		if (table.at(from).find(to) == table.at(from).end() || distance > table.at(from).at(to)) {
			table[from][to] = distance;
			table[to][from] = distance;
		}
	}
	return table;
}

void findMaxSpanningTree(const std::vector<std::unordered_map<int, int>>& table, const int& start_node = 1) {
	int result = 0;
	std::priority_queue<std::pair<int, int>> edges;

	std::vector<bool> visited(table.size(), false);
	visited[start_node] = true;
	int number_visited = 1;

	for (auto const& [node, distance] : table.at(start_node)) {
		edges.push(std::make_pair(distance, node));
	}

	while (number_visited != visited.size()-1 && !edges.empty()) {
		auto const [maxDistance, maxNode] = edges.top();
		if (!visited.at(maxNode)) {
			visited[maxNode] = true;
			result += maxDistance;
			number_visited++;
		}
		edges.pop();
		for (auto const& [node, distance] : table.at(maxNode)) {
			if (!visited.at(node)) {
				edges.push(std::make_pair(distance, node));
			}
		}
	}

	if (number_visited == visited.size() - 1) {
		std::cout << result;
	}
	else {
		std::cout << "Oops! I did it again";
	}
}

int roadNetwork() {
	int number_node, number_edge;
	std::cin >> number_node >> number_edge;
	std::vector<std::unordered_map<int, int>> table = read(number_node, number_edge);
	findMaxSpanningTree(table);
	return 0;
}