//https://contest.yandex.ru/contest/22781/run-report/109528825/

// Привет. Для прошлого решения я делал объяснение ввиде презентации, но видимо система пропускает только cpp-файлы

// Принцип работы
//Реализация калькулятора с польской нотацией реализована на основе стека. В качестве стека используется контейнер 
// stack из стандартной библиотеки stl.
//При считывании числа из консоли оно добавляется в стек.
//При считывании арифметической операции из стека извлекается два числа производиться операция над ними и 
// затем полученное значение добавляется в стек.
//В качестве окончательного значения выводиться верхний элемент стека.

// Доказательство коррекности. Не совсем понимаю что необходимо писать.
// Из описанного алгоритма следует, что чем раньше было добавлено число тем раньше оно будет использоваться выполнения 
// арифметического выражения.
// Если количество чисел больше чем необходимо, то выводиться последнее добавленное в стек.
// Для правильного деления (с учетом условий задачи) условное ветвеление. Если делимое число больше нуля и делиться без остатка на делитель,
// то делимое просто делиться на делитель, иначе от частного отнимается 1. Например -12 / 8 = (-12 / 8 ) - 1 = -2. То есть округляется в меньшую сторону


// Временная сложность
//Сложность выполнения цикла for – линейная О(N), где N – количество чисел и знаков операции.
//В каждой итерации цикла одна из возможных условных ветвей :
//Добавление числа в стек – амортизированная сложность в среднем О(1).
//Выполнение арифметической операции. В нее входит: извлечение двух элементов из стека О(2), выполнение операции О(1) и 
// добавление в стек О(1).То есть сложность выполнение арифметической операции О(1).
//Значит общая сложность в среднем составляет О(N).

// Пространственная сложность.
// Для реализации алгоритма используется вспомогательный вектор, который хранить в себе N строк, где N - количество чисел и знаков операции.
// Также используется стек, в котором в худшем случае (если сначала идут только числа потом знаки операции) будет лежать M элементов, 
// где M - количество чисел. Прием M < N. 
// Поэтому общая пространственная сложность составляет O(N).

// Я не понял почему это решение лучше чем прошлое. Если в прошлом не используется дополнительный вектор как в этом и 
// пространственная сложность для него по сути меньше и составляет O(M)

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