#include <iostream>

using namespace std;
int main() {
	int N, P; cin >> N >> P;
	long long total = 0;
	long long max = 0;
	for (long long i = 0; i < N; i++) {
		long long curr; cin >> curr; total += curr;
		if (curr > max)
			max = curr;
	}
	for (long long i = 1; i < N; i++) {
		int dummy; cin >> dummy;
	}
	cout << (P - 1) * max + total;
}