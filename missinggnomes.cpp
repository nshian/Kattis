#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	set<int> missing;
	for (int i = 0; i < n; i++)
		missing.insert(i+1);
	int m; cin >> m;
	vector<int> gnomes;
	for (int i = 0; i < m; i++) {
		int curr; cin >> curr;
		gnomes.push_back(curr);
		missing.erase(curr);
	}
	int idx = 0;
	while (idx < gnomes.size() && !missing.empty()) {
		int curr = gnomes[idx];
		if (curr > *missing.begin()) {
			gnomes.insert(gnomes.begin() + idx, *missing.begin());
			missing.erase(missing.begin());
			idx++;
		}
		else {
			if (idx == gnomes.size() - 1) {
					gnomes.push_back(*missing.begin());
					missing.erase(missing.begin());
			}
			idx++;
		}
	}
	for (auto& g : gnomes)
		cout << g << '\n';
}