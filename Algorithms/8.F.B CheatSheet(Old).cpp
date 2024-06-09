// https://contest.yandex.ru/contest/26133/run-report/114846244/
// Принцип работы
// Работа данной программы реализована с помощью поиска шаблона в тексте при помощи префикс функции и обхода в глубину графа.
// 
// Доказательство корректности
// Сначала с помощью префикс функции находится все позиции, где в тексте встречается искомый шаблон.
// Затем программа итеративно проходится по всем найденным индексами и создаются ребра между найденным индексом и индексом равным
// сумме найденного индекса и длины шаблона.
// Например: текст - abcdef, шаблон def, найденный индекс 3, значит создастся ребро между вершиной 3 и 6 (3 + len(def)).
// После считывания обработки всех шаблонов, запускается поиск в глубину, если при обходе некоторая вершина связана с вершиной под номером
// равной длины исходного текста(шпаргалки), то с помощью введенных шаблонов можно составить исходных текст(шпаргалку).
// 
// Временная сложность
// Временная сложность поиска индексов вхождения шаблона в текст(шпаргалку) составляется - O(Ls + Lt), где Ls - длина шаблона, Lt - длина текста.
// Временная сложность создания графа(ребер графа) составляет O(t) - где t - количество индексов вхождения одного шаблона.
// Временная сложность обхода графа в глубину в худшем случае составляет - O(| V | ^ 2), где V - количество всех вершин.
// Общая временная сложность O(N * (Lss + Lt) + N * ts) + O(| V | ^ 2), где N - количество шаблонов, Lss - средняя длина шаблона, ts - среднее
// количество вхождения шаблона в текст, | V | -количество полученных вершин графа.
// В худшем случае(если граф заполнен на половину) количество ребер составляет | V | равно Lt / 2
// Поэтому общая временная сложность составляет O(N * (Lss + Lt)) + O(Lt ^ 2) ~O(N * Lt) + O(Lt ^ 2).
// 
// Пространственная сложность
// Для реализации данного алгоритма необходимо хранить индексы связанных вершин.В худшем случае все вершины связаны между собой,
// поэтому общая временная сложность составляет O(Lt ^ 2)
// 
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>

std::vector<int> search(const std::string& p, const std::string& text) {
    std::vector<int> result;
    std::string s = p + '#' + text;
    std::vector<int> π(p.length(), 0);
    int π_prev = 0;
    for (int i = 1; i < s.length(); i++) {
        int k = π_prev;
        while (k > 0 && s[k] != s[i]) {
            k = π[k - 1];
        }
        if (s[k] == s[i]) {
            k += 1;
        }
        if (i < p.length()) {
            π[i] = k;
        }
        π_prev = k;
        if (k == p.length()) {
            result.push_back(i - 2 * p.length());
        }
    }
    return result;
}

void addWord(const std::string& cheat_sheet, const std::string& word, std::vector<std::vector<int>>& adjacency) {
    std::vector<int> indexes = search(word, cheat_sheet);
    for (const int& index : indexes) {
        adjacency[index].push_back(index + word.size());
    }
}

enum colors {White, Grey, Black};

bool check(const std::vector<std::vector<int>>& adjacency, const int& end) {
	std::vector<int> colors(adjacency.size() + 1, White);
	std::stack<int> stack;
	stack.push(0);

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		if (colors.at(node) == White) {
			colors[node] = Grey;
			stack.push(node);

            for (const int& connected_node: adjacency.at(node)) {
            	if (colors.at(connected_node) == White) {
            		stack.push(connected_node);
            	}
                if (connected_node == end) {
                    return true;
                }
            }
		}
		else if (colors.at(node) == Grey) {
			colors[node] = Black;
		}
	}
    return false;
}

int cheatSheet_() {
    std::string cheat_sheet;
    std::cin >> cheat_sheet;
    std::vector<std::vector<int>> adjacency(cheat_sheet.size());
    int number_words;
    std::cin >> number_words;
    for (int i = 0; i < number_words; i++) {
        std::string word;
        std::cin >> word;
        addWord(cheat_sheet, word, adjacency);
    }
    if (check(adjacency, cheat_sheet.size())) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
	return 0;
}