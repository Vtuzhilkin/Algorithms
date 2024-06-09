// https://contest.yandex.ru/contest/24810/run-report/113524496/
// Принцип работы
// Принцип работы пирамидальной сортировки реализован с использованием структуры данных бинарная куча.
// Все добавляемые элементы просеиваются вверх. После извлечения вершины, новая вершина просеивается вниз.
// 
// Доказательство корректности
// Сначала создается бинарная куча из входных данных. После добавление нового элемента в конец очереди происходит восстановление
// свойств кучи с помощью функции "просеивание вверх".
// После создания бинарной кучи, создается отсортированный массив. Первым элементов в отсортированный массив добавляется
// вершина кучи, затем на ее место вставляется последний элемент кучи, после этого происходит восстановление кучи с помощью функции
// "просеивание вниз". Извлечение из вершины элемента и восстановление кучи повторяется пока все элементы из кучи не будут добавлены
// в отсортированный массив.
// 
// Временная сложность
// Создание бинарной кучи из входных данных :
// При добавлении 1 - го элемента в очередь он вставляется в вершину очереди - O(1), просеивание вверх не происходит.
// При добавлении m - го элемента первым действием происходит вставка его в конец очереди - O(1), затем данные элемент просеивается вверх.
// В худшем случае, если добавленный элемент наименьший, просеивание вверх занимает - O(log(m)).
// Следовательно вставка N элементов занимает : O(1) ... + O(log(m)) + ... O(log(N)) = O(N * log(N / 2)) = O(N * log(N)).
// Создание отсортированного списка.
// Аналогично добавлению N элемент, временная сложность удаления N элементов занимает O(N * log(N)).
// Итоговая временная сложность алгоритма пирамидальной сортировки составляет O(N * log(N)).
// 
// Пространственная сложность.
// Для реализации алгоритма бинарной сортировки необходимо выделить память под бинарную кучу для N элементов - O(N).
// А также необходимо выделить память под отсортированный массив для N элементов - O(N).
// Итоговая пространственная сложность составляет O(N).


#include <iostream>
#include <string>
#include <vector>
#include <tuple>

struct Participant {
	Participant(std::string name, int completed_tasks, int fines) : name(name), completed_tasks(completed_tasks), fines(fines) {};
	std::string name;
	int completed_tasks;
	int fines;
};

std::tuple<int, int, const std::string&> make_tuple(const Participant& prt) {
	return std::tuple<int, int, const std::string&>(-prt.completed_tasks, prt.fines, prt.name);
}

bool operator<(const Participant& first_prt, const Participant second_prt) {
	return make_tuple(first_prt) > make_tuple(second_prt);
}

bool operator==(const Participant& first_prt, const Participant second_prt) {
	return make_tuple(first_prt) == make_tuple(second_prt);
}

bool operator>(const Participant& first_prt, const Participant second_prt) {
	return second_prt < first_prt;
}

class Heap {
private:
	std::vector<Participant> heap;
	std::vector<Participant> sorted_list;

	void swap(int& idx, int idx_swap) {
		Participant help = heap.at(idx);
		heap[idx] = heap[idx_swap];
		heap[idx_swap] = help;
		idx = idx_swap;
	}

	void siftUp() {
		int idx = heap.size() - 1;
		while (heap.at(idx) > heap.at(idx / 2) && idx != 1) {
			swap(idx, idx / 2);
		}
		if (heap.size() > 2 * idx + 1 && heap.at(idx) < heap.at(2 * idx + 1)) {
			swap(idx, 2 * idx + 1);
		}
	}

	void siftDown() {
		int idx = 1;
		while (2 * idx + 1 < heap.size() && !(heap.at(idx) > heap.at(2 * idx) && heap.at(idx) > heap.at(2 * idx + 1))) {
			if (heap.at(idx) < heap.at(2 * idx) && heap.at(idx) < heap.at(2 * idx + 1)) {
				int help_idx = 2*idx;
				if (heap.at(2 * idx) < heap.at(2 * idx + 1)) {
					help_idx++;
				}
				swap(idx, help_idx);
			} else if (heap.at(idx) < heap.at(2 * idx)) {
				swap(idx, 2*idx);
			} else if (heap.at(idx) < heap.at(2 * idx + 1)) {
				swap(idx, 2 * idx + 1);
			}
		}
		if (2 * idx < heap.size() && heap.at(2 * idx) > heap.at(idx)) {
			swap(idx, 2 * idx);
		}
	}

public:
	Heap() {
		heap.push_back({ "null", 0,0 });
	}
	void add(const Participant& prt) {
		heap.push_back(prt);
		siftUp();
	}
	void make_sorted() {
		while (heap.size() != 1) {
			sorted_list.push_back(*++heap.begin());
			*++heap.begin() = heap.back();
			heap.pop_back();
			siftDown();
		}
	}
	void printed_sorted() {
		for (std::vector<Participant>::const_iterator prt = sorted_list.cbegin(); prt != sorted_list.cend(); prt++) {
			std::cout << prt->name << std::endl;
		}
	}
};

int pyramidSorting(){
	Heap participants;
	int number_participants;
	std::cin >> number_participants;
	for (int i = 0; i < number_participants; i++) {
		std::string name;
		int completed_tasks;
		int fines;
		std::cin >> name >> completed_tasks >> fines;
		participants.add({ name, completed_tasks, fines });
	}
	participants.make_sorted();
	participants.printed_sorted();
	return 0;
}