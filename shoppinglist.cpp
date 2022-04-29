#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	map<string, int> freq;
	int num = 0;
	for (int i = 0; i < n; i++) {
		set<string> items;
		for (int j = 0; j < m; j++) {
			string item; cin >> item;
			items.insert(item);
		}
		for (auto& item : items) {
			if (freq.find(item) == freq.end())
				freq[item] = 1;
			else
				freq[item]++;
			if (freq[item] == n)
				num++;
		}
	}
	cout << num << '\n';
	for (auto& f : freq) {
		if (f.second == n)
			cout << f.first << '\n';
	}
}