// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Siyuan Xu
// Date   : 2015-07-30

/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
*
**********************************************************************************/

//20ms
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map <int, int> numMap;
		for (int i = 0; i < nums.size(); i++) {
			numMap[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			if ((numMap.find(target - nums[i]) != numMap.end()) && (numMap[target - nums[i]] > i)) {
				result.push_back(i + 1);
				result.push_back(numMap[target - nums[i]] + 1);
				return result;
			}
		}
	}
}
