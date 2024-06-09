//https://contest.yandex.ru/contest/25070/run-report/114517555/

// Принцип работы
// Принцип работы данного алгоритма основан на поиске циклов в графе при помощи алгоритма обхода графа в глубину.
// Можно заметить что если из города с номер N можно проложить черные и красные дороги в город M (так что N < M) и заменить красные дороги
// на черные только из города M в город N, то появиться цикл. Значит данная задача сводиться к поиску цикла в графе.
// 
// Доказательство корректности.
// Так как все железные дороги идут из города с меньшим номером в город с большим номером, то все вершины выстроенные в порядке
// 1 ... |V| топологически отсортированы. Если заменить красные дороги на ребра, которые ведут от вершины с большим номером к вершине
// с меньшим номером, то в случае появления циклов в графе следует что между двумя парами вершины есть путь с черными и красными дорогами.
// 
// Пример 1->3=>2->4=>1. В данном примере нехватает ребер между вершина 1 и 2, а также между вершинами 3 и 4. Если провести ту или иную дорогу
// то в нем будет возможность проложить разные типы дорог между вершинами. 
// 
//		1      2					1======2				1------2
//		=-   - =					=-   - =	Из 1=2=3	=-   - =    Из 1-2-4
//		=  -   =   добавляем 		=  -   =	Из 1-3		=  -   =	Из 1=4	
//		= - -  =   недостоющее		= - -  =				= - -  =
//		=-   - =	ребро 1=>2		=-   - =				=-   - =
//		4	   3					4	   3				4	   3
//		
//		Также если добавить ребро - между 3 и 4. Получаться пути 1-3-4 и 1=4
// 
// Произвольный цикл. Рассмотрим набор некоторых вершин r1, r2, r3 ... rn (такое что 1 < r1 < r2 < ... < rn < N).
// Так же вершины соединены следующим образом r1-r2-r3-...rn (т.е. вершина rl соединена с вершиной rl+1 черной дорогой). Количество вершин от 3 до N вершин.
// Если же остальные дороги красные (от вершин с меньшим номером к вершине с большем номером), то при замене их на черную дорогу от большей
// вершины к меньшей возникнет цикл. Например вершина r3=r1 возникнет цикл r1-r2-r3=r1, в произвольном случае r1-r2-...-rl=r1.
// 
// За счет чего происходить экономия памяти если использовать матрицу смежность? В этом случае необходимо хранить пустые ячейки
// За счет того что int поменял на bool?
// 
// Временная сложность
// Поиск в глубину запускается от каждой из вершин(если вершина посещена, то поиск не запускается).
// Поиск в глубину у связного графа занимает O(V).Следовательно общая временная сложность составляет O(|V|^2), где |V| -количество вершин
// 
// Пространственная сложность
// Для реализации данного алгоритма используется память для хранения посещенных вершин O(|V|), а также при каждом поиске в глубину
// цвета для каждой вершины O(|V|) и стэк городов O(|V|).
// Соответственно пространственная сложность составляет O(|V|), где |V| - количество вершин.



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

enum colors {White, Grey, Black};

bool check_city(const int& start_city, const std::vector<std::vector<bool>>& roads, std::vector<bool>& visited) {
	std::vector<char> colors(roads.size() + 1, White);
	std::stack<int> cities;
	cities.push(start_city);

	while (!cities.empty()) {
		int city = cities.top();
		cities.pop();

		if (colors.at(city) == White) {
			colors[city] = Grey;
			visited[city] = true;
			cities.push(city);

			for (int connected_city = 1; connected_city < roads.size(); connected_city++) {
				if (roads.at(city).at(connected_city)) {
					if (colors.at(connected_city) == White) {
						cities.push(connected_city);
					}
					else if (colors.at(connected_city) == Grey) {
						return false;
					}
				}
			}
		}
		else if (colors.at(city) == Grey) {
			colors[city] = Black;
		}
	}
	return true;
}

bool check_country(const std::vector<std::vector<bool>>& roads) {
	std::vector<bool> visited(roads.size(), false);
	for (int city = 1; city < roads.size(); city++) {
		if (!visited.at(city) && !check_city(city, roads, visited)) {
			return false;
		}
	}
	return true;
}

int railWays() {
	int number_cities;
	std::cin >> number_cities;
	std::vector<std::vector<bool>> roads(number_cities + 1, std::vector<bool>(number_cities+1, false));
	for (int from_city = 1; from_city <= number_cities - 1; from_city++) {
		for (int to_city = from_city + 1; to_city <= number_cities; to_city++) {
			char road;
			std::cin >> road;
			if (road == 'B') {
				roads[from_city][to_city] = true;
			}
			else if (road == 'R') {
				roads[to_city][from_city] = true;
			}
		}
	}
	if (check_country(roads)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}