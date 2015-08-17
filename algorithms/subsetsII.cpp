// Source : https://leetcode.com/problems/subsets-ii/
// Author : Siyuan Xu
// Date   : 2015-08-14

/********************************************************************************** 
* 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,2], a solution is:
* 
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/

class Solution90 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> vec;
		for (int i = 0; i < 1 << n; i++) {
			vec.clear();
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1)
					vec.push_back(nums[j]);
			}
			res.insert(vec);
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
};

//12ms
class Solution90_02 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int bar = 0;
		for (int i = 0; i < n; i++) {
			int l = res.size();
			for (int j = 0; j < l; j++) {
				if (i == 0 || nums[i] != nums[i - 1] || j >= bar) {
					res.push_back(res[j]);
					res.back().push_back(nums[i]);
				}
			}
			bar = l;
		}
		return res;
	}
};

//12ms
class Solution90_03 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		int n = nums.size(), k = 0;
		while (k < n) {
			int count = 1;
			while (k + 1 < n && nums[k + 1] == nums[k]) {
				k++; count++;
			}
			int l = res.size();
			vector<int> tmp;
			for (int c = 0; c < count; c++) {
				tmp.push_back(nums[k]);
				for (int j = 0; j < l; j++) {
					res.push_back(res[j]);
					res.back().insert(res.back().end(), tmp.begin(), tmp.end());
				}
			}
			k++;
		}
		return res;
	}
};

//12ms
class Solution90_04 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret;
		ret.push_back(vector<int>());
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ) {
			int j = i;
			while (j < nums.size() && nums[j] == nums[i]) j++;
			int size = ret.size();
			vector<int> tmp;
			for (int len = 1; i + len <= j; len++) {
				tmp.push_back(nums[i]);
				for (int cnt = 0; cnt < size; cnt++) {
					ret.push_back(ret[cnt]);
					ret.back().insert(ret.back().end(), tmp.begin(), tmp.end());
				}
			}
			i = j;
		}
		return ret;
	}
};

//8ms
class Solution90_05 {
public:
	void dfs(vector<vector<int>> &res, vector<int> &ans, vector<int>& nums, int k) {
		if (k >= nums.size())
			return;
		for (int i = k; i < nums.size(); i++) {
			if (i == k || nums[i] != nums[i - 1]) {
				ans.push_back(nums[i]);
				res.push_back(ans);
				dfs(res, ans, nums, i + 1);
				ans.pop_back();
			}
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res(1);
		vector<int> ans;
		sort(nums.begin(), nums.end());
		dfs(res, ans, nums, 0);
		return res;
	}
};

//12ms
class Solution90_06 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > totalset = {{}};
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size();) {
			int count = 0; // num of elements are the same
			while (count + i<nums.size() && nums[count + i] == nums[i])  count++;
			int previousN = totalset.size();
			vector<int> tmp;
			for (int c = 0; c < count; c++) {
				tmp.push_back(nums[i]);
				for (int j = 0; j < previousN; j++) {
					totalset.push_back(totalset[j]);
					totalset.back().insert(totalset.back().end(), tmp.begin(), tmp.end());
				}
			}
			i += count;
		}
		return totalset;
	}
};


