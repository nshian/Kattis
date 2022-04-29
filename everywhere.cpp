#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		unordered_set<string> countries;
		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			string city; cin >> city;
			countries.insert(city);
		}
		cout << countries.size() << '\n';
	}
}