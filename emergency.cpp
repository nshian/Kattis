#include <iostream>
using namespace std;

int main() {
	long long n, k; cin >> n >> k;
	if (n / k <= 1) //no special edge formed
		cout << n - 1 << '\n';
	else
		cout << k + 1 + (n - 1) % k << '\n';
}