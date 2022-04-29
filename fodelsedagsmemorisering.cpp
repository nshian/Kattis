#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	set<string> names;
	map<pair<int, int>, pair<string,int>> birthdays;
	for (int i = 0; i < N; i++) {
		string name; cin >> name;
		int liking; cin >> liking;
		string date; cin >> date;
		int day = int(date[0] - '0') * 10 + int(date[1] - '0');
		int month = int(date[3] - '0') * 10 + int(date[4] - '0');
		auto birthday = make_pair(day, month);
		if (birthdays.find(birthday) != birthdays.end()) { //birthday already existent
			if (birthdays[birthday].second < liking) {
				string old_name = birthdays[birthday].first;
				birthdays[birthday].first = name;
				birthdays[birthday].second = liking;
				names.erase(old_name);
				names.insert(name);
			}
		}
		else {
			names.insert(name);
			birthdays[birthday] = make_pair(name, liking);
		}
	}
	cout << birthdays.size() << '\n';;
	for (auto name : names)
		cout << name << '\n';
}