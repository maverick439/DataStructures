#include <iostream>
#include <queue>
using namespace std;

class   TreeNode{
public:
    int data;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int d){
        data = d;
        TreeNode*left = NULL;
        TreeNode*right = NULL;
    }
};

TreeNode* createTree(){
    int x;
    cin>>x;
    if(x == -1)
        return NULL;
    TreeNode*root = new TreeNode(x);
    cout<<"Enter left child of - "<<x<<" ";
    root->left = createTree();
    cout<<"Enter right child of - "<<x<<" ";
    root->right = createTree();
    return root;
}

void preorder(TreeNode*root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode*root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(TreeNode*root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(TreeNode*root){
    queue<TreeNode*> q;
    if(root == NULL)
        return;
    q.push(root);

    while(q.empty() != true){
        TreeNode* cur = q.front();
        q.pop();
        cout<<cur->data<<" ";
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
}

void leftView(TreeNode* root,int curLevel,int &leveltoPrint){
        if(root == NULL)
            return;
        if(leveltoPrint < curLevel){
            cout<<root->data<<" ";
            leveltoPrint = curLevel;
        }
        leftView(root->left,curLevel+1,leveltoPrint);
        leftView(root->right,curLevel+1,leveltoPrint);
}
void leftView(TreeNode*root){
    int leveltoPrint = 0;
    leftView(root,1,leveltoPrint);
}

void rightView(TreeNode* root,int curLevel,int &leveltoPrint){
        if(root == NULL)
            return;
        if(leveltoPrint < curLevel){
            cout<<root->data<<" ";
            leveltoPrint = curLevel;
        }
        rightView(root->right,curLevel+1,leveltoPrint);
        rightView(root->left,curLevel+1,leveltoPrint);
}
void rightView(TreeNode*root){
    int leveltoPrint = 0;
    rightView(root,1,leveltoPrint);
}

int countNodes(TreeNode*root){
    if(root==NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int height(TreeNode*root){
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left),height(root->right));
}
int diameter(TreeNode*root){
    if(root == NULL)
        return 0;
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}
int main(){
    TreeNode* root = NULL;
    root = createTree();
    cout<<"Pre-order : ";
    preorder(root);     cout<<endl;
    cout<<"Inorder :";
    inorder(root);      cout<<endl;
    cout<<"Post-order :";
    postorder(root);    cout<<endl;
    cout<<"Level - Order Traversal\n";
    levelOrder(root);   cout<<endl;
    cout<<"Left View : ";
    leftView(root);     cout<<endl;
    cout<<"Right View : ";
    rightView(root);    cout<<endl;
    int cnt = countNodes(root);
    cout<<"No of Nodes : "<<cnt<<endl;
    int ht = height(root);
    cout<<"Height : "<<ht<<endl;
    int dia = diameter(root);
    cout<<"Diameter : "<<dia<<endl;

}
