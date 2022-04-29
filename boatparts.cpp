#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int P, N; cin >> P >> N;
	unordered_set<string> parts;
	int last_day = 1;
	int new_items = 0;
	for (int i = 1; i <= N; i++) {
		string part; cin >> part;
		if (parts.find(part) == parts.end()) { //part not yet replaced
			parts.insert(part);
			last_day = i;
			new_items++;
		}
	}
	if (new_items == P)
		cout << last_day << '\n';
	else
		cout << "paradox avoided" << '\n';
}