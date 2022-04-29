#include <iostream>

int main() {
	int N; std::cin >> N;
	int total = 0;
	for (int i = 0; i < N; i += 1) {
		int curr; std::cin >> curr;
		total += curr;
	}
	std::cout << total - (N - 1) << '\n';
}