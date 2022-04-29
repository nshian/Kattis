#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

void dfs(string curr, unordered_map<string, vector<string>>& AL, unordered_set<string>& visited, stack<string>& reversed) { //must have & because pass by reference is necessary to amend visited vector + stack 
	visited.insert(curr);
	for (auto& node : AL[curr]) {
		if (visited.find(node) == visited.end())
			dfs(node, AL, visited, reversed);
	}
	reversed.push(curr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n; string dummy; getline(cin, dummy);
	unordered_map<string, vector<string>> AL;
	unordered_set<string> visited;
	stack<string> reversed;
	for (int i = 0; i < n; i++) {
		string rule; getline(cin, rule);
		stringstream ss(rule);
		string file; ss >> file; file.pop_back();
		string dep;
		while (ss >> dep)
			AL[dep].push_back(file);
	}
	string changed; getline(cin, changed);
	dfs(changed, AL, visited, reversed);
	while (!reversed.empty()) {
		cout << reversed.top() << '\n';
		reversed.pop();
	}
}