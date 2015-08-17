// Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author : Siyuan Xu
// Date   : 2015-08-15

/********************************************************************************** 
* 
* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
* 
* For example,
* Given n = 3, your program should return all 5 unique BST's shown below.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
* 
* OJ's Binary Tree Serialization:
* 
* The serialization of a binary tree follows a level order traversal, where '#' signifies 
* a path terminator where no node exists below.
* 
* Here's an example:
* 
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
* 
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
* 
*               
**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//24ms(good)
class Solution {
public:
    vector<TreeNode*> generate(int l, int r){
		if (l > r) return vector<TreeNode*>(1, NULL);
		vector<TreeNode*> res;
		for(int i = l; i <= r; i++){
			vector<TreeNode*> lRes = generate(l, i - 1);
			vector<TreeNode*> rRes = generate(i + 1, r);
			for(int ll = 0; ll < lRes.size(); ll++){
				for(int rr = 0; rr < rRes.size(); rr++){
					TreeNode* head = new TreeNode(i);
					head->left = lRes[ll]; head->right = rRes[rr];
					res.push_back(head);
				}
			}
		}
		return res;
	}
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
		res = generate(1, n);
		return res;
    }
};
