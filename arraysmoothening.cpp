#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	priority_queue<int> pq;
	unordered_map<int, int> freq;
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int curr; cin >> curr;
		if (freq.find(curr) == freq.end())
			freq[curr] = 1;
		else
			freq[curr]++;
	}
	for (auto& f : freq)
		pq.push(f.second);
	for (int i = 0; i < K; i++) {
		int top = pq.top();
		pq.pop();
		top--;
		pq.push(top);
	}
	int max = pq.top();
	cout << max << '\n';
}