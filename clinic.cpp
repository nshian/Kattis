#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
typedef long long ll;

struct patient {
	string name;
	ll priority;
};

struct cmp {
	bool operator()(patient a, patient b) const{
		if (a.priority > b.priority)
			return true;
		if (a.priority == b.priority)
			return a.name < b.name;
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;
	set<patient, cmp> queue;
	unordered_map<string, ll> values;
	for (int i = 0; i < N; i++) {
		int Q; cin >> Q;
		if (Q == 1) {
			ll T; cin >> T;
			string name; cin >> name;
			ll S; cin >> S;
			patient curr; curr.name = name; curr.priority = S - (K * T);
			queue.insert(curr);
			values[name] = curr.priority;
		}
		else if (Q == 2) {
			ll T; cin >> T;
			if (queue.empty())
				cout << "doctor takes a break" << '\n';
			else {
				auto top = queue.begin();
				cout << (*(top)).name << '\n';
				queue.erase(top);
			}
		}
		else {
			ll T; cin >> T;
			string name; cin >> name;
			patient curr; curr.name = name; curr.priority = values[name];
			if (queue.find(curr) != queue.end())
				queue.erase(curr);
		}
	}
}