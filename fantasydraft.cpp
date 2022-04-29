#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k; cin >> n >> k;
	vector<list<string>> preferences(n); //vector of owners' preferences
	unordered_map<string, int> nametorank; //table of players and their rank
	map<int, string> rankings; //map of each player's rankings
	map<int, vector<string>> drafts; //final map of teams
	for (int i = 0; i < n; i++) {
		int q; cin >> q;
		for (int j = 0; j < q; j++) {
			string player; cin >> player;
			preferences[i].push_back(player);
		}
	}
	int p; cin >> p;
	for (int i = 0; i < p; i++) {
		string player; cin >> player;
		nametorank[player] = i;
		rankings[i] = player;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			bool preferred = false;
			while (!preferences[j].empty() && !preferred) {
				string player = preferences[j].front();
				int rank = nametorank[player];
				preferences[j].pop_front(); //regardless of whether this player is available, we will still pop
				if (rankings.find(rank) != rankings.end()) { //this preferred player is still available
					drafts[j].push_back(player);
					preferred = true;
					rankings.erase(rank); //remove player from pool
				}
			}
			if (!preferred) { //failed to secure preferred player, choose from pool
				string player = rankings.begin()->second;
				drafts[j].push_back(player);
				rankings.erase(rankings.begin()->first);
			}
		}
	}
	for (auto d : drafts) {
		for (auto player : d.second)
			cout << player << " ";
		cout << '\n';
	}
}