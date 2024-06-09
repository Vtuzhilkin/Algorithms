//https://contest.yandex.ru/contest/25070/run-report/114517555/

// ������� ������
// ������� ������ ������� ��������� ������� �� ������ ������ � ����� ��� ������ ��������� ������ ����� � �������.
// ����� �������� ��� ���� �� ������ � ����� N ����� ��������� ������ � ������� ������ � ����� M (��� ��� N < M) � �������� ������� ������
// �� ������ ������ �� ������ M � ����� N, �� ��������� ����. ������ ������ ������ ��������� � ������ ����� � �����.
// 
// �������������� ������������.
// ��� ��� ��� �������� ������ ���� �� ������ � ������� ������� � ����� � ������� �������, �� ��� ������� ����������� � �������
// 1 ... |V| ������������� �������������. ���� �������� ������� ������ �� �����, ������� ����� �� ������� � ������� ������� � �������
// � ������� �������, �� � ������ ��������� ������ � ����� ������� ��� ����� ����� ������ ������� ���� ���� � ������� � �������� ��������.
// 
// ������ 1->3=>2->4=>1. � ������ ������� ��������� ����� ����� ������� 1 � 2, � ����� ����� ��������� 3 � 4. ���� �������� �� ��� ���� ������
// �� � ��� ����� ����������� ��������� ������ ���� ����� ����� ���������. 
// 
//		1      2					1======2				1------2
//		=-   - =					=-   - =	�� 1=2=3	=-   - =    �� 1-2-4
//		=  -   =   ��������� 		=  -   =	�� 1-3		=  -   =	�� 1=4	
//		= - -  =   �����������		= - -  =				= - -  =
//		=-   - =	����� 1=>2		=-   - =				=-   - =
//		4	   3					4	   3				4	   3
//		
//		����� ���� �������� ����� - ����� 3 � 4. ���������� ���� 1-3-4 � 1=4
// 
// ������������ ����. ���������� ����� ��������� ������ r1, r2, r3 ... rn (����� ��� 1 < r1 < r2 < ... < rn < N).
// ��� �� ������� ��������� ��������� ������� r1-r2-r3-...rn (�.�. ������� rl ��������� � �������� rl+1 ������ �������). ���������� ������ �� 3 �� N ������.
// ���� �� ��������� ������ ������� (�� ������ � ������� ������� � ������� � ������� �������), �� ��� ������ �� �� ������ ������ �� �������
// ������� � ������� ��������� ����. �������� ������� r3=r1 ��������� ���� r1-r2-r3=r1, � ������������ ������ r1-r2-...-rl=r1.
// 
// �� ���� ���� ����������� �������� ������ ���� ������������ ������� ���������? � ���� ������ ���������� ������� ������ ������
// �� ���� ���� ��� int ������� �� bool?
// 
// ��������� ���������
// ����� � ������� ����������� �� ������ �� ������(���� ������� ��������, �� ����� �� �����������).
// ����� � ������� � �������� ����� �������� O(V).������������� ����� ��������� ��������� ���������� O(|V|^2), ��� |V| -���������� ������
// 
// ���������������� ���������
// ��� ���������� ������� ��������� ������������ ������ ��� �������� ���������� ������ O(|V|), � ����� ��� ������ ������ � �������
// ����� ��� ������ ������� O(|V|) � ���� ������� O(|V|).
// �������������� ���������������� ��������� ���������� O(|V|), ��� |V| - ���������� ������.



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