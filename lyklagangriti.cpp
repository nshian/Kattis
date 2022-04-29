#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	list<char> password;
	auto itr = password.end();
	string line;
	getline(cin, line);
	for (auto& curr : line) {
		if (curr == 'L') {
			if (!password.empty())
				itr = prev(itr, 1);
		}
		else if (curr == 'R') {
			if (!password.empty())
				itr = next(itr, 1);
		}
		else if (curr == 'B') {
			itr = prev(itr, 1);
			itr = password.erase(itr);
		}
		else
			password.insert(itr, curr);
	}
	for (auto& p : password)
		cout << p;
}