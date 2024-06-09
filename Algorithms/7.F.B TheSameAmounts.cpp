//https://contest.yandex.ru/contest/25597/run-report/114735047/
// Принцип работы
// Работа данной программы основана алгоритме задачи о рюкзаке.
// Если возможно набрать элементы так чтобы их сумма равнялась половине суммы всех очков в играх, то другая половина также в сумме дает
// половину суммы всех очков.
// 
// Доказательство корректности.
// Алгоритм данной задачи сводиться к алгоритму поиску максимальной вместимости в рюкзак.
// Если сумма очков в играх - это не целое число, то очки невозможно разделить на две равные группы.
// Иначе будем проверять возможность собрать из очков половину от суммы всех очков.
// 
// В таблице dp[i][j] будем хранить возможность собрать сумму j из очков.
// Базовый случай : если половина от общей суммы ноль и первое очко равняется 0, то половину от суммы собрать возможно.
// Переход динамики Если не брать i-е очко, то возможность собрать j сумму равняется dp[i-1][j]
// Если возможно собрать сумму равная разнице j суммы и iго очка, то и собрать сумму j также возможно.
// 
// Сначала берется первое очко, и постепенно увеличивается половина от суммы всех очков. Затем добавляется следующее очко и также
// постепенно увеличивается половина от суммы всех очков.
// 
// Результатов работы алгоритма является число в ячейки dp[0][M], где M - сумма от половины всех очков.
// Если dp[0][M] равно true, значит можно набрать так очки чтобы их сумма равнялась сумме оставшимся очкам.
// 
// Временная сложность
// Так как в результате работы алгоритма необходимо пройтись по всей таблицы dp[N][M], значит общая временная сложность алгоритма
// составляет O(N* M), где N - количество всех очков, M - половина от суммы всех очков.
// 
// Пространственная сложность.
// Для работы данного алгоритма на каждом этапе необходимо в памяти хранить две строки размером M.В одной хранятся текущие значение,
// в другой значения полученные на предыдущем этапе.
// Поэтому общая пространственная сложность составляет O(2 * M) ~O(M), где M - половина от суммы всех очков.

#include <iostream>
#include <vector>

int calculate_max(const std::vector<int>& points, const int& summ) {
	std::vector<std::vector<bool>> dp(2, std::vector<bool>(summ + 1, 0));
	for (int number_point = 0; number_point < points.size(); number_point++) {
		for (int number_summ = 0; number_summ <= summ; number_summ++) {
			bool previous_summ = false, current_summ = false;

			if (number_point > 0) {
				previous_summ = dp.at(0).at(number_summ);
			}
			if (number_summ >= points.at(number_point)) {
				current_summ = (points.at(number_point) == number_summ);
				if (number_point > 0 && !current_summ) {
					current_summ = dp.at(0).at(number_summ - points.at(number_point));
				}
			}
			dp[1][number_summ] = previous_summ || current_summ;
		}
		std::swap(dp[0], dp[1]);
	}
	return dp.begin()->back();
}

bool splitting(const std::vector<int>& points, int summ) {
	if (summ % 2 != 0) {
		return false;
	}
	else {
		summ /= 2;
		if (calculate_max(points, summ)) {
			return true;
		}
		else {
			return false;
		}
	}
}

int theSameAmounts() {
	int number_points;
	std::cin >> number_points;
	std::vector<int> points;
	int summ_points = 0;
	for (int i = 0; i < number_points; i++) {
		int point;
		std::cin >> point;
		summ_points += point;
		points.push_back(point);
	}
	if (splitting(points, summ_points)) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}
	return 0;
}