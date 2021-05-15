/* 
For the recursive solution, we set a lower bound and a upper bound for the tree. 
When we recurse on the left subtree, the upper bound becomes the value of its root. 
When we recurse on the right subtree, the lower bound becomes the value of its root.

Note we use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX].

*/

// Approach 1 : Recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX); 
    }
    bool helper(TreeNode*root, long min, long max){
        if(root == NULL){ return true; }
        if(root->val <= min || root->val >= max){ return false; }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
    
};

// Approach 2 : Recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode*prev = NULL;
        return validate(root, prev); 
    }
    bool validate(TreeNode*root, TreeNode*&prev){
        if(root == NULL){ return true; }
        if(!validate(root->left,prev)){ return false; }
        if(prev && prev->val >= root->val){ return false; }
        prev = root;
        return validate(root->right, prev);
    }
    
};

//Approach 3 : Iterative
//The iterative idea is to apply iterative inorder traversal to the tree 
//and check whether the current value is always larger than the previous one.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){ return true; }
        stack<TreeNode*> stack;
        TreeNode*prev = NULL;
        while(root != NULL || !stack.empty()){
            while(root != NULL){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(prev && prev->val >= root->val){ return false; }
            prev = root;
            root = root->right;
        }
        return true;
    }
};