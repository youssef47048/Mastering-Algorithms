// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> numList;
const int MAX = 2500 + 1;
int memory[MAX][MAX];

int LIS(int i, int prev) {
	if (i == (int) numList.size())
		return 0;

	auto &ret = memory[i][prev];

	if (ret != -1)
		return ret;

	int choice1 = LIS(i + 1, prev);	// Leave
	int choice2 = 0;

	if (prev >= (int) numList.size() || numList[prev] < numList[i])
		choice2 = 1 + LIS(i + 1, i);	// Take

	return ret = max(choice1, choice2);
}

void LIS_print(int i, int prev) {
	if (i == (int) numList.size())
		return;
	// Compute optimal and see which path generated it
	int optimal = LIS(i, prev);

	int choice1 = LIS(i + 1, prev);	// Leave
	int choice2 = 0;

	if (prev >= (int) numList.size() || numList[prev] < numList[i])
		choice2 = 1 + LIS(i + 1, i);	// Take

	if (optimal == choice1)
		LIS_print(i + 1, prev);
	else {	// choice 2
		cout << numList[i] << " ";
		LIS_print(i + 1, i);
	}
}

class Solution {
public:
	int lengthOfLIS(const vector<int> &nums) {
		numList = nums;
		memset(memory, -1, sizeof(memory));
		int ans = LIS(0, numList.size());

		LIS_print(0, numList.size());

		return ans;
	}
};

int main() {
	Solution().lengthOfLIS( { 10, 9, 2, 5, 3, 7, 101, 18 });

	return 0;
}
