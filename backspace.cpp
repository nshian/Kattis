#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input; getline(cin, input);
	list<char> intended;
	auto itr = intended.end();
	for (auto c : input) {
		if (c == '<') {
			itr--;
			itr = intended.erase(itr);
		}
		else
			intended.insert(itr, c);
	}
	for (auto c : intended)
		cout << c;
}