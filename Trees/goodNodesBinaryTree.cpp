/**
 Given a binary tree root, a node X in the tree is named good if in the path from root to X 
 there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 */

// DFS based Solution
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        if(root == NULL){ return result; }
        dfs_helper(root,result,INT_MIN);
        return result;
    }
    void dfs_helper(TreeNode*root, int&result, int max_so_far){
        if(root){
            if(root->val >= max_so_far){ result++; }
            dfs_helper(root->left, result, max(max_so_far,root->val)); 
            dfs_helper(root->right,result, max(max_so_far,root->val));
        }
    }
};