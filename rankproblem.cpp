#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

int main() {
	int n, m; std::cin >> n >> m;
	std::vector<int> rankings(n);
	std::iota(rankings.begin(), rankings.end(), 1);
	for (int rep = 1; rep <= m; rep += 1) {
		char t1, t2; int i, j; std::cin >> t1 >> i >> t2 >> j;
		int index_i = std::distance(rankings.begin(), std::find(rankings.begin(), rankings.end(), i));
		int index_j = std::distance(rankings.begin(), std::find(rankings.begin(), rankings.end(), j));
		if (index_i > index_j) {
			rankings.erase(rankings.begin() + index_j);
			rankings.insert(rankings.begin() + index_i, j);
		}
	}
	for (int pos = 0; pos < n; pos += 1) {
		std::cout << 'T' << rankings[pos] << " ";
	}
	std::cout << '\n';
	return 0;
}