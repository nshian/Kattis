#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n; cin >> n; string dummy; getline(cin, dummy);
	unordered_map<string, string> parties;
	for (int i = 0; i < n; i++) {
		string candidate, party;
		getline(cin, candidate); getline(cin, party);
		parties[candidate] = party;
	}
	int m; cin >> m; getline(cin, dummy);
	unordered_map<string, int> votes;
	int max_votes = 0;
	for (int i = 0; i < m; i++) {
		string candidate; getline(cin, candidate);
		if (votes.find(candidate) == votes.end())
			votes[candidate] = 1;
		else
			votes[candidate]++;
		if (votes[candidate] > max_votes)
			max_votes = votes[candidate];
	}
	bool duplicate = false;
	int num = 0;
	for (auto v : votes) {
		if (v.second == max_votes)
			num++;
	}
	if (num != 1)
		duplicate = true;
	if (duplicate)
		cout << "tie" << '\n';
	else {
		for (auto v : votes) {
			if (v.second == max_votes) {
				cout << parties[v.first] << '\n';
			}
				
		}
	}
}