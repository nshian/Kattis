#include <iostream>
#include <vector>

int main() {
	bool stopped = false;
	while (!stopped) {
		int N, M; std::cin >> N >> M;
		if (N == 0 && M == 0) {
			stopped = true;
		}
		else {
			std::vector<int> jack;
			std::vector<int> jill;
			int count = 0;
			int jack_idx = 0;
			int jill_idx = 0;
			for (int i = 0; i < N; i += 1) {
				int curr; std::cin >> curr;
				jack.push_back(curr);
			}
			for (int i = 0; i < M; i += 1) {
				int curr; std::cin >> curr;
				jill.push_back(curr);
			}
			while (jack_idx < jack.size() && jill_idx < jill.size()) {
				if (jack[jack_idx] == jill[jill_idx]) {
					count += 1;
					jack_idx += 1;
					jill_idx += 1;
				}
				else if (jack[jack_idx] < jill[jill_idx]) {
					jack_idx += 1;
				}
				else {
					jill_idx += 1;
				}
			}
			std::cout << count << '\n';
		}
	}
}