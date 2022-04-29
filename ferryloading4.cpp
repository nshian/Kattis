#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c; cin >> c;
	for (int i = 0; i < c; i++) {
		int l, m; cin >> l >> m;
		queue<double> left;
		queue<double> right;
		int count = 0;
		double capacity = 0.0;
		for (int j = 0; j < m; j++) {
			double length; cin >> length; string end; cin >> end;
			length /= 100;
			if (end == "left")
				left.push(length);
			else
				right.push(length);
		}
		while (!left.empty() || !right.empty()) {
			if (left.empty() && !right.empty())
				count++;
			if (!left.empty()) {
				count++;
				while (capacity < l) {
					if (!left.empty()) {
						if (capacity + left.front() <= l) {
							capacity += left.front();
							left.pop();
						}
						else
							break;
					}
					else
						break;
				}
			}
			capacity = 0.0; //reset capacity of boat
			if (right.empty() && !left.empty())
				count++;
			if (!right.empty()) {
				count++;
				while (capacity < l) {
					if (!right.empty()) {
						if (capacity + right.front() <= l) {
							capacity += right.front();
							right.pop();
						}
						else
							break;
					}
					else
						break;
				}
			}
			capacity = 0.0; //reset capacity of boat
		}
		cout << count << '\n';
	}
}