#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

struct toy {
	string name;
	long long count;
};

struct cmp {
	bool operator()(toy a, toy b) const {
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

	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		unordered_map<string, long long> freq;
		int N; cin >> N;
		for (int j = 0; j < N; j++) {
			string toy; cin >> toy; long long count; cin >> count;
			freq[toy] += count;
		}
		cout << freq.size() << '\n';
		set<toy, cmp> toys;
		for (auto& f : freq) {
			toy curr; curr.name = f.first; curr.count = f.second;
			toys.insert(curr);
		}
		for (auto& t : toys) {
			cout << t.name << " " << t.count << '\n';
		}
	}
}