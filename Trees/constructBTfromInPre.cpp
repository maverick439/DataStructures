/**
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder 
 * is the inorder traversal of the same tree, construct and return the binary tree.
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 *https://leetcode.com/explore/interview/card/microsoft/31/trees-and-graphs/196/discuss/340504/C++-simple-recursive-(+-detail-explanation) 
 * */
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); int root_index = 0;
        return build(preorder, inorder, root_index, 0,n-1);
    }
    TreeNode*build(vector<int>& preorder, vector<int>& inorder, int&root_index, int left, int right){
        if(left > right){ return NULL; }
        int pivot = left;
        
        while(inorder[pivot] != preorder[root_index]){ pivot++; }
        root_index++;
        
        TreeNode*newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, root_index, left, pivot-1);
        newNode->right = build(preorder, inorder, root_index, pivot+1, right);
        return newNode;
    }
};

/**
 * Concept;
 * Use Preorder Traversal to get the root
 * Use Inorder Traversal to get the left & right sub tree
 * */