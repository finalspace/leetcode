// Source : https://leetcode.com/problems/sort-colors/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given an array with n objects colored red, white or blue, sort them so that objects of 
* the same color are adjacent, with the colors in the order red, white and blue.
* 
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* 
* Note:
* You are not suppose to use the library's sort function for this problem.
* 
* Follow up:
*  > A rather straight forward solution is a two-pass algorithm using counting sort.
*  > First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array 
*    with total number of 0's, then 1's and followed by 2's.
*  > Could you come up with an one-pass algorithm using only constant space?
*               
**********************************************************************************/

//Dutch national flag problem

//smart solution
//4ms(best)
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        //classic: Dutch national flag problem
        int w = 0, b = nums.size() - 1;
		for(int i = 0; i <= b; i++){
			if (nums[i] == 0)
				swap(nums[w++], nums[i]); //nums[w] is first not 0, and should be 1. this is to swap the first "1" with the current "0"
			else if (nums[i] == 2 )
				swap(nums[b--], nums[i--]);
		}
    }
};

//interesting solution
//4ms(best)
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int w = -1, r = -1, b = -1;
		for(int i = 0; i < nums.size(); i++){
			if (nums[i] == 0){
				nums[++b] = 2; nums[++r] = 1; nums[++w] = 0;
			}
			else if (nums[i] == 1){
				nums[++b] = 2; nums[++r] = 1;
			}
			else {
				nums[++b] = 2;
			}
		}
    }
};
