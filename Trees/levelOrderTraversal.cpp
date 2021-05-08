//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){ return result; }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>current_level; 
            current_level.reserve(n);
            for(int i=0;i < n;i++){
                TreeNode*p = q.front();
                q.pop();
                if(p != NULL){
                    current_level.push_back(p->val);
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            if(current_level.size() > 0){
                result.push_back(current_level);
            }
        }
        return result;
    }
};