/**
 * The boundary of a binary tree is the concatenation of the root, 
 * the left boundary, the leaves ordered from left-to-right, 
 * and the reverse order of the right boundary.
 * 
 * Input: root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
 * Output: [1,2,4,7,8,9,10,6,3]
 * https://leetcode.com/problems/boundary-of-binary-tree/
 * */

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> boundary;
        if(root == NULL){ return boundary; }
        
        boundary.push_back(root->val);
        
        leftBoundary(root->left,boundary);
        leavesBoundary(root->left, boundary);
        leavesBoundary(root->right, boundary);
        rightBoundary(root->right,boundary);
         
        return boundary;
    }
private:
    // Get the left boundary nodes of tree
    void leftBoundary(TreeNode*root, vector<int>&boundary){
        //Check for blank or leaf nodes
        if(root == NULL || (!root->left && !root->right)){ return; }
        boundary.push_back(root->val);
        if(root->left == NULL){ leftBoundary(root->right, boundary); }
        else{ leftBoundary(root->left, boundary); }
    }
    // Get the right boundary nodes of tree
    void rightBoundary(TreeNode*root, vector<int>&boundary){
        //Check for blank or leaf nodes
        if(root == NULL || (!root->left && !root->right)){ return; }
        if(root->right == NULL){ rightBoundary(root->left, boundary); }
        else{ rightBoundary(root->right, boundary); }
        boundary.push_back(root->val);
        
    }
    // Get the bottom boundary or leaves of tree
    void leavesBoundary(TreeNode*root, vector<int>&boundary){
        if(root == NULL){ return; }
        if(!root->left && !root->right){ 
            boundary.push_back(root->val);
            return;
        }
        leavesBoundary(root->left, boundary);
        leavesBoundary(root->right, boundary);
    }
            
};