#include <iostream>
#include <cstdlib>

int main() {
	int n; std::cin >> n;
	for (int i = 0; i < n; i += 1) {
		bool found = false;
		int s, d; std::cin >> s >> d;
		int a = 0;
		while(a <= s/2 && !found) {
			if (abs(a - (s - a)) == d) {
				found = true;
				std::cout << s-a << " " << a << '\n';
			}
			a += 1;
		}
		if (!found) {
			std::cout << "impossible" << '\n';
		}
	}
}