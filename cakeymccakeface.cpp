#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    vector<int> entry; vector<int> exit;
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
        int curr; cin >> curr;
        entry.push_back(curr);
    }
    for (int i = 0; i < M; i++) {
        int curr; cin >> curr;
        exit.push_back(curr);
    }
    for (auto e : entry) {
		for (auto ex : exit) {
			if(ex-e > 0)
				freq[ex - e]++;
		}
    }
    int max_count = -1;
    int max_value = 0;
    for (auto f : freq) {
        if (f.second > max_count) {
            max_count = f.second;
            max_value = f.first;
        }
        if (f.second == max_count)
            max_value = min(max_value, f.first);
    }
    cout << max_value << '\n';
}