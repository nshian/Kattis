#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> mountains;
	int highest = 0;
	int highest_idx = 0;
	for (int i = 0; i < N; i++) {
		int curr; cin >> curr;
		if (curr > highest) {
			highest = curr;
			highest_idx = i;
		}
		mountains.push_back(curr);
	}
	int secondhighest = 0;
	int lowest = 999999;
	int distance = 0;
	for (int i = 0; i < highest_idx; i++) {
		if (mountains[i] >= secondhighest) {
			secondhighest = mountains[i];
			lowest = 999999;
		}
		else {
			if (mountains[i] < lowest) {
				lowest = mountains[i];
				if(secondhighest - lowest > distance)
					distance = secondhighest - lowest;
			}
		}
	}
	secondhighest = 0;
	lowest = 999999;
	for (int i = N - 1; i > highest_idx; i--) {
		if (mountains[i] >= secondhighest) {
			secondhighest = mountains[i];
			lowest = 999999;
		}
		else {
			if (mountains[i] < lowest) {
				lowest = mountains[i];
				if (secondhighest - lowest > distance)
					distance = secondhighest - lowest;
			}
		}
	}
	cout << distance << '\n';
}