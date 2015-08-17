// Source : https://leetcode.com/problems/simplify-path/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Given an absolute path for a file (Unix-style), simplify it.
* 
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* 
* 
* Corner Cases:
* 
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
* 
*               
**********************************************************************************/

//8ms(best)
class Solution {
public:
    string simplifyPath(string path) {
        string res;
		stack<string> stk;
		string folder = "";
		stringstream ss(path);
		string tmp;
		while (getline(ss, tmp, '/')) {
			if (tmp == ".") continue;
			if (tmp == "..") { if (!stk.empty()) stk.pop(); }
			else if (!tmp.empty()) stk.push(tmp);
		}
		if (stk.empty()) return "/";
		while (!stk.empty()) {
			res = '/' + stk.top() + res;
			stk.pop();
		}
		return res;
    }
};


//12ms(good)
class Solution {
public:
    string simplifyPath(string path) {
        string res;
		stack<string> stk;
		string folder = "";
		stringstream ss(path);
		string tmp;
		while (getline(ss, tmp, '/')) {
			if (tmp == ".") continue;
			if (tmp == "..") { if (!stk.empty()) stk.pop(); }
			else if (!tmp.empty()) stk.push(tmp);
		}
		if (stk.empty()) return "/";
		while (!stk.empty()) {
			res = '/' + stk.top() + res;
			stk.pop();
		}
		return res;
    }
};

//16ms
class Solution {
public:
    string simplifyPath(string path) {
        string res;
		stack<string> stk;
		string folder = "";
		path += '/';
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == '/') {
				if (folder == "..") {if (!stk.empty()) stk.pop(); }
				else if (!folder.empty() && folder != ".") { stk.push(folder); };
				folder.clear();
			}
			else {
				folder.push_back(path[i]);
			}
		}
		if (stk.empty()) return "/";
		while (!stk.empty()) {
			res = '/' + stk.top() + res;
			stk.pop();
		}
		return res;
    }
};
