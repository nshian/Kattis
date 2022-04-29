#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	unordered_map<string, int> frequency;
	int max = 1;
	string max_combination = "";
	for (int i = 0; i < n; i++) {
		vector<string> courses;
		for (int j = 0; j < 5; j++) {
			string course; cin >> course;
			courses.push_back(course);
		}
		sort(courses.begin(), courses.end());
		string combination = "";
		for (string c : courses)
			combination += c;
		if (frequency.find(combination) == frequency.end()) //combination not found
			frequency[combination] = 1;
		else {
			frequency[combination]++;
			if (frequency[combination] > max) {
				max = frequency[combination];
			}
		}
	}
	int total = 0;
	for (auto comb : frequency) {
		if (comb.second == max)
			total += comb.second;
	}
	cout << total << '\n';
}