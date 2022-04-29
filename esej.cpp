#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<string> words;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int A, B; cin >> A >> B;
	while (words.size() < A || words.size() < B / 2) {
		string word = "";
		int length = (rand() % 14) + 1;
		for (int i = 0; i < length; i++) {
			char letter = alphabet[rand() % 26];
			word += letter;
		}
		words.insert(word);
	}
	for (auto word : words)
		cout << word << " ";
}