#include <iostream>
#include <vector>
#include <algorithm>

struct Bed
{
	int start;
	int end;
};

int flowerBeds() {
	std::vector<Bed> beds;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		std::cin >> start >> end;
		beds.push_back({ start, end });
	}
	std::sort(beds.begin(), beds.end(), [&](const Bed& first, const Bed& second) {return first.start < second.start; });
	Bed left_bed = *beds.begin();
	for (int i = 1; i < N; i++) {
		const Bed& current_bed = beds.at(i);
		if (left_bed.start == current_bed.start) {
			left_bed = { left_bed.start, std::max(left_bed.end, current_bed.end) };
		}
		else {
			if (left_bed.end < current_bed.start) {
				std::cout << left_bed.start << " " << left_bed.end << std::endl;
				left_bed = beds.at(i);
			}
			else {
				left_bed = { left_bed.start, std::max(left_bed.end, current_bed.end) };
			}
		}
	}
	std::cout << left_bed.start << " " << left_bed.end;
	return 0;
}