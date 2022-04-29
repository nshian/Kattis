#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	unordered_map<int, pair<int, int>> languages;
	for (int i = 0; i < n; i++) {
		int curr; cin >> curr;
		if (languages.find(curr) == languages.end()) //this is a new language
			languages[curr] = make_pair(i, n);
		else {
			if (i - languages[curr].first < languages[curr].second) //distance is now less
				languages[curr] = make_pair(i, i - languages[curr].first);
			else //update curr idx which is latest occurrence of the language
				languages[curr].first = i;
		}
	}
	int min_distance = n; 
	for (auto l : languages)
		if ((l.second).second < min_distance)
				min_distance = (l.second).second;
	if (languages.size() == n) //all are unique languages
		cout << n << '\n';
	else
		cout << min_distance << '\n';
}