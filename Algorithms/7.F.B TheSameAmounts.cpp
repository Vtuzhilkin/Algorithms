//https://contest.yandex.ru/contest/25597/run-report/114735047/
// ������� ������
// ������ ������ ��������� �������� ��������� ������ � �������.
// ���� �������� ������� �������� ��� ����� �� ����� ��������� �������� ����� ���� ����� � �����, �� ������ �������� ����� � ����� ����
// �������� ����� ���� �����.
// 
// �������������� ������������.
// �������� ������ ������ ��������� � ��������� ������ ������������ ����������� � ������.
// ���� ����� ����� � ����� - ��� �� ����� �����, �� ���� ���������� ��������� �� ��� ������ ������.
// ����� ����� ��������� ����������� ������� �� ����� �������� �� ����� ���� �����.
// 
// � ������� dp[i][j] ����� ������� ����������� ������� ����� j �� �����.
// ������� ������ : ���� �������� �� ����� ����� ���� � ������ ���� ��������� 0, �� �������� �� ����� ������� ��������.
// ������� �������� ���� �� ����� i-� ����, �� ����������� ������� j ����� ��������� dp[i-1][j]
// ���� �������� ������� ����� ������ ������� j ����� � i�� ����, �� � ������� ����� j ����� ��������.
// 
// ������� ������� ������ ����, � ���������� ������������� �������� �� ����� ���� �����. ����� ����������� ��������� ���� � �����
// ���������� ������������� �������� �� ����� ���� �����.
// 
// ����������� ������ ��������� �������� ����� � ������ dp[0][M], ��� M - ����� �� �������� ���� �����.
// ���� dp[0][M] ����� true, ������ ����� ������� ��� ���� ����� �� ����� ��������� ����� ���������� �����.
// 
// ��������� ���������
// ��� ��� � ���������� ������ ��������� ���������� �������� �� ���� ������� dp[N][M], ������ ����� ��������� ��������� ���������
// ���������� O(N* M), ��� N - ���������� ���� �����, M - �������� �� ����� ���� �����.
// 
// ���������������� ���������.
// ��� ������ ������� ��������� �� ������ ����� ���������� � ������ ������� ��� ������ �������� M.� ����� �������� ������� ��������,
// � ������ �������� ���������� �� ���������� �����.
// ������� ����� ���������������� ��������� ���������� O(2 * M) ~O(M), ��� M - �������� �� ����� ���� �����.

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