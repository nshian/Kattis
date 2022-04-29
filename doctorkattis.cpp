#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
using namespace std;

struct patient {
	string name;
	int arrival;
	int level;
};

struct cmp {
	bool operator()(patient a, patient b) const {
		if (a.level > b.level)
			return true;
		if (a.level == b.level)
			return a.arrival < b.arrival;
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<patient, cmp> clinic;
	unordered_map<string, pair<int, int>> cats; //arrival + level
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int cmd; cin >> cmd;
		if (cmd == 0) {
			string name; int level; cin >> name >> level;
			patient curr; curr.name = name; curr.arrival = i; curr.level = level;
			clinic.insert(curr);
			cats[name] = make_pair(i, level);
		}
		else if (cmd == 1) {
			string name; cin >> name; int increment; cin >> increment;
			patient curr; curr.name = name; curr.arrival = cats[name].first; curr.level = cats[name].second;
			clinic.erase(curr);
			cats[name].second = curr.level + increment;
			curr.level = cats[name].second;
			clinic.insert(curr);
		}
		else if (cmd == 2) {
			string name; cin >> name;
			patient curr; curr.name = name; curr.arrival = cats[name].first; curr.level = cats[name].second;
			clinic.erase(curr);
			cats.erase(name);
		}
		else if (cmd == 3) {
			if (clinic.empty())
				cout << "The clinic is empty" << '\n';
			else
				cout << (*(clinic.begin())).name << '\n';
		}
	}
}