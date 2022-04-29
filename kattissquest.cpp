#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	map<int, priority_queue<int>> quests;
	for (int i = 0; i < N; i++) {
		string cmd; cin >> cmd;
		if (cmd == "add") {
			int E, G; cin >> E >> G;
			quests[E].push(G);
		}
		else if (cmd == "query") {
			int X; cin >> X;
			long long gold = 0;
			while (X) {
				auto highest = quests.upper_bound(X);
				if (highest == quests.begin()) //X is too low, no suitable energy level task found
					break;
				else {
					highest--;
					gold += (highest->second).top();
					(highest->second).pop();
					X -= (highest->first);
					if ((highest->second).empty()) //erase because there are no more tasks of that energy level so we do not accidentally access it later on
						quests.erase(highest);
				}
			}
			cout << gold << '\n';
		}
	}
}