// Source : https://leetcode.com/problems/3sum/
// Author : Siyuan Xu
// Date   : 2015-08-02

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note:
* 
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
* 
*     For example, given array S = {-1 0 1 2 -1 -4},
* 
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
* 
*               
**********************************************************************************/

//pick a first number, then set front and back as the both sides of the rest numbers, and move towards center
//56ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;

        while (front < back) {

            int sum = nums[front] + nums[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && nums[back] == triplet[2]) back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;

    }

    return res;
        
    }
};
