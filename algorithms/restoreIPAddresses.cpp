// Source : https://leetcode.com/problems/restore-ip-addresses/
// Author : Siyuan Xu
// Date   : 2015-08-15

/********************************************************************************** 
* 
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
* 
* For example:
* Given "25525511135",
* 
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
* 
*               
**********************************************************************************/

//dfs
//0ms(best)
class Solution {
public:
    void dfs(vector<string> &res, string sln, string &s, int index, int sum) {
		if (sum >= 4 && index == s.size()) {
			res.push_back(sln);
			return;
		}
		if (s.size() - index >  (4 - sum) * 3) return;
		
		for (int i = index; i < s.size() - (4 - sum - 1); i++) {
			string tmp = s.substr(index, i - index + 1);
			if (tmp.size() > 1 && tmp[0] == '0' || stoi(tmp) > 255) return;
			tmp += ((sum == 3) ? "" : ".");
			dfs(res, sln + tmp, s, i + 1, sum + 1);
		}
	}
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		string sln = "";
		if (s.size() < 4) return res;
		dfs(res, sln, s, 0, 0);
		return res;
    }
};


//dfs
//4ms(good)
class Solution {
public:
    void dfs(vector<string> &res, string &sln, string &s, int index, int sum) {
		if (sum >= 4 && index == s.size()) {
			res.push_back(sln);
			return;
		}
		if (s.size() - index >  (4 - sum) * 3) return;
		
		for (int i = index; i < s.size() - (4 - sum - 1); i++) {
			string tmp = s.substr(index, i - index + 1);
			if (tmp.size() > 1 && tmp[0] == '0') return;
			if (stoi(tmp) > 255)  return;
			tmp += ((sum == 3) ? "" : ".");
			sln += tmp;
			dfs(res, sln, s, i + 1, sum + 1);
			sln.erase(sln.end() - tmp.size(), sln.end());

		}
	}
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		string sln = "";
		if (s.size() < 4) return res;
		dfs(res, sln, s, 0, 0);
		return res;
    }
};
