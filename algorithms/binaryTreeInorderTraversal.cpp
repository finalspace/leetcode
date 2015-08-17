// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Siyuan Xu
// Date   : 2015-08-15

/********************************************************************************** 
* 
* Given a binary tree, return the inorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 
*    1
*     \
*      2
*     /
*    3
* 
* return [1,3,2].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
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
 
 
 //0ms(best)
class Solution {
public:
    void helper(vector<int> &res, TreeNode* root) {
		if (!root) return;
		helper(res, root->left);
		res.push_back(root->val);
		helper(res, root->right);
	}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
		helper(res, root);
		return res;
    }
};


