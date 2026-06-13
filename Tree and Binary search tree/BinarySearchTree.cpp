

#include<bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};


void add_left_child(TreeNode *node, TreeNode *leftChild)
{
    node->left = leftChild;
}

void add_right_child(TreeNode *node, TreeNode *rightChild)
{
    node->right= rightChild;
}


TreeNode* createNode(int value)
{

    TreeNode *new_node =(TreeNode*) malloc(sizeof(TreeNode));

    if(new_node==NULL)
    {
        cout<<"Node not created...";
        exit(1);
    }

    new_node->val = value;
    new_node->left = NULL;
    new_node->right= NULL;

    return new_node;
}

void pre_order_traverse(TreeNode *preOrder)
{

    cout<<preOrder->val<<", ";

    if(preOrder->left !=NULL)
    {
       // preOrder=preOrder->left;
        pre_order_traverse(preOrder->left);
    }

    if(preOrder->right !=NULL)
    {
       // preOrder=preOrder->right;
        pre_order_traverse(preOrder->right);
    }
}

void post_order_traverse(TreeNode *postOrder){

    if(postOrder->left !=NULL){
        post_order_traverse(postOrder->left);
    }

    if(postOrder->right != NULL){
           post_order_traverse(postOrder->right);
    }

    cout<<postOrder->val<<", ";

}


void in_order_traverse(TreeNode *inOrder){

    if(inOrder->left !=NULL){
        in_order_traverse(inOrder->left);
    }

    cout<<inOrder->val<<", ";

    if(inOrder->right !=NULL){
        in_order_traverse(inOrder->right);
    }

}
int main()
{
    // 2 -> root child -> left: 7, right: 5;
    // 7 -> child new root -> left : 10; right: 8;
    // 5 -> child new root -> left : 11, right: 90

    TreeNode *root=createNode(2);
    TreeNode *left=createNode(7);
    TreeNode *right=createNode(5);

    add_left_child(root, left);
    add_right_child(root, right);

    TreeNode *leftChildLeft=createNode(10);
    TreeNode *leftChildRight=createNode(8);

    add_left_child(left, leftChildLeft);
    add_right_child(left, leftChildRight);

    TreeNode *rightChildLeft=createNode(11);
    TreeNode *rightChildRight=createNode(90);

    add_left_child(right, rightChildLeft);
    add_right_child(right, rightChildRight);


    cout<<"Let's print the created tree "<<endl;

    cout<<"------ Preorder Traverse ------"<<endl;
    pre_order_traverse(root);

    cout<<endl;
    cout<<"------ Postorder Traverse ------"<<endl;
    post_order_traverse(root);

    cout<<endl;
    cout<<"------ Inorder Traverse ------"<<endl;
    in_order_traverse(root);


    //TreeNode *head=root;

    /*while(root!=NULL)
    {
        cout<<root->val<<", ";
        root=root->left;
    }
    head=head->right;
    while(head!=NULL){
        cout<<head->val<<", ";
        head=head->right;
    } */

    return 0;
}




