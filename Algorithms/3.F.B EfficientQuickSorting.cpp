// https://contest.yandex.ru/contest/23815/run-report/110305597/

// Принцип работы
// Принцип работы данного алгоритма схож с обычным алгоритмом быстрой сортировки, за исключением того, что в данном не используется
// дополнительная память для хранения массивов с элементами больше опорного, элементами меньше опорного и равными опорному.
//
// Доказательство корректности
// В исходном массиве данных берется средний элемент (он будет опорным). Затем все элементы которые меньше среднего переносятся 
// в левую часть, а элементы больше среднего переносятся в правую часть. После этого рекурсино вызывается функция сортировки 
// для каждой из частей, до тех пор пока сортируемый массив не будет содержать один элемент. Затем полученные массив с элементами 
// меньшего опорного, средний элемент и массив с элементами больше опорного в результирущий (отсортирванный) массив.
// 
// Временная сложность
// В худшем случае если каждый раз опорный элемент будет является наименьшем или наибольшим из всех, то придется все элементы перекладывать
// одну часть массива. 
// Так же все участники решили одинаковое количество задач и получили одинаковое количество штрафов, то будет происходить лексикографическое
// сравнение по имени. То есть функция разбиения массива на три части будет иметь пространственную сложность равной O(N*M), 
// где N - количество элементов в массив, M - среднее количество символов в именах. 
// Затем вызовется рекурсивно вызовется сортировка от N-1 элементов.

// Глубина рекурсии в этом случае равна N.
// Значит временная сложность алгоритма в худшем случае будет составлять O(N^2*M), где N - количество элементов в массиве,
// M - среднее количество символов в именах.
// 
// В общем случае (кол-во решеных задач и штрафов разное сравнение за O(1)) каждый раз массив будет разбиваться на три части 
// (две равны между собой, третья равна опорному элементу). Глубина рекурсии в этом случае равна log2(N).
// Значит временная сложность в общем случае будет составляться O(N*ln(N)), где N - количество элементов в массиве.
// 
// Пространнственная сложность.
// В данном алгоритма помимо исходного массива на стеке необходимо хранить опорный элемент, итераторы начала и конца интервалов.
// Глубина стека в общем случае ln(N), где N - количество элементов в массиве. 
// Опорный элемент включает в себя три переменные: кол-во решенных задач O(1), кол-во штрафов O(1) м имя O(M), где M - кол-во символов в имени.
// Значит общая пространственная сложность данного алгоритма составляет O(ln(N)*M), где N - количество элементов в исходном массиве, 
// M - кол-во символов в имени

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

bool operator<(const Participant& first_prt, const Participant second_prt) {
	return std::tuple<int, int, const std::string&>(-first_prt.completed_tasks, first_prt.fines, first_prt.name) > 
		std::tuple<int, int, const std::string&>(-second_prt.completed_tasks, second_prt.fines, second_prt.name);
}

bool operator==(const Participant& first_prt, const Participant second_prt) {
	return std::tuple<int, int, const std::string&>(first_prt.completed_tasks, first_prt.fines, first_prt.name) ==
		std::tuple<int, int, const std::string&>(second_prt.completed_tasks, second_prt.fines, second_prt.name);
}

bool operator>(const Participant& first_prt, const Participant second_prt) {
	return second_prt < first_prt;
}

std::vector<Participant>::iterator paritition(std::vector<Participant>::iterator left, std::vector<Participant>::iterator right, const Participant& pivot) {
	if (right - left == 1) {
		if (*left > *right) {
			std::swap(*left, *right);
		}
		return left;
	}
	while (left != right) {
		while (*left < pivot) {
			left++;
		}
		while (*right > pivot) {
			right--;
		}
		std::swap(*left, *right);
	}
	return left;
}

void quick_sort(std::vector<Participant>::iterator begin, std::vector<Participant>::iterator end) {
	if (end - begin < 1) {
		return;
	}
	else {
		const Participant pivot = *(begin + (end - begin) / 2);
		std::vector<Participant>::iterator iter_middle = paritition(begin, end, pivot);
		if (iter_middle != begin) quick_sort(begin, iter_middle - 1);
		if (iter_middle != end) quick_sort(iter_middle + 1, end);
		return;
	}
}

void quick_sort(std::vector<Participant>& participants) {
	quick_sort(participants.begin(), --participants.end());
}

int efficientQuickSorting() {
	int number_participants;
	std::cin >> number_participants;
	std::vector<Participant> participants;
	std::string name;
	int completed_tasks, fines;
	for (int i = 0; i < number_participants; i++) {
		std::cin >> name >> completed_tasks >> fines;
		participants.push_back(Participant{ name, completed_tasks, fines });
	}
	quick_sort(participants);
	for (std::vector<Participant>::const_reverse_iterator iter = participants.crbegin(); iter < participants.crend(); iter++) {
		std::cout << iter->name << std::endl;
	}
	return 0;
}
