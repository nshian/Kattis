#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
	vi p, rank, setSize;
	//int numSets;
public:
	UnionFind(int N) {
		p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
		rank.assign(N, 0);
		setSize.assign(N, 1);
		//numSets = N;
	}

	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

	//int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }

	void unionSet(int i, int j) {
		if (isSameSet(i, j)) return;
		int x = findSet(i), y = findSet(j);
		if (rank[x] > rank[y]) swap(x, y);
		p[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
		setSize[y] += setSize[x];
		//--numSets;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	UnionFind connections(2*n);
	unordered_map<string, int> buildings;
	for (int i = 0; i < n; i++) {
		string b1, b2; cin >> b1 >> b2;
		if (buildings.find(b1) == buildings.end())
			buildings[b1] = buildings.size();
		if (buildings.find(b2) == buildings.end())
			buildings[b2] = buildings.size();
		connections.unionSet(buildings[b1], buildings[b2]);
		cout << connections.sizeOfSet(buildings[b1]) << '\n';
	}
}