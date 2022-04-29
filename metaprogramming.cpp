#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> dict;
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		string cmd; ss >> cmd;
		if (cmd == "define") {
			string value_str; ss >> value_str; int value_int = stoi(value_str);
			string word; ss >> word;
			dict[word] = value_int;
		}
		else {
			string a, opr, b; ss >> a >> opr >> b;
			if (dict.find(a) == dict.end() || dict.find(b) == dict.end())
				cout << "undefined" << '\n';
			else if (opr == "<") {
				if (dict[a] < dict[b])
					cout << "true" << '\n';
				else
					cout << "false" << '\n';
			}
			else if (opr == "=") {
				if (dict[a] == dict[b])
					cout << "true" << '\n';
				else
					cout << "false" << '\n';
			}
			else if (opr == ">") {
				if (dict[a] > dict[b])
					cout << "true" << '\n';
				else
					cout << "false" << '\n';
			}
		}
	}
}