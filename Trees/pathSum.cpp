/* Given the root of a binary tree and an integer targetSum, return true if the tree has a 
root-to-leaf path such that adding up all the values along the path equals targetSum.
Link: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/537/
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){ return false; }
        if(!root->left && !root->right && root->val == targetSum){ return true; }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
    
};
