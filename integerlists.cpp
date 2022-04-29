#include <iostream>
#include <sstream>
#include <list>
#include <iterator>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test; cin >> test;
	string dummy; getline(cin, dummy); //newline char
	for (int i = 0; i < test; i++) {
		bool reverse = false;
		bool error = false;
		string program; getline(cin, program);
		int n; cin >> n;
		getline(cin, dummy); //newline char again
		string input; getline(cin, input);
		list<string> nums;
		istringstream ss(input);
		ss.ignore(); //ignore [
		for (int j = 0; j < n; j++) {
			string word;
			if (j == n - 1) 
				getline(ss, word, ']');
			else
				getline(ss, word, ',');
			nums.push_back(word);
		}
		for (auto& p : program) {
			if (p == 'R')
				reverse = !reverse;
			else if (p == 'D') {
				if (nums.empty()) {
					cout << "error" << '\n';
					error = true;
					break;
				}
				else {
					if (!reverse)
						nums.pop_front();
					else
						nums.pop_back();
				}
			}
		}
		if (!error) {
			cout << '[';
			if (!reverse) {
				for (auto itr = nums.begin(); itr != nums.end(); itr++) {
					cout << *itr;
					if (itr != prev(nums.end(), 1))
						cout << ',';
				}
			}
			else {
				stack<string> reversed;
				for (auto itr = nums.begin(); itr != nums.end(); itr++) {
					reversed.push(*itr);
				}
				while (!reversed.empty()) {
					string curr = reversed.top();
					reversed.pop();
					cout << curr;
					if (!reversed.empty())
						cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}
}