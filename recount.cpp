#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, int> votes;
	string candidate;
	int max_count = 0;
	while (getline(cin, candidate)) {
		if (candidate == "***")
			break;
		else {
			if (votes.find(candidate) == votes.end())
				votes[candidate] = 1;
			else
				votes[candidate]++;
			if (votes[candidate] > max_count)
				max_count = votes[candidate];
		}
	}
	int num = 0;
	string winner = "";
	for (auto v : votes)
		if (v.second == max_count) {
			num++;
			winner = v.first;
		}
	if (num != 1)
		cout << "Runoff!" << '\n';
	else
		cout << winner << '\n';
}