// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
// Link: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/536/
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

// Recursive Approach
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){ return false; }
        return helper(root->left,root->right);
    }
    bool helper(TreeNode*p, TreeNode*q){
        if(!p && !q){ return true; }
        if(!p || !q){ return false; }
        if(p->val != q->val){ return false; }
        return helper(p->left,q->right) && helper(p->right,q->left);
    }
};

// Iterative Approach
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){ return false; }
        TreeNode*leftNode;  TreeNode*rightNode;
        queue<TreeNode*>p;  queue<TreeNode*>q;
        p.push(root->left); q.push(root->right);
        while(!p.empty() && !q.empty()){
            leftNode = p.front(); p.pop();
            rightNode= q.front(); q.pop();
            if(!leftNode && !rightNode){ continue; }
            else if(!leftNode || !rightNode){ return false; }
            else if(leftNode->val != rightNode->val){ return false; }
            p.push(leftNode->left); q.push(rightNode->right);
            p.push(leftNode->right); q.push(rightNode->left);
        }
        return true;
    }
};