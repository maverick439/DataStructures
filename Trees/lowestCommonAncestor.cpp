/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if(!root || root == p || root == q){ return root; }
        
        TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);
        if(leftTree == NULL){ return rightTree; }
        else if(rightTree == NULL){ return leftTree; }
        else{ return root; }
        
    }
};