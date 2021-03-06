// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(begin(nums), end(nums));
		vector<vector<int>> result;
		vector<int> v;
		dfs(result, v, nums, 0);
		return result;
	}
private:
	void dfs(vector<vector<int>>& result, vector<int>& v, vector<int>& nums, int i) {
		result.push_back(v);
		for (int j = i, n = nums.size(); j < n; j++) {
			if (j > i and nums[j] == nums[j - 1]) {
				continue;
			}
			v.push_back(nums[j]);
			dfs(result, v, nums, j + 1);
			v.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result, answer;

	nums = {1, 2, 2};
	answer = {{2}, {1}, {1, 2, 2}, {2, 2}, {1, 2}, {}};
	sort(begin(answer), end(answer));
	result = solution.subsetsWithDup(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}