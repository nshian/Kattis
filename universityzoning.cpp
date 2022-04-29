/*  Matric Number: A0231053X
	Full Name: Ng Sihan, Ian
	Lab Group: 4
	TA: Ammar Fathin Sabili */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

long long compute_distance(int row_allocated, int row, int col_allocated, int col) {
	return abs(row_allocated - row) + abs(col_allocated - col);
}

bool comparecells(std::pair<int, int> cell1, std::pair<int, int> cell2) {
	if (cell1.first < cell2.first) {
		return true;
	}
	if (cell1.first == cell2.first) {
		if (cell1.second < cell2.second) {
			return true;
		}
		return false;
	}
	return false;
}

struct Student {
	int row;
	int col;
	int id;
	int fac;
};

bool comparestudents(Student student1, Student student2) {
	if (student1.id < student2.id) {
		return true;
	}
	return false;
}

struct Faculty {
	int numofcells; //K
	std::vector<std::pair<int, int>> cells; //coordinates of cells allocated (to be sorted)
	std::vector<Student> students; //vector of students
	std::vector<long long> distances; //vector of distances of each student from their assigned cell (to be sorted)
	int T; //compliance target
};

int main() {
	int R, C, F, S, G;
	std::cin >> R >> C >> F >> S >> G;
	std::vector<Faculty> faculties;
	for (int i = 0; i < F; i += 1) { //reading in F lines
		Faculty curr_fac;
		std::cin >> curr_fac.numofcells;
		for (int i = 0; i < curr_fac.numofcells; i += 1) {
			int row, col; std::cin >> row >> col;
			curr_fac.cells.push_back(std::make_pair(row, col));
		}
		faculties.push_back(curr_fac);
	}
	for (int i = 0; i < S; i += 1) { //reading in S lines
		Student curr_student;
		std::cin >> curr_student.row >> curr_student.col >> curr_student.id >> curr_student.fac;
		faculties[curr_student.fac - 1].students.push_back(curr_student);
	}
	for (int i = 0; i < F; i += 1) { //reading in F times T values
		std::cin >> faculties[i].T;
	}
	for (int i = 0; i < F; i += 1) {
		std::sort(faculties[i].cells.begin(), faculties[i].cells.end(), comparecells); //sort by row and col
		std::sort(faculties[i].students.begin(), faculties[i].students.end(), comparestudents); //sort by student ID
		for (int j = 0; j < faculties[i].students.size(); j += 1) {
			int row_allocated = faculties[i].cells[j].first;
			int row = faculties[i].students[j].row;
			int col_allocated = faculties[i].cells[j].second;
			int col = faculties[i].students[j].col;
			long long distance = compute_distance(row_allocated, row, col_allocated, col);
			faculties[i].distances.push_back(distance);
		}
		std::sort(faculties[i].distances.begin(), faculties[i].distances.end());
	}
	std::vector<long long> minsteps_perfaculty(F);
	for (int i = 0; i < F; i += 1) {
		long long minsteps = 0;
		for (int j = 0; j < faculties[i].T; j += 1) {
			minsteps += faculties[i].distances[j];
		}
		minsteps_perfaculty[i] = minsteps;
	}
	std::sort(minsteps_perfaculty.begin(), minsteps_perfaculty.end());
	long long sum = 0;
	for (int i = 0; i < G; i += 1) {
		sum += minsteps_perfaculty[i];
	}
	std::cout << sum << '\n';
	return 0;
}