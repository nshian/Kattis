#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string curr; cin >> curr;
		stack<char> adventure;
		bool failed = false;
		for (int j = 0; j < curr.length(); j++) {
			if (curr[j] == '$' || curr[j] == '|' || curr[j] == '*')
				adventure.push(curr[j]);
			else if (curr[j] == 't') {
				if (adventure.empty()) {
					failed = true;
					break;
				}
				else if (adventure.top() == '|')
					adventure.pop();
				else {
					failed = true;
					break;
				}
			}
			else if (curr[j] == 'j') {
				if (adventure.empty()) {
					failed = true;
					break;
				}
				else if (adventure.top() == '*')
					adventure.pop();
				else {
					failed = true;
					break;
				}
			}
			else if (curr[j] == 'b') {
				if (adventure.empty()) {
					failed = true;
					break;
				}
				else if (adventure.top() == '$')
					adventure.pop();
				else {
					failed = true;
					break;
				}
			}
		}
		if (!adventure.empty())
			failed = true;
		if (failed)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}