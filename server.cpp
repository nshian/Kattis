#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, T; cin >> n >> T;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int curr; cin >> curr;
		if (T >= curr) {
			count++;
			T -= curr;
		}
		else
			break;
	}
	cout << count << '\n';
}