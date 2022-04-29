//secret string: PL1_H3LL00
#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q; cin >> N >> Q;
	unordered_map<string, string> couples;
	list<string> congaline;
	//unordered_map<string, int> idxs;
	for (int i = 0; i < N; i++) {
		string a, b; cin >> a >> b;
		couples[a] = b;
		couples[b] = a;
		congaline.push_back(a);
		congaline.push_back(b);
	}
	auto itr = congaline.begin();
	string dummy; getline(cin, dummy);
	for (int i = 0; i < Q; i++) {
		char cmd; cin >> cmd;
		if (cmd == 'F')
			itr--;
		else if (cmd == 'B')
			itr++;
		else if (cmd == 'R') {
			if (itr == prev(congaline.end(), 1))
				itr = congaline.begin();
			else {
				string person; person = *itr;
				itr = congaline.erase(itr); //passed to person behind
				congaline.push_back(person);
			}
		}
		else if (cmd == 'P') {
			string person; person = *itr;
			cout << couples[person] << '\n';
		}
		else { //cmd == 'C'
			string person; person = *itr;
			string partner = couples[person];
			if (itr == prev(congaline.end(), 1)) {
				congaline.erase(itr);
				itr = congaline.begin();
			}
			else {
				itr = congaline.erase(itr);
			}
			for (auto it = congaline.begin(); it != congaline.end(); it++) {
				if (*(it) == partner) { //found partner, now put person behind partner
					if (it == prev(congaline.end(), 1))
						congaline.push_back(person);
					else {
						it++;
						congaline.insert(it, person);
					}
					break;
				}
			}
		}
	}
	cout << '\n';
	for (auto& person : congaline)
		cout << person << '\n';
}