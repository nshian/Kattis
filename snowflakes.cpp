#include <iostream>
#include <unordered_set>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test; cin >> test;
	for (int i = 0; i < test; i++) {
		int max_length = 0;
		unordered_set<int> flakes;
		int n; cin >> n;
		list<int> sequence;
		for (int j = 0; j < n; j++) {
			int curr; cin >> curr;
			if (flakes.find(curr) == flakes.end()) { //this is a unique snowflake
				flakes.insert(curr);
				sequence.push_back(curr);
				if (sequence.size() > max_length)
					max_length = sequence.size();
			}
			else { //duplicate snowflake encountered
				while (sequence.front() != curr) { //delete all the flakes from before the first occurrence of the repeated flake
					flakes.erase(sequence.front());
					sequence.pop_front();
				}
				sequence.pop_front();
				sequence.push_back(curr);
			}
		}
		cout << max_length << '\n';
	}
}