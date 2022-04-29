#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	unordered_map<string, int> dictbyword;
	unordered_map<int, string> dictbynum;
	while (getline(cin, line)) {
		stringstream ss(line);
		string cmd; ss >> cmd;
		if (cmd == "clear") {
			dictbyword.clear();
			dictbynum.clear();
		}
		else if (cmd == "def") {
			string word, value_str; int value_int;
			ss >> word; ss >> value_str; value_int = stoi(value_str);
			if (dictbyword.find(word) != dictbyword.end()) { //wrd defined before
				dictbynum.erase(dictbyword[word]);
				dictbyword.erase(word);
			}
			dictbyword[word] = value_int;
			dictbynum[value_int] = word;
		}
		else if (cmd == "calc") {
			string word; ss >> word;
			bool error = false;
			int sum = 0;
			if (dictbyword.find(word) != dictbyword.end())
				sum += dictbyword[word]; //initialise sum
			else
				error = true;
			cout << word;
			while (ss >> word) {
				if (word == "+") {
					cout << " " << word;
					ss >> word; //read in next word
					if (dictbyword.find(word) == dictbyword.end()) //word was not defined
						error = true;
					else
						sum += dictbyword[word];
					cout << " " << word;
				}
				else if (word == "-") {
					cout << " " << word;
					ss >> word; //read in next word
					if (dictbyword.find(word) == dictbyword.end()) //word was not defined
						error = true;
					else
						sum -= dictbyword[word];
					cout << " " << word;
				}
				else { //word == "="
					cout << " " << word;
					if (dictbynum.find(sum) == dictbynum.end())
						error = true;
					if (error)
						cout << " " << "unknown" << '\n';
					else
						cout << " " << dictbynum[sum] << '\n';
				}
			}
		}
	}
}