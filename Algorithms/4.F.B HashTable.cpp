// https://contest.yandex.ru/contest/24414/run-report/111913692/
// 
// -- ������� ������ --
// ������� ������ ������������� ���-������� ������� �� ����������� vector � list �� ����������� ���������� stl
// ������ ������� ������� ��������� � ���� ���� �������� int. ��� ����������, �������� ��� ��������� �������� ������� ��������������
// ����� ������ � ������� �������� ��� ����� ��������� ������ �������, ����� ����������� ��� ����������� ������� � ���� ����.
// 
// -- �������������� ������������ --
// ��� ���������� �������� ������� ������������� ����� ������, � ������� ����� ��������� ����������� ������� (������� calculate_number_cell)
// ����� ���������� �� vector'a ������������ list, �� �������� ���������� ������ � ������� �������� � ������ ������ ������������. ����
// ����� ������� ������, �� ��������� ��������� ���� ���, �� �������� ����� �������.
// 
// ��������� � �������� �������� ���������� ���������� ����������, ������ ���� 3������� � �������/��������� ������ �� ������ ��������� None
// 
// -- ��������� ��������� --
// ��� ���������� �������� ����������: 
// ��������� ����� ������ - �(1), 
// �������� ������ �� list � ������� �������� - �(N), ��� N - ���������� ��������� � ������.
// �������� �������� ��� �������� � ����� ������ - �(1)
// 
// ��� �������� �������� ����������:
// ��������� ����� ������ - �(1), 
// �������� ������ �� list � ������� �������� - �(N), ��� N - ���������� ��������� � ������.
// ������� ������� �� list ��� ������� None - �(1)
// 
// ��� ��������� �������� ����������:
// ��������� ����� ������ - �(1), 
// �������� ������ �� list � ������� �������� - �(N), ��� N - ���������� ��������� � ������.
// ������� ������� ��� ������� None - �(1)
// 
// � ����� ����� ��������� ��������� ������ ���-������� ���������� - �(M*N), ��� M - ���������� ��������, N - ������� ���������� ��������� � list'��
// 
// -- ���������������� ��������� --
// 
// ��� ������ ������������� ���-������� ���������� �������:
// max_size - ������������ ���������� �����
// vector<list<pair<int,int>>> - ������ ������� ��� � ������� �������� ����� � �������� 
// ����� ���������������� ��������� ���������� �(max_size*N), ��� N - ������� ���������� ��� � �������
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

class HashTable {
public:
	HashTable(int max_size_) : max_size(max_size_), table(std::vector<std::list<std::pair<const int, int>>>(max_size_)) {};

	void put(const int& key, const int& value) {
		int number_cell = calculete_number_cell(key);
		std::list<std::pair<const int, int>>::iterator iter = find_if(table[number_cell].begin(), table[number_cell].end(), 
			[&](const std::pair<const int, int>& find_key) { return find_key.first == key;});
		if (iter != table[number_cell].end()) {
			iter->second = value;
		}
		else {
			table[number_cell].push_back({ key, value });
		}
	}
	void get(const int& key) {
		int number_cell = calculete_number_cell(key);
		for (const std::pair<int, int>& key_value : table.at(number_cell)) {
			if (key_value.first == key) {
				std::cout << key_value.second << std::endl;
				return;
			}
		}
		std::cout << "None" << std::endl;
	}

	void delete_(const int& key) {
		int number_cell = calculete_number_cell(key);
		std::list<std::pair<const int, int>>::iterator delete_cell = table[number_cell].begin();
		for (; delete_cell != table[number_cell].end(); delete_cell++) {
			if (delete_cell->first == key) {
				break;
			}
		}
		if (delete_cell != table[number_cell].end()) {
			std::cout << delete_cell->second << std::endl;
			table[number_cell].erase(delete_cell);
		}
		else {
			std::cout << "None" << std::endl;
		}
	}

private:
	std::vector<std::list<std::pair<const int, int>>> table;
	int max_size;

	int calculete_number_cell(const int& key) {
		int number_cells = key;
		if (key < 0) number_cells = -key;
		number_cells %= max_size;
		return number_cells;
	}
	
};


int hashTable() {
	HashTable hashTable(9973);
	int number_commands;
	std::cin >> number_commands;
	std::string command;
	int key, value;
	for (int i = 0; i < number_commands; i++) {
		std::cin >> command >> key;
		if (command == "put") {
			std::cin >> value;
			hashTable.put(key, value);
		}
		else if (command == "get") {
			hashTable.get(key);
		}
		else if (command == "delete") {
			hashTable.delete_(key);	
		}
	}

	return 0;
}