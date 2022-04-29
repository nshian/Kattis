#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	unordered_set<string> words;
	string curr; cin >> curr;
	char last_char = curr[curr.length()-1];
	words.insert(curr);
	bool violated = false;
	for (int i = 1; i < N; i++) {
		string curr; cin >> curr;
		if (curr[0] != last_char || words.find(curr) != words.end()) {
			if (i % 2 == 0)
				cout << "Player 1 lost" << '\n';
			else
				cout << "Player 2 lost" << '\n';
			violated = true;
			break;
		}
		words.insert(curr);
		last_char = curr[curr.length() - 1];
	}
	if (!violated)
		cout << "Fair Game" << '\n';
}