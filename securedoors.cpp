#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_set<string> names;
	for (int i = 0; i < n; i++) {
		string cmd, name; cin >> cmd >> name;
		if (cmd == "entry") {
			if (names.find(name) == names.end()) {
				names.insert(name);
				cout << name << " " << "entered\n";
			}
			else
				cout << name << " " << "entered (ANOMALY)\n";
		}
		else {
			if (names.find(name) == names.end())
				cout << name << " " << "exited (ANOMALY)\n";
			else {
				names.erase(name);
				cout << name << " " << "exited\n";
			}
		}
	}
}