// Source : https://leetcode.com/problems/recover-binary-search-tree/
// Author : Siyuan Xu
// Date   : 2015-08-15

/********************************************************************************** 
* 
* Two elements of a binary search tree (BST) are swapped by mistake.
* 
* Recover the tree without changing its structure.
* 
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 //52(good)
class Solution1 {
public:
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeNode *n1 = NULL;
        TreeNode *n2 = NULL;
        TreeNode *prev = NULL;
        proc(root,n1,n2,prev);
        if(n1 && n2)
            swap(n1->val,n2->val);
        }
    void proc(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev)
    {
        if(!root)
            return;
        proc(root->left,n1,n2,prev);
        if(prev && prev->val > root->val)
        {
            n2 = root;
            if(!n1)
            n1 = prev;
        }
        prev = root;
        proc(root->right,n1,n2,prev);
    }
};
