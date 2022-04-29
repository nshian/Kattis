/*  Matric Number: A0231053X
	Full Name: Ng Sihan, Ian
	Lab Group: 4
	TA: Ammar Fathin Sabili */

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<pll> vii;

const ll INF = 1e16; //big but not big enough to overflow

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int V,E,C,K,M; cin >> V >> E >> C >> K >> M;
	vector<vii> AL(V, vii());
	for (int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		AL[u-1].emplace_back(v-1, w);
		AL[v-1].emplace_back(u-1, w);
	}
	vi dist(V, INF); dist[0] = 0;
	multiset<pll> pq;
	for (int u = 0; u < V; u++)
		pq.insert({ dist[u], u });
	  // sort the pairs by non-decreasing distance from s
	while (!pq.empty()) {                          // main loop
		auto [d, u] = *pq.begin();                   // shortest unvisited u
		pq.erase(pq.begin());
		for (auto& [v, w] : AL[u]) {                 // all edges from u
			if (dist[u] + w >= dist[v]) continue;        // not improving, skip
			pq.erase(pq.find({ dist[v], v }));           // erase old pair
			dist[v] = dist[u] + w;                       // relax operation
			pq.insert({ dist[v], v });                   // enqueue better pair
		}
	}
	int available = 0;
	vector<long long> reachabledist;
	for (int i = 0; i < C; i++) {
		int f; cin >> f;
		if (dist[f-1] < INF) {
			available++;
			reachabledist.push_back(dist[f-1]);
		}
	}
	if (available < K && available < M)
		cout << -1 << '\n';
	else { //always possible to pick a fruit
		sort(reachabledist.begin(), reachabledist.end());
		if (K <= M)
			cout << 2 * reachabledist[K - 1] << '\n';
		else
			cout << 2 * reachabledist[M - 1] << '\n';
	}
}