#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L; cin >> L;
	cin.ignore();
	stack<char> brackets;
	string line;
	getline(cin, line);
	for (int i = 0; i < line.size(); i++) {
		char curr = line[i];
		if (curr == '(' || curr == '[' || curr == '{')
			brackets.push(curr);
		else {
			if (curr != ' ') {
				if (!brackets.empty()) {
					if (curr == ')') {
						if (brackets.top() != '(') {
							cout << curr << ' ' << i << '\n';
							return 0;
						}
						brackets.pop();
					}
					else if (curr == ']') {
						if (brackets.top() != '[') {
							cout << curr << ' ' << i << '\n';
							return 0;
						}
						brackets.pop();
					}
					else if (curr == '}') {
						if (brackets.top() != '{') {
							cout << curr << ' ' << i << '\n';
							return 0;
						}
						brackets.pop();
					}
				}
				else {
					cout << curr << ' ' << i << '\n';
					return 0;
				}
			}
		}
	}
	cout << "ok so far" << '\n';
}