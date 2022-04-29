#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	list<string> queue;
	for (int i = 0; i < N; i++) {
		string curr; cin >> curr; queue.push_back(curr);
	}
	int C; cin >> C;
	for (int i = 0; i < C; i++) {
		string cmd; cin >> cmd;
		if (cmd == "cut") {
			string a, b; cin >> a >> b;
			auto itr = find(queue.begin(), queue.end(), b);
			queue.insert(itr, a);
		}
		else if (cmd == "leave") {
			string a; cin >> a;
			auto itr = find(queue.begin(), queue.end(), a);
			queue.erase(itr);
		}
	}
	for (auto person : queue)
		cout << person << '\n';
}