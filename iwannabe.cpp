#include <iostream>
#include <unordered_set>
#include <set>
#include <iterator>
using namespace std;


struct Pokenom {
	int id;
	long long attack;
	long long defense;
	long long health;
};

struct compare_attack {
	bool operator()(Pokenom a, Pokenom b) const {
		return a.attack > b.attack;
	}
};

struct compare_defense {
	bool operator()(Pokenom a, Pokenom b) const {
		return a.defense > b.defense;
	}
};

struct compare_health {
	bool operator()(Pokenom a, Pokenom b) const {
		return a.health > b.health;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;
	set<Pokenom, compare_attack> attack;
	set<Pokenom, compare_defense> defense;
	set<Pokenom, compare_health> health;
	unordered_set<int> final;
	for (int i = 0; i < N; i++) {
		Pokenom curr; cin >> curr.attack >> curr.defense >> curr.health;
		curr.id = i;
		attack.insert(curr); defense.insert(curr); health.insert(curr);
	}
	for (int i = 0; i < K; i++) {
		final.insert((*(next(attack.begin(), i))).id);
		final.insert((*(next(defense.begin(), i))).id);
		final.insert((*(next(health.begin(), i))).id);
	}
	cout << final.size() << '\n';
}