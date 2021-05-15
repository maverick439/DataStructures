/*
Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){ return NULL; }
        stack<TreeNode*> stack;
        vector<int> inorder;
        while(root || !stack.empty()){
            while(root){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            inorder.push_back(root->val);
            root = root->right;
        }
        int ans = inorder[k-1];
        return ans;
    }
};