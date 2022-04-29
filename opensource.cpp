#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

struct Project {
	string name;
	long long count;
};

struct cmp {
	bool operator()(Project a, Project b) const {
		if (a.count > b.count)
			return true;
		if (a.count == b.count)
			return a.name < b.name;
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	unordered_map<string, long long> freq;
	unordered_map<string, pair<bool, string>> signups;
	set<Project, cmp> projects;
	string project = "";
	string id = "";
	while (getline(cin, line)) {
		if (line == "0" || line == "1") { //end of test case
			for (auto f : freq) {
				Project curr; curr.name = f.first; curr.count = f.second;
				projects.insert(curr);
			}
			for (auto p : projects) {
				cout << p.name << " " << p.count << '\n';
			}
			if (line == "0")
				return 0;
			else {
				freq.clear();
				signups.clear();
				projects.clear();
			}
		}
		else {
			if (isupper(line[0])) { //project name
				project = line;
				freq[project] = 0;
			}
			else { //student ID
				id = line;
				if (signups.find(id) == signups.end()) { //student has not registered before
					freq[project]++;
					signups[id] = make_pair(false, project);
				}
				else {
					if (signups[id].second != project) {
						if (!(signups[id].first)) {
							signups[id].first = true;
							freq[signups[id].second]--;
						}
					}
				}
			}
		}
	}
}