#include <iostream>

void swap(int i, int j, int nums[5]) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void printnums(int nums[5]) {
	for (int i = 0; i < 5; i += 1) {
		std::cout << nums[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	int nums[5];
	for (int i = 0; i < 5; i += 1) {
		std::cin >> nums[i];
	}
	for (int last = 4; last >= 0; last -= 1) {
		bool swapped = false;
		for (int i = 0; i < last; i += 1) {
			if (nums[i] > nums[i + 1]) {
				swapped = true;
				swap(i, i + 1, nums);
				printnums(nums);
			}
		}
		if (!swapped) {
			break;
		}
	}
	return 0;
}