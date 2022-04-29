#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q; cin >> N >> Q;
	unordered_map<int, int> wealths;
	int universal = 0;
	for (int i = 0; i < Q; i++) {
		string cmd; cin >> cmd;
		if (cmd == "SET") {
			int person, wealth; cin >> person >> wealth;
			wealths[person] = wealth;
		}
		else if (cmd == "PRINT") {
			int person; cin >> person;
			if (wealths.find(person) == wealths.end())
				cout << universal << '\n';
			else
				cout << wealths[person] << '\n';
		}
		else {
			cin >> universal;
			wealths.clear();
		}
	}
}