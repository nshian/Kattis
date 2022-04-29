#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T; string dummy; getline(cin, dummy);
	for (int i = 0; i < T; i++) {
		string line; getline(cin, line);
		list<char> input;
		auto itr = input.end();
		for (auto c : line) {
			if (c == '[')
				itr = input.begin();
			else if (c == ']')
				itr = input.end();
			else if (c == '<') {
				if (!input.empty()) {
					if (itr != input.begin()) {
						itr--;
						itr = input.erase(itr);
					}
				}
			}
			else
				input.insert(itr, c);
		}
		for (auto c : input)
			cout << c;
		cout << '\n';
	}
}