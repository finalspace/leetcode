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

//better solution
//https://leetcode.com/discuss/22289/my-ac-c-code-o-n-complexity-26ms
class Solution {
// The general idea:
// Construct a hash function f for L, f: vector<string> -> int, 
// Then use the return value of f to check whether a substring is a concatenation 
// of all words in L.
// f has two levels, the first level is a hash function f1 for every single word in L.
// f1 : string -> double
// So with f1, L is converted into a vector of float numbers
// Then another hash function f2 is defined to convert a vector of doubles into a single int.
// Finally f(L) := f2(f1(L))
// To obtain lower complexity, we require f1 and f2 can be computed through moving window.
// The following corner case also needs to be considered:
// f2(f1(["ab", "cd"])) != f2(f1(["ac", "bd"]))
// There are many possible options for f2 and f1. 
// The following code only shows one possibility (probably not the best), 
// f2 is the function "hash" in the class,
// f1([a1, a2, ... , an]) := int( decimal_part(log(a1) + log(a2) + ... + log(an)) * 1000000000 )
public:
    // The complexity of this function is O(nW).
    double hash(double f, double code[], string &word) {
        double result = 0.;
        for (auto &c : word) result = result * f + code[c];
        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        uniform_real_distribution<double> unif(0., 1.);
        default_random_engine seed;
        double code[128];
        for (auto &d : code) d = unif(seed);
        double f = unif(seed) / 5. + 0.8;
        double value = 0;

        // The complexity of the following for loop is O(L.size( ) * nW).
        for (auto &str : L) value += log(hash(f, code, str));

        int unit = 1e9;
        int key = (value-floor(value))*unit;
        int nS = S.size(), nL = L.size(), nW = L[0].size();
        double fn = pow(f, nW-1.);
        vector<int> result;
        if (nS < nW) return result;
        vector<double> values(nS-nW+1);
        string word(S.begin(), S.begin()+nW);
        values[0] = hash(f, code, word);

        // Use a moving window to hash every word with length nW in S to a float number, 
        // which is stored in vector values[]
        // The complexity of this step is O(nS).
        for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];

        // This for loop will run nW times, each iteration has a complexity O(nS/nW)
        // So the overall complexity is O(nW * (nS / nW)) = O(nS)
        for (int i=0; i<nW; ++i) {
            int j0=i, j1=i, k=0;
            double sum = 0.;

            // Use a moving window to hash every L.size() continuous words with length nW in S.
            // This while loop will terminate within nS/nW iterations since the increasement of j1 is nW,
            // So the complexity of this while loop is O(nS / nW).
            while(j1<=nS-nW) {
                sum += log(values[j1]);
                ++k;
                j1 += nW;
                if (k==nL) {
                    int key1 = (sum-floor(sum)) * unit;
                    if (key1==key) result.push_back(j0);
                    sum -= log(values[j0]);
                    --k;
                    j0 += nW;
                }
            }
        }
        return result;
    }
};
