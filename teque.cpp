#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	deque<int> front, back;
	for (int i = 0; i < N; i++) {
		string cmd; cin >> cmd; int num; cin >> num;
		if (cmd == "push_back") {
			back.push_back(num);
			if (back.size() - front.size() > 1) {
				front.push_back(back.front());
				back.pop_front();
			}
		}
		else if (cmd == "push_front") {
			front.push_front(num);
			if (front.size() - back.size() > 1) {
				back.push_front(front.back());
				front.pop_back();
			}
		}
		else if (cmd == "push_middle") {
			if (front.size() < back.size()) {
					front.push_back(back.front());
					back.pop_front();
				}
			back.push_front(num);
		}
		else {
			if (num >= front.size())
				cout << back[num-front.size()] << '\n';
			else
				cout << front[num] << '\n';
		}
	}
}