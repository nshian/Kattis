#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	map<string, double> trees;
	string line;
	int count = 0;
	while (getline(cin, line)) {
		trees[line]++;
		count++;
	}
	for (auto t : trees) {
		cout << t.first << " " << setprecision(8) << (double)t.second / count * 100.0 << '\n';
	}
}