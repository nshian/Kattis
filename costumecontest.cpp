#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	map<string, int> types;
	for (int i = 0; i < N; i++) {
		string type; cin >> type;
		if (types.find(type) == types.end())
			types[type] = 1;
		else
			types[type]++;
	}
	int min_count = 1000;
	for (auto t : types) {
		if (t.second < min_count)
			min_count = t.second;
	}
	for (auto t : types) {
		if (t.second == min_count)
			cout << t.first << '\n';
	}
}