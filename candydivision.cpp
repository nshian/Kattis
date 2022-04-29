#include <iostream>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long N; cin >> N;
	long long root = sqrt(N);
	set<long long> friends;
	for (long long i = 1; i <= root; i++) {
		if (N % i == 0) {
			friends.insert(i - 1);
			friends.insert(N / i - 1);
		}
	}
	for (auto f : friends)
		cout << f << " ";
}