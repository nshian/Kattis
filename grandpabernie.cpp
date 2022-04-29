#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	unordered_map<string, vector<int>> trips;
	for (int i = 0; i < n; i++) {
		string country; int year; cin >> country >> year;
		trips[country].push_back(year);
	}
	for (auto& trip : trips) {
		sort(trip.second.begin(), trip.second.end());
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string country; int k; cin >> country >> k;
		cout << (trips[country])[k - 1] << '\n';
	}
}