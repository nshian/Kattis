/*  Matric Number: A0231053X
	Full Name: Ng Sihan, Ian
	Lab Group: 4
	TA: Ammar Fathin Sabili */

#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	map<int, pair<int, int>> trains; //information regarding M train lines
	map <int, vector<pair<int, int>>> destinations; //information regarding each city and its destinations + its corresponding train line number
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		trains[i] = make_pair(a, b);
		destinations[a].push_back(make_pair(b, i));			
		destinations[b].push_back(make_pair(a, i));
	}
	bool route_possible = true;
	vector<int> sequence;
	for (int i = 1; i <= N; i++) {
		bool train_possible = false;
		for (auto d : destinations[i]) {
			if (i == N) {
				if (d.first == 1){
					train_possible = true;
					sequence.push_back(d.second);
					break;
				}
			}
			else {
				if (d.first == i + 1) {
					train_possible = true;
					sequence.push_back(d.second);
					break;
				}
			}
		}
		if (train_possible == false) {
			route_possible = false;
			break;
		}
	}
	if (!route_possible) {
		cout << "impossible" << '\n';
	}
	else {
		for (auto train : sequence) {
			cout << train << '\n';
		}
	}
}