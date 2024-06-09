#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct University {
	University(int id, int num_part) : ID(id), number_participant(num_part) {};
	int ID;
	int number_participant = 0;


};

bool compare(const University& first, const University& second) {
	if (first.number_participant == second.number_participant) {
		return first.ID < second.ID;
	}
	else {
		return first.number_participant > second.number_participant;
	}
}


int conferenceLovers() {
	int number_students;
	std::cin >> number_students;
	std::map<int, int> number_universities;
	std::vector<University> ids;
	for (int i = 0; i < number_students; i++) {
		int id;
		std::cin >> id;
		if (number_universities[id] != 0) {
			ids[number_universities[id] - 1].number_participant++;
		}
		else {
			ids.push_back(University{ id, 1 });
			number_universities[id] = ids.size();
		}
	}
	std::sort(ids.begin(), ids.end(), compare);
	int number;
	std::cin >> number;
	number = std::min(number, int(ids.size()));
	for (int i = 0; i < number; i++) {
		std::cout << ids[i].ID << " ";
	}

}