#include <iostream>
#include <cmath>

int main() {
	bool stopped = false;
	while (!stopped) {
		int n; std::cin >> n;
		if (n == 0) {
			stopped = true;
		}
		else {
			double rowtotal = 0;
			double coltotal = 0;
			for (int i = 0; i < n; i += 1) {
				int row, col; std::cin >> row >> col;
				rowtotal += row;
				coltotal += col;
			}
			rowtotal /= n;
			coltotal /= n;
			int row = (rowtotal - floor(rowtotal) > 0.50) ? ceil(rowtotal) : floor(rowtotal);
			int col = (coltotal - floor(coltotal) > 0.50) ? ceil(coltotal) : floor(coltotal);
			std::cout << row << " " << col << '\n';
		}
	}
}