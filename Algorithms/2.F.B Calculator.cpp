//https://contest.yandex.ru/contest/22781/run-report/109528825/

// ������. ��� �������� ������� � ����� ���������� ����� �����������, �� ������ ������� ���������� ������ cpp-�����

// ������� ������
//���������� ������������ � �������� �������� ����������� �� ������ �����. � �������� ����� ������������ ��������� 
// stack �� ����������� ���������� stl.
//��� ���������� ����� �� ������� ��� ����������� � ����.
//��� ���������� �������������� �������� �� ����� ����������� ��� ����� ������������� �������� ��� ���� � 
// ����� ���������� �������� ����������� � ����.
//� �������� �������������� �������� ���������� ������� ������� �����.

// �������������� �����������. �� ������ ������� ��� ���������� ������.
// �� ���������� ��������� �������, ��� ��� ������ ���� ��������� ����� ��� ������ ��� ����� �������������� ���������� 
// ��������������� ���������.
// ���� ���������� ����� ������ ��� ����������, �� ���������� ��������� ����������� � ����.
// ��� ����������� ������� (� ������ ������� ������) �������� ����������. ���� ������� ����� ������ ���� � �������� ��� ������� �� ��������,
// �� ������� ������ �������� �� ��������, ����� �� �������� ���������� 1. �������� -12 / 8 = (-12 / 8 ) - 1 = -2. �� ���� ����������� � ������� �������


// ��������� ���������
//��������� ���������� ����� for � �������� �(N), ��� N � ���������� ����� � ������ ��������.
//� ������ �������� ����� ���� �� ��������� �������� ������ :
//���������� ����� � ���� � ���������������� ��������� � ������� �(1).
//���������� �������������� ��������. � ��� ������: ���������� ���� ��������� �� ����� �(2), ���������� �������� �(1) � 
// ���������� � ���� �(1).�� ���� ��������� ���������� �������������� �������� �(1).
//������ ����� ��������� � ������� ���������� �(N).

// ���������������� ���������.
// ��� ���������� ��������� ������������ ��������������� ������, ������� ������� � ���� N �����, ��� N - ���������� ����� � ������ ��������.
// ����� ������������ ����, � ������� � ������ ������ (���� ������� ���� ������ ����� ����� ����� ��������) ����� ������ M ���������, 
// ��� M - ���������� �����. ����� M < N. 
// ������� ����� ���������������� ��������� ���������� O(N).

// � �� ����� ������ ��� ������� ����� ��� �������. ���� � ������� �� ������������ �������������� ������ ��� � ���� � 
// ���������������� ��������� ��� ���� �� ���� ������ � ���������� O(M)

#include <iostream>
#include <sstream>
#include <stack>
#include <iterator>
#include <vector>

void operation(std::stack<int>& stack, const char& symbol) {
	int second_operand = stack.top();
	stack.pop();
	int first_operand = stack.top();
	stack.pop();
	if (symbol == '-') {
		stack.push(first_operand - second_operand);
	}
	else if (symbol == '+') {
		stack.push(first_operand + second_operand);
	}
	else if (symbol == '/') {
		if (first_operand >= 0 || first_operand % second_operand == 0) {
			stack.push(first_operand / second_operand);
		}
		else {
			stack.push(first_operand / second_operand + first_operand / abs(first_operand));
		}
	}
	else if (symbol == '*') {
		stack.push(first_operand * second_operand);
	}
}

int calculator() {
	std::stack<int> stack;
	std::string expression;
	std::getline(std::cin, expression);

	std::istringstream stream_expression(expression);
	std::istream_iterator<std::string> input(stream_expression), eof;
	std::vector<std::string> vec_expression(input, eof);

	for (std::vector<std::string>::const_iterator part_expression = vec_expression.cbegin(); part_expression != vec_expression.cend(); part_expression++) {
		if (part_expression->size() == 1 && (*part_expression->cbegin() == '+' ||
			*part_expression->cbegin() == '-' || *part_expression->cbegin() == '*' || *part_expression->cbegin() == '/')) {
			operation(stack, *part_expression->cbegin());
		}
		else {
			stack.push(stoi(*part_expression));
		}
	}
	std::cout << stack.top();
	

	return 0;
}