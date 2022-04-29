#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> cards;
	for (int i = 0; i < N; i++) {
		int curr; cin >> curr; cards.push_back(curr);
	}
	sort(cards.begin(), cards.end());
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int lower, upper; cin >> lower >> upper;
		int lower_idx = lower_bound(cards.begin(), cards.end(), lower) - cards.begin();
		int upper_idx = upper_bound(cards.begin(), cards.end(), upper) - cards.begin();
		cout << upper_idx - lower_idx << '\n';
	}
}