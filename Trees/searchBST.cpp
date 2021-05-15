/* 
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and 
return the subtree rooted with that node. If such a node does not exist, return null.
https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/141/basic-operations-in-a-bst/1000/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){ return NULL; }
        TreeNode*current = NULL;
        while(root){
            if(val == root->val){ current = root; break; }
            else if(val < root->val){ root = root->left; }
            else{ root = root->right; }
        }
        if(current){ return current; }
        return NULL;
    }
};