#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	bool stopped = false;
	while (!stopped) {
		int n, m; std::cin >> n >> m;
		if (n == 0 && m == 0) {
			stopped = true;
		}
		else {
			std::vector<int> heads; std::vector<int> knights;
			for (int i = 0; i < n; i += 1) {
				int curr; std::cin >> curr;
				heads.push_back(curr);
			}
			for (int i = 0; i < m; i += 1) {
				int curr; std::cin >> curr;
				knights.push_back(curr);
			}
			std::sort(heads.begin(), heads.end());
			std::sort(knights.begin(), knights.end());
			int coins = 0; int heads_idx = 0; int knights_idx = 0;
			while (heads_idx < n && knights_idx < m) {
				if (knights[knights_idx] >= heads[heads_idx]) {
					coins += knights[knights_idx];
					heads_idx += 1;
					knights_idx += 1;
				}
				else {
					knights_idx += 1;
				}
			}
			if (knights_idx == m && heads_idx < n) {
				std::cout << "Loowater is doomed!" << '\n';
			}
			else {
				std::cout << coins << '\n';
			}
		}
	}
}