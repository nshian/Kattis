#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	while (cin >> n) {
		if (n == 0)
			return 0;
		else {
			string line; getline(cin, line);
			map<string, set<string>> report;
			for (int i = 0; i < n; i++) {
				getline(cin, line);
				stringstream ss(line);
				string name; ss >> name;
				string item;
				while (ss >> item) {
					report[item].insert(name);
				}
			}
			for (auto& r : report) {
				cout << r.first;
				for (auto& name : r.second)
					cout << " " << name;
				cout << '\n';
			}
			cout << '\n';
		}
	}
}