#include <iostream>

int main() {
	int N; std::cin >> N;
	int real = 0; int placebo = 0; double real_A = 0; double real_B = 0; double real_C = 0; double placebo_A = 0; double placebo_B = 0; double placebo_C = 0;
	for (int i = 0; i < N; i += 1) {
		char vaccine; std::cin >> vaccine;
		if (vaccine == 'Y') {
			real += 1;
			char A, B, C; std::cin >> A >> B >> C;
			if (A == 'Y') {
				real_A += 1;
			}
			if (B == 'Y') {
				real_B += 1;
			}
			if (C == 'Y') {
				real_C += 1;
			}
		}
		else {
			placebo += 1;
			char A, B, C; std::cin >> A >> B >> C;
			if (A == 'Y') {
				placebo_A += 1;
			}
			if (B == 'Y') {
				placebo_B += 1;
			}
			if (C == 'Y') {
				placebo_C += 1;
			}
		}
	}
	real_A = real_A / real * 100;
	real_B = real_B / real * 100;
	real_C = real_C / real * 100;
	placebo_A = placebo_A / placebo * 100;
	placebo_B = placebo_B / placebo * 100;
	placebo_C = placebo_C / placebo * 100;
	if (real_A >= placebo_A) {
		std::cout << "Not Effective" << '\n';
	}
	else {
		std::cout << (placebo_A - real_A) / placebo_A * 100 << '\n';
	}
	if (real_B >= placebo_B) {
		std::cout << "Not Effective" << '\n';
	}
	else {
		std::cout << (placebo_B - real_B) / placebo_B * 100 << '\n';
	}
	if (real_C >= placebo_C) {
		std::cout << "Not Effective" << '\n';
	}
	else {
		std::cout << (placebo_C - real_C) / placebo_C * 100 << '\n';
	}
}