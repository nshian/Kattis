/*  Matric Number: A0231053X
	Full Name: Ng Sihan, Ian
	Lab Group: 4
	TA: Ammar Fathin Sabili */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N; cin >> N;
	unordered_map<long long, unordered_map<string, string>> overall;
	long long nest_level = 0;
	unordered_map<string, vector<long long>> levels;
	for (int i = 0; i < N; i++) {
		string cmd; cin >> cmd;
		if (cmd == "DECLARE") {
			string var, type; cin >> var >> type;
			if (overall[nest_level].find(var) != overall[nest_level].end()) { //variable is found in the corresponding table
				cout << "MULTIPLE DECLARATION" << '\n';
				return 0;
			}
			else {
				overall[nest_level][var] = type;
				levels[var].push_back(nest_level);
			}
		}
		else if (cmd == "TYPEOF") {	
			string var; cin >> var;
			if (levels[var].empty())
				cout << "UNDECLARED" << '\n';
			else
				cout << overall[*(levels[var].rbegin())][var] << '\n';
		}
		else if (cmd == "{") { //increment level of nesting and initialise a table for it
			unordered_map<string, string> var_types;
			nest_level++;
			overall[nest_level] = var_types;
		}
		else if (cmd == "}") {
			for (auto var : overall[nest_level]) {
				levels[var.first].pop_back();
			}
			overall.erase(nest_level); //erase definitions from previous deeper level of nesting
			nest_level--;
		}
	}
}