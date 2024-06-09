// https://contest.yandex.ru/contest/23815/run-report/110305597/

// ������� ������
// ������� ������ ������� ��������� ���� � ������� ���������� ������� ����������, �� ����������� ����, ��� � ������ �� ������������
// �������������� ������ ��� �������� �������� � ���������� ������ ��������, ���������� ������ �������� � ������� ��������.
//
// �������������� ������������
// � �������� ������� ������ ������� ������� ������� (�� ����� �������). ����� ��� �������� ������� ������ �������� ����������� 
// � ����� �����, � �������� ������ �������� ����������� � ������ �����. ����� ����� ��������� ���������� ������� ���������� 
// ��� ������ �� ������, �� ��� ��� ���� ����������� ������ �� ����� ��������� ���� �������. ����� ���������� ������ � ���������� 
// �������� ��������, ������� ������� � ������ � ���������� ������ �������� � ������������� (��������������) ������.
// 
// ��������� ���������
// � ������ ������ ���� ������ ��� ������� ������� ����� �������� ���������� ��� ���������� �� ����, �� �������� ��� �������� �������������
// ���� ����� �������. 
// ��� �� ��� ��������� ������ ���������� ���������� ����� � �������� ���������� ���������� �������, �� ����� ����������� ������������������
// ��������� �� �����. �� ���� ������� ��������� ������� �� ��� ����� ����� ����� ���������������� ��������� ������ O(N*M), 
// ��� N - ���������� ��������� � ������, M - ������� ���������� �������� � ������. 
// ����� ��������� ���������� ��������� ���������� �� N-1 ���������.

// ������� �������� � ���� ������ ����� N.
// ������ ��������� ��������� ��������� � ������ ������ ����� ���������� O(N^2*M), ��� N - ���������� ��������� � �������,
// M - ������� ���������� �������� � ������.
// 
// � ����� ������ (���-�� ������� ����� � ������� ������ ��������� �� O(1)) ������ ��� ������ ����� ����������� �� ��� ����� 
// (��� ����� ����� �����, ������ ����� �������� ��������). ������� �������� � ���� ������ ����� log2(N).
// ������ ��������� ��������� � ����� ������ ����� ������������ O(N*ln(N)), ��� N - ���������� ��������� � �������.
// 
// ����������������� ���������.
// � ������ ��������� ������ ��������� ������� �� ����� ���������� ������� ������� �������, ��������� ������ � ����� ����������.
// ������� ����� � ����� ������ ln(N), ��� N - ���������� ��������� � �������. 
// ������� ������� �������� � ���� ��� ����������: ���-�� �������� ����� O(1), ���-�� ������� O(1) � ��� O(M), ��� M - ���-�� �������� � �����.
// ������ ����� ���������������� ��������� ������� ��������� ���������� O(ln(N)*M), ��� N - ���������� ��������� � �������� �������, 
// M - ���-�� �������� � �����

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
