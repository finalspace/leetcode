// Source : https://leetcode.com/problems/anagrams/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
 * 
 * Given an array of strings, group anagrams together.
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * 
 * Note:
 * 
 * For the return value, each inner list's elements must follow the lexicographic order.
 * All inputs will be in lower-case.
 * 
 * Update (2015-08-09):
 * The signature of the function had been updated to return list<list<string>> instead 
 * of list<string>, as suggested here. If you still see your function signature return 
 * a list<string>, please click the reload button  to reset your code definition.
 * 
 **********************************************************************************/

//nice use of map
//52ms(best) 
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> copyStr(strs);
		unordered_map<string, vector<int>> mp;
		vector<string> res;
		for (int i = 0; i < copyStr.size(); i++) {
			sort(copyStr[i].begin(), copyStr[i].end());
			mp[copyStr[i]].push_back(i);
		}
		for (auto it: mp) {
			for (int i = 0; it.second.size() > 1 && i < it.second.size(); i++) {
				res.push_back(strs[it.second[i]]);
			}
		}
		return res;
    }
};
