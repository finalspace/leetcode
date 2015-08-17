// Source : https://leetcode.com/problems/4sum/
// Author : Siyuan Xu
// Date   : 2015-08-03

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
* Find all unique quadruplets in the array which gives the sum of target.
* 
* Note:
* 
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
* The solution set must not contain duplicate quadruplets.
* 
*     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
* 
*     A solution set is:
*     (-1,  0, 0, 1)
*     (-2, -1, 1, 2)
*     (-2,  0, 0, 2)
* 
*               
**********************************************************************************/

//insert pair value into map and record position information. 
//iterate first two numbers, then find the last valid pair(using position information)
//212ms 
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
		unordered_map<int, vector<pair<int, int>>> cache;
		if (nums.size() < 4) return res;
		sort(nums.begin(), nums.end());
		auto last = nums.end();
		for(auto i = 0; i < nums.size(); i++){
			for(auto j = i + 1; j < nums.size(); j++){
			    cache[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
			}
		}
		for(auto i = 0; i<nums.size(); i++){
			for(auto j = i+1; j<nums.size(); j++){
				int goal = target - nums[i] -nums[j];
				if (cache.find(goal)!=cache.end()){
				    const auto& vec = cache[goal];
					for(int k = 0; k < vec.size(); k++){
						if (i > vec[k].second){
							res.push_back( { nums[vec[k].first],nums[vec[k].second], nums[i], nums[j] });
						}
					}
				}
			}
		}
		
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
}
        
};

//188 ms
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
		if (nums.size()<4) return res;
		sort(nums.begin(), nums.end());
		auto last = nums.end();
		int sum = 0;
		for(auto i = nums.begin(); i < prev(last, 3); i++){
			for(auto j = next(i); j < prev(last, 2); j++){
				auto k = next(j);
				auto l = prev(last);
				while(k<l){
					sum = *i+*j+*k+*l;
					if (sum>target){
						l--;
					}else if (sum<target){
						k++;
					}else{
						vector<int> ans;
						ans.push_back(*i);
						ans.push_back(*j);
						ans.push_back(*k);
						ans.push_back(*l);
						res.push_back(ans);
						while((k<l)&&(*k==*(k+1)))
							k++;
						while((k<l)&&(*l==*(l-1)))
							l--;
						k++; l--;
					}
				}
			}
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());

		return res;
}
        
};
