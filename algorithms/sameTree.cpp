// Source : https://oj.leetcode.com/problems/same-tree/
// Author : Hao Chen
// Date   : 2013-10-01

/********************************************************************************** 
* 
* Given two binary trees, write a function to check if they are equal or not.
* 
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
* 
*               
**********************************************************************************/

/**
 * Definition for binary tree
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return IsSame(p, q);
    }
    
    bool IsSame(TreeNode *p, TreeNode *q)
    {
        if ((!p)&&(!q))
            return true;
        if ((!p)||(!q))
            return false;
        if (p->val != q->val)
            return false;
        //else
        return (IsSame(p->left, q->left) && IsSame(p->right, q->right));
    }
};
