#include <iostream>
#include <vector>
using namespace std;

void dfs(int curr, vector<vector<int>>& AL, vector<bool>& visited) { //must have & because pass by reference is necessary to amend visited vector 
	visited[curr] = true;
	for (auto& node : AL[curr]) {
		if (!visited[node])
			dfs(node, AL, visited);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		vector<vector<int>> AL;
		int m; cin >> m;
		int r; cin >> r;
		AL.assign(m, vector<int>());
		vector<bool> visited;
		visited.assign(m, false);
		for (int j = 0; j < r; j++) {
			int source, destination; cin >> source >> destination;
			AL[source].push_back(destination);
			AL[destination].push_back(source);
		}
		int numofCC = 0;
		for (int k = 0; k < m; k++) {
			if (!visited[k]) {
				dfs(k, AL, visited);
				numofCC++;
			}
		}
		cout << numofCC - 1 << '\n';
	}
}