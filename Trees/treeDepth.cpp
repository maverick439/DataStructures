/*
"Top-down" Solution
"Top-down" means that in each recursive call, we will visit the node first to come up with some values, 
and pass these values to its children when calling the function recursively. 
So the "top-down" solution can be considered as a kind of preorder traversal.
*/
int answer; // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}

/*
"Bottom-up" Solution
"Bottom-up" is another recursive solution. In each recursive call, we will firstly call the function recursively 
for all the children nodes and then come up with the answer according to the returned values and the value of the 
current node itself. 
This process can be regarded as a kind of postorder traversal. 
*/

int maximum_depth(TreeNode* root) {
    if (!root) {
        return 0;                                 // return 0 for null node
    }
    int left_depth = maximum_depth(root->left);
    int right_depth = maximum_depth(root->right);
    return max(left_depth, right_depth) + 1;      // return depth of the subtree rooted at root
}