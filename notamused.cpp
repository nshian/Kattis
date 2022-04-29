#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	int day = 0;
	unordered_map<string, int> times;
	map<string, double> bills;
	while (cin >> word) {
		if (word == "OPEN")
			day++;
		else if (word == "ENTER") {
			string name; int time; cin >> name >> time;
			times[name] = time;
		}
		else if (word == "EXIT") {
			string name; int time; cin >> name >> time;
			int difference = time - times[name];
			bills[name] += difference * 0.10;
		}
		else {
			cout << "Day " << day << '\n';
			for (auto& b : bills)
				cout << b.first << " " << "$" << fixed << setprecision(2) << b.second << '\n';
			times.clear();
			bills.clear();
			cout << '\n';
		}
	}
}