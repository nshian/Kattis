#include <iostream>
#include <stack>

int main(){
	std::stack<int> cards;
	int n; std::cin >> n;
	for (int i = 0; i < n; i++) {
		int curr; std::cin >> curr;
		if (cards.empty()) {
			cards.push(curr);
		}
		else {
			if ((curr + cards.top()) % 2 == 0) {
				cards.pop();
			}
			else {
				cards.push(curr);
			}
		}
	}
	std::cout << cards.size() << '\n';
}