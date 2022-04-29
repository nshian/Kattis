#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, t; cin >> N >> t;
	vector<int> nums;
	for (int i = 0; i < N; i++) {
		int num; cin >> num; nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	if (t == 1) {
		int left = 0; int right = nums.size() - 1;
		while (left != right) {
			int sum = nums[left] + nums[right];
			if (sum == 7777) {
				cout << "Yes" << '\n';
				return 0;
			}
				
			else {
				if (sum < 7777)
					left++;
				else
					right--;
			}
		}
		cout << "No" << '\n';
	}
	else if (t == 2) {
		for (int i = 0; i < N-1; i++) {
			if (nums[i] == nums[i + 1]) {
				cout << "Contains duplicate" << '\n';
				return 0;
			}
		}
		cout << "Unique" << '\n';
	}
	else if (t == 3) {
		int count = 1;
		int num = 0;
		for (int i = 0; i < N; i++) {
			if (nums[i] == nums[i + 1])
				count++;
			else
				count = 1;
			if (count > N / 2) {
				num = nums[i];
				cout << nums[i] << '\n';
				return 0;
			}
		}
		cout << -1 << '\n';
	}
	else if (t == 4) {
		if (N % 2 == 0)
			cout << nums[N / 2 - 1] << " " << nums[N / 2];
		else
			cout << nums[N / 2];
	}
	else {
		for (int i = 0; i < N; i++) {
			if (nums[i] >= 100 && nums[i] <= 999)
				cout << nums[i] << " ";
			if (nums[i + 1] > 999)
				return 0;
		}
	}
}