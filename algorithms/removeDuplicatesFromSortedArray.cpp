// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Siyuan Xu
// Date   : 2015-08-03

/********************************************************************************** 
* 
* Given a sorted array, remove the duplicates in place such that each element appear 
* only once and return the new length.
* 
* Do not allocate extra space for another array, you must do this in place with constant memory.
* 
* For example,
* Given input array A = [1,1,2],
* 
* Your function should return length = 2, and A is now [1,2].
* 
*               
**********************************************************************************/

//basic lib algorithm
//32ms
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end())-nums.begin();
    }
};

//basic lib algorithm
//40ms
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
		int res = nums.size();
		int m = nums[0];
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
        
    }
};

//array trick
//36ms
class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for(int i = 1; i < n; i++){
      if(nums[i] == nums[i-1]) count++;
      else nums[i-count] = nums[i];
    }
    return n-count;
    }
};
