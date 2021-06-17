/**
 * Populating Next Right Pointers in Each Node
 * You are given a "perfect binary tree" where all leaves are on the same level, and every parent has two children.
 * */

// Recursive Solution
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){ return NULL; }
        if(root->left){
            root->left->next = root->right; 
            if(root->next){
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};


// Iterative Solution
class Solution {
public:
    Node* connect(Node* root) {
        Node*pre = root; 
        while(pre){
            Node*current = pre;
            while(current && current->left){
                current->left->next = current->right;
                if(current->next){
                    current->right->next = current->next->left;
                }
                current = current->next;
            }
            pre = pre->left;
        }
        return root;
    }
};