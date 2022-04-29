#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<string> keywords;
	int n; cin >> n; string dummy; getline(cin, dummy);
	for (int i = 0; i < n; i++) {
		string input; getline(cin, input);
		for (int j = 0; j < input.length(); j++) {
			if (isalpha(input[j])) {
				if (isupper(input[j]))
					input[j] = tolower(input[j]);
			}
			else if (input[j] == '-')
				input[j] = ' ';
		}
		keywords.insert(input);
	}
	cout << keywords.size() << '\n';
}