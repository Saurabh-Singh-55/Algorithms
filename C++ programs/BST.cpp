#include <iostream>
using namespace std;

class node
{
    public :
    int data;
    node* left;
    node* right;
    node(int x)
    {
        data =x;
        left=NULL;
        right=NULL;
    }
};

node* insert(node* root,int x)
{
    if(root==NULL)
        {   node* j=new node(x);
            return j;
        }
    else if(x>root->data)
        root->right=insert(root->right,x);
    else if(x<root->data)
        root->left=insert(root->left,x);
    return root;
}

void inorder(node* root)
{

    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}
void delet(int x)
{
}

int main()
{

    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 50);
    insert(root, 50);
    insert(root, 80);
    inorder(root);

    return 0;
}



