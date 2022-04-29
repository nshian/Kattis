#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q; cin >> N >> Q;
    unordered_map<int, int> freq;
    set<int> problems;
    for (int i = 0; i < N; i++) {
        int curr; cin >> curr;
        if (freq.find(curr) == freq.end())
            freq[curr] = 1;
        else
            freq[curr]++;
        problems.insert(curr);
    }
    for (int i = 0; i < Q; i++) {
        int T, D; cin >> T >> D;
        if (problems.empty())
            cout << -1 << '\n';
        else {
            if (T == 1) {
                auto itr = problems.upper_bound(D);
                if (itr == problems.end())
                    cout << -1 << '\n';
                else {
                    int num = *itr;
                    cout << num << '\n';
                    freq[num]--;
                    if (freq[num] == 0)
                        problems.erase(num);
                }
            }
            else {
                if (D < *problems.begin())
                    cout << -1 << '\n';
                else {
                    auto itr = problems.upper_bound(D);
                    itr--;
                    int num = *itr;
                    cout << num << '\n';
                    freq[num]--;
                    if (freq[num] == 0)
                        problems.erase(num);
                }
            }
        }
    }
}