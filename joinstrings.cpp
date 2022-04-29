#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<string> words;
    vector<list<int>> idxs;
    for (int i = 0; i < N; i++) {
        string curr; cin >> curr;
        words.push_back(curr);
        list<int> new_list;
        new_list.push_back(i);
        idxs.push_back(new_list);
    }
    int final_idx = 0;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        idxs[a - 1].splice(idxs[a - 1].end(), idxs[b - 1]);
        final_idx = a - 1;
    }
    for (int& idx : idxs[final_idx])
        cout << words[idx];
}