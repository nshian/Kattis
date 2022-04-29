/*  Matric Number: A0231053X
	Full Name: Ng Sihan, Ian
	Lab Group: 4
	TA: Ammar Fathin Sabili */

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

void bfs(int s, vector<int>& hops, vector<vector<long long>>& AL) { // s is the starting/source vertex
	queue<int> q;
	q.push(s);
	//visited[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto& v : AL[u])
			if (hops[v] == 1e9) {
				hops[v] = hops[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> blocks;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int curr; cin >> curr;
		blocks.push_back(curr);
	}
	stack<int> comp;
	stack<int> idxs;
	vector<vector<long long>> adj_list(N+1);
	for (int i = 0; i < N; i++) {
		if (comp.empty()) {
			comp.push(blocks[i]);
			idxs.push(i);
		}
		else {
			while (!comp.empty()) {
				if (blocks[i] < comp.top()) { //current block is shorter
					adj_list[idxs.top()].push_back(i);
					comp.push(blocks[i]);
					idxs.push(i);
					break;
				}
				else { //current block is >= left curr nearest highest
					comp.pop();
					idxs.pop();
				}
			}
			if (comp.empty()) { //we popped everything ie the current block is the highest
				comp.push(blocks[i]);
				idxs.push(i);
			}
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (comp.empty()) {
			comp.push(blocks[i]);
			idxs.push(i);
		}
		else {
			while (!comp.empty()) {
				if (blocks[i] < comp.top()) { //current block is shorter
					adj_list[idxs.top()].push_back(i);
					comp.push(blocks[i]);
					idxs.push(i);
					break;
				}
				else { //current block is >= left curr nearest highest
					comp.pop();
					idxs.pop();
				}
			}
			if (comp.empty()) { //we popped everything ie the current block is the highest
				comp.push(blocks[i]);
				idxs.push(i);
			}
		}
	}
	vector<int> highestblocks;
	int highest = 0;
	for (int i = 0; i < N; i++) {
		if (blocks[i] > highest)
			highest = blocks[i];
	}
	for (int i = 0; i < N; i++) {
		if (blocks[i] == highest)
			highestblocks.push_back(i);
	}
	for (int i = 0; i < highestblocks.size(); i++) {
		adj_list[N].push_back(highestblocks[i]);
	}
	vector<int> hops(N + 1, 1e9);
	hops[N] = -1;
	bfs(N, hops, adj_list);
	for (int i = 0; i < N; i++)
		cout << hops[i] << " ";
}