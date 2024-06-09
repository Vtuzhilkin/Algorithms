//https://contest.yandex.ru/contest/26133/run-report/114957945/
// Принцип работы
// Работа реализованной программы основана префиксном дереве.Из введенных шаблон создается префиксное дерево, затем с помощью
// дерева проверяется возможность составить введенный текст из шаблонов.
// 
// Доказательство корректности.
// После считывания очередного шаблона, алгоритм посимвольно проходится по шаблону
//		Если вершины с таким символом нет, то создается новая вершина
//		Иначе указатель текущей вершины перемещается на вершину с нужным символов.
// 
// После создания префиксного дерева, проверяется возможность составить текст из шаблонов с помощью динамического программирования.
// Создается вектор dp размером длину текста + 1 и dp[0] присваивается значение true.
// Затем происходит итерация по всей длине текста.
//		Если dp[i] = true, то алгоритм проходится по префиксному дереву и если очередная вершина является терминальной,
//			то dp[number_root] присваивается значение true.
// 
// Если после выхода из цикла значения последнего элемента в dp равно true, значит текст можно составить из введенных шаблонов.
// 
// Временная сложность
// Программа работает в два этапа.
// 1. Создания префиксного дерева.Для этого необходимо пройтись каждому символу всех шаблонов.
//		Поэтому временная сложность данного этапа составляет - O(M * l), где M - количество шаблонов, l - средняя длина шаблона.
//		Или O(L), где L - суммарная длина всех шаблонов.
// 2. В худшем случае если введенные шаблоны это все суффиксы данного текста.Тогда на каждой итерации необходимо будет спуститься
//		в вниз дерева.Количество итераций равно длина текста, а средняя высота дерева равна половине длины текста, поэтому
//		временная сложность 2го этапа равна O(N * N / 2) ~O(N ^ 2), где N - размер текста.
// 
// Общая временная сложность составляет O(M * l + N ^ 2).Если N >> l или N >> M, то можно свести к O(N ^ 2).
// 
// Пространственная сложность.
// В худшем случае необходимо будет хранить шаблоны(если у них нет пересекающихся префиксов), поэтому общая временная сложность
// составляет O(L), где L - суммарная длина всех шаблонов.
// 
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

struct Node {
	std::unordered_map<char, std::unique_ptr<Node>> nodes;
	bool terminalNode = false;
};

class PrefixTree {
private:
	Node root;
public:
	void addWord(const std::string& word) {
		Node* current_root = &root;
		for (const char& symbol : word) {
			if (current_root->nodes.find(symbol) == current_root->nodes.end()) {
				current_root->nodes[symbol] = std::make_unique<Node>();
			}
			current_root = current_root->nodes[symbol].get();
		}
		current_root->terminalNode = true;
	}
	bool searchWord(const std::string& word) {
		Node* current_root = &root;
		std::vector<int> dp(word.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i < word.size(); i++) {
			if (dp.at(i)) {
				int index = i;
				while (index < word.size() && current_root->nodes.find(word.at(index)) != current_root->nodes.end()) {
					current_root = current_root->nodes[word.at(index)].get();
					if (current_root->terminalNode) {
						dp[index + 1] = true;
					}
					index++;
				}
				current_root = &root;
			}
		}
		return dp.back();
	}
};

int chatSheet() {
	std::string text;
	std::cin >> text;
	int number_patterns;
	std::cin >> number_patterns;
	PrefixTree prefixTree;
	for (int i = 0; i < number_patterns; i++) {
		std::string new_pattern;
		std::cin >> new_pattern;
		prefixTree.addWord(new_pattern);
	}
	if (prefixTree.searchWord(text)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}