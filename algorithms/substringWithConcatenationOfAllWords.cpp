// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : Siyuan Xu
// Date   : 2015-08-05

/********************************************************************************** 
* 
* You are given a string, S, and a list of words, L, that are all of the same length. 
* Find all starting indices of substring(s) in S that is a concatenation of each word 
* in L exactly once and without any intervening characters.
* 
* For example, given:
* S: "barfoothefoobarman"
* L: ["foo", "bar"]
* 
* You should return the indices: [0,9].
* (order does not matter).
* 
*               
**********************************************************************************/

//store words in map (straightforwad solution)
//768ms
class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
		unordered_map<string, int> map;
		for (auto s : words) {
			map[s]++;
		}
		int wordLen = words[0].size();
		int windowLen = wordLen * words.size();
		for (int i = 0; i < s.length() - windowLen + 1; i++) {
			unordered_map<string, int> count;
			for (int j = 0; j < words.size(); j++) {
				string word = s.substr(i + j*wordLen, wordLen);
				if (map.find(word) != map.end()) {
					count[word]++;
					if (count[word] > map[word])
						break;
					if (j == words.size() - 1) {
						res.push_back(i);
					}
				}
				else break;
			}
		}
		return res;
    }
};

class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                } 
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};
