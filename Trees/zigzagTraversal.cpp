/**
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, 
 * then right to left for the next level and alternate between).
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * 
 * https://leetcode.com/explore/interview/card/microsoft/31/trees-and-graphs/197/
 **/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result; 
        if(root == NULL){ return result; }
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> current_level;
            current_level.reserve(n);
            for(int i=0;i < n;i++){
                TreeNode*temp = q.front(); 
                q.pop();
                if(temp != NULL){
                    current_level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if(current_level.size() > 0){
                if(level%2 == 0){ 
                    reverse(current_level.begin(), current_level.end());
                }
                result.push_back(current_level);
            }
            level++;
        }
        return result;
    }
};