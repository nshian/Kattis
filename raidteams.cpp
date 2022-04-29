#include <iostream>
#include <set>
using namespace std;

struct raider {
	string name;
	int first;
	int second;
	int third;
};

struct cmp_first {
	bool operator()(raider a, raider b) const{
		if (a.first > b.first)
			return true;
		if (a.first == b.first)
			return a.name < b.name;
		return false;
	}
};

struct cmp_second {
	bool operator()(raider a, raider b) const {
		if (a.second > b.second)
			return true;
		if (a.second == b.second)
			return a.name < b.name;
		return false;
	}
};

struct cmp_third {
	bool operator()(raider a, raider b) const {
		if (a.third > b.third)
			return true;
		if (a.third == b.third)
			return a.name < b.name;
		return false;
	}
};

struct cmp {
	bool operator()(raider a, raider b) const {
		return a.name < b.name;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<raider, cmp_first> firstskill;
	set<raider, cmp_second> secondskill;
	set<raider, cmp_third> thirdskill;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		raider curr; cin >> curr.name >> curr.first >> curr.second >> curr.third;
		firstskill.insert(curr);
		secondskill.insert(curr);
		thirdskill.insert(curr);
	}
	for (int i = 0; i < N / 3; i++) {
		set<raider, cmp> sorted;
		sorted.insert(*(firstskill.begin())); secondskill.erase(*(firstskill.begin())); thirdskill.erase(*(firstskill.begin())); firstskill.erase(*(firstskill.begin()));
		sorted.insert(*(secondskill.begin())); firstskill.erase(*(secondskill.begin())); thirdskill.erase(*(secondskill.begin())); secondskill.erase(*(secondskill.begin()));
		sorted.insert(*(thirdskill.begin())); firstskill.erase(*(thirdskill.begin())); secondskill.erase(*(thirdskill.begin())); thirdskill.erase(*(thirdskill.begin()));
		for (auto r : sorted)
			cout << r.name << " ";
		cout << '\n';
	}
}