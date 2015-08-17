// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Siyuan Xu
// Date   : 2015-08-19

/********************************************************************************** 
* 
* Given a string, find the length of the longest substring without repeating characters. 
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*               
**********************************************************************************/

//using an array to store the last position of each character

//28ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> position(256, -1);
		int longest = 0;
		int front = 0;
		for(int rear = 0; rear < s.size(); rear++){
			if (position[s[rear]] >= front){
				longest = max(longest, rear - front);
				front = position[s[rear]]+1;
			}
		    position[s[rear]] = rear;
		}
		longest = max(longest, int(s.size() - front));
        return longest;
        
    }
};
