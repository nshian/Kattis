#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

struct cmp {
	bool operator()(pair<string, string> a, pair<string, string> b) const {
		if (a.second < b.second)
			return true;
		if (a.second == b.second)
			return a.first < b.first;
		return false;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, int> firstname;
	set<pair<string, string>, cmp> names;
	string name;
	while (getline(cin, name)) {
		stringstream ss(name);
		string first, last; ss >> first >> last;
		pair<string, string> fullname; fullname.first = first; fullname.second = last;
		names.insert(fullname);
		firstname[first]++;
	}
	for (auto n : names) {
		if (firstname[n.first] != 1)
			cout << n.first << " " << n.second << '\n';
		else
			cout << n.first << '\n';
	}
}