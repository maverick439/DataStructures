/**
Basic Concept
Approach 1: Recursion O(N)
1. Pre-order Traversal (Traverse Right before left for this case)
2. Make a visited_level array or variable 
3. Store the node-val in sol array if it's level is not vistited from before

Approach 2: Level Order Traversal O(N)
1. Do a level order traversal
2. Store the last values of each level in sol array.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        int levelToPrint = 0;
        rightHelper(root, 1, levelToPrint, right_view);
        return right_view;
    }
private:
    void rightHelper(TreeNode*root,int currLevel,int &levelToPrint,vector<int>& right_view){
        if(root == NULL){ return; }  
        if(levelToPrint < currLevel){
            right_view.push_back(root->val);
            levelToPrint = currLevel;
        }
        rightHelper(root->right, currLevel+1, levelToPrint, right_view);
        rightHelper(root->left, currLevel+1, levelToPrint, right_view);
    }
};