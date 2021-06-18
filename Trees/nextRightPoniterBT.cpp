/*
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

https://leetcode.com/explore/interview/card/microsoft/31/trees-and-graphs/163/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


// Iterative Approach
class Solution {
public:
    Node* connect(Node* root) {
        if (!root || (root->left == NULL && root->right == NULL)) return root;
        Node*head = root;
        while(head != NULL){
            Node*dummy = new Node(0);
            Node*temp = dummy;
            while(head != NULL){
                if(head->left != NULL){
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right != NULL){
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }
        return root;
    }
};


// Recursive Approach
class Solution {
public:
    Node* connect(Node* root) {
        if (!root || (root->left == NULL && root->right == NULL)) return root;
        if (root->left)
        {
            if (root->right)
            {
                root->left->next = root->right;
            }
            else
            {
                Node *node = root->next;
                while (node)
                {
                    if (node->left)
                    {
                        root->left->next = node->left;
                        break;
                    }
                    else if (node->right)
                    {
                        root->left->next = node->right;
                        break;
                    }
                    node = node->next;
                }
            }
        }
        
        if (root->right)
        {   
            Node *node = root->next;
            
            while (node)
            {
                if (node->left)
                {
                    root->right->next = node->left;
                    break;
                }
                else if (node->right)
                {
                    root->right->next = node->right;
                    break;
                }
                node = node->next;
            }
        }

        connect(root->right);   // right first before next level
        connect(root->left);
        
        
        return root;
    }
};