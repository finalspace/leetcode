// Source : https://leetcode.com/problems/validate-binary-search-tree/
// Author : Siyuan Xu
// Date   : 2015-08-15

/********************************************************************************** 
* 
* Given a binary tree, determine if it is a valid binary search tree (BST).
* 
* Assume a BST is defined as follows:
* 
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
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
 
 
 //maintaining global pre-node
 //using in-order to check if sequence is ascending
 //12ms(best)
class Solution1 {
public:
    //https://leetcode.com/discuss/14886/order-traversal-please-rely-buggy-int_max-int_min-solutions
    bool isValid(TreeNode* root, TreeNode* &prev){
		if (!root) return true;
		if (root->left && !isValid(root->left, prev)) return false;
		if (prev && prev->val >= root->val) return false;
		prev = root;
		return isValid(root->right, prev);
	}
    bool isValidBST(TreeNode* root) {
		TreeNode* prev = NULL;
        return isValid(root, prev);
    }
};


//utilizing boundary check
//12ms(best)
class Solution2 {
public:
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
		if (root == NULL) return true;
		if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
			return false;
		if ((root->left && !isValid(root->left, minNode, root)) || (root->right && !isValid(root->right, root, maxNode)))
			return false;
		return true;
	}
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
};


//recursive
//12ms(best)
class Solution3 {
public:
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
		if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};
