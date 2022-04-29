#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
private:
	vector<int> p, rank, setSize;
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
	UnionFind collection(2 * n); //initialise nodes
	unordered_map<string, int> buildings;
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		if (buildings.find(a) == buildings.end())
			buildings[a] = buildings.size();
		if (buildings.find(b) == buildings.end())
			buildings[b] = buildings.size();
		collection.unionSet(buildings[a], buildings[b]);
		cout << collection.sizeOfSet(buildings[a]) << '\n';
	}
}