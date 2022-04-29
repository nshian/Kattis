#include <iostream>
#include <stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> temp;
	stack<int> og;
	stack<int> aux;
	int n; cin >> n;
	int count = 0;
	for (int i = 0; i < 2 * n; i++) {
		int curr; cin >> curr;
		temp.push(curr);
	}
	for (int i = 0; i < 2 * n; i++) {
		og.push(temp.top());
		temp.pop();
	}
	while (!og.empty()) {
		count++;
		if (aux.empty()) {
			aux.push(og.top());
			og.pop();
		}
		else {
			if (og.top() == aux.top()) { //there is a match
				og.pop(); aux.pop();
			}
			else {
				aux.push(og.top());
				og.pop();
			}
		}
	}
	if (!aux.empty())
		cout << "impossible" << '\n';
	else
		cout << count << '\n';
}