#include <iostream>

bool validity_checker(long dividend, long number) {
	bool appeared[9] = { false };
	while (dividend != 0) {
		int digit = dividend % 10;
		if (digit == 0) {
			return false;
		}
		if (appeared[digit - 1] == false && number % digit == 0) {
			appeared[digit - 1] = true;
			dividend /= 10;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	long L, H; std::cin >> L >> H;
	long count = 0;
	for (long i = L; i <= H; i += 1) {
		if (validity_checker(i, i)) {
			count += 1;
		}
	}
	std::cout << count << '\n';
	return 0;
}