#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	map<string, vector<string>> categories;
	map<string, long long> freq;
	for (int i = 0; i < N; i++) {
		string category; cin >> category;
		freq[category] = 0;
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			string keyword; cin >> keyword;
			categories[keyword].push_back(category);
		}
	}
	string word;
	long long max = 0;
	while (cin >> word) {
		if (categories.find(word) != categories.end()) {
			for (auto s : categories[word]) {
				freq[s]++;
				if (freq[s] > max)
					max = freq[s];
			}
		}
	}
	for (auto f : freq) {
		if (f.second == max)
			cout << f.first << '\n';
	}
}