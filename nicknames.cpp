/*  Matric Number: A0231053X
	Full Name: Ng Sihan, Ian
	Lab Group: 4
	TA: Ammar Fathin Sabili */

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	//std::unordered_map<char, std::vector<std::string>> names;
	std::unordered_map<std::string, int> names;
	int A; std::cin >> A;
	for (int i = 0; i < A; i++) {
		std::string curr = "";
		std::string name; std::cin >> name;
		for (int i = 0; i < name.size(); i++) {
			curr += name[i];
			names[curr]++;
		}
		//names[name[0]].push_back(name);
	}
	int B; std::cin >> B;
	for (int i = 0; i < B; i++) {
		std::string nickname; std::cin >> nickname;
		//char first = nickname[0];
		int total = 0;
		/*if (!names[first].empty()) {
			if (nickname.size() == 1) {
				total += names[first].size();
			}
			else {
				//bool found = true;
				for (auto name : names[first]) {
					if (nickname.size() <= name.size()) {
						//  for (int i = 1; i < nickname.size(); i++) {
						//      if (nickname[i] != name[i]) {
						//          found = false;
						//          break;
						//      }
						//  }
						//  if (found) {
						//      total++;
						//  }
						//}
						auto idx = std::mismatch(nickname.begin(), nickname.end(), name.begin());
						if (idx.first == nickname.end())
							total++;
					}
				}
			}
		}*/
		total += names[nickname];
		std::cout << total << '\n';
	}
	return 0;
}