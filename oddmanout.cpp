#include <iostream>
#include <unordered_set>

int main() {
	int N; std::cin >> N;
	for (int i = 1; i <= N; i++) {
		std::unordered_set<int> guests;
		int G; std::cin >> G;
		for (int j = 0; j < G; j++) {
			int C; std::cin >> C;
			if (!(guests.insert(C).second))
				guests.erase(C);
		}
		std::cout << "Case #" << i << ": " << *(guests.begin()) << '\n';
	}
	return 0;
}