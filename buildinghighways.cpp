#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> levels;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int curr; cin >> curr;
		levels.push_back(curr);
	}
	sort(levels.begin(), levels.end());
	long long total = 0;
	for (int i = 1; i < N; i++) {
		int weight = levels[0] + levels[i];
		total += weight;
	}
	cout << total << '\n';
}