#include <iostream>
#include <queue>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
class Tree{
public:
    node* createNode(int data)
    {
        node* newnode = new node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    void insertIntoBinaryTree(node *root,int data)
    {
        queue<node *> q;
        q.push(root);
        while(!q.empty())
        {
            node* temp=q.front();
        //    cout<<temp->data<<"\t";
            q.pop();
            if(!root->left)
            {
                root->left = createNode(data);
                break;
            }
            else
                q.push(temp->left);
            if(!root->right)
            {
                root->right = createNode(data);
                break;
            }
            else
                q.push(temp->right);
        }

    }
    void inorderTraversal(node *root)
    {
        if(root == NULL)
            return;
        inorderTraversal(root->left);
        cout<<root->data<<"\t";
        inorderTraversal(root->right);
    }
};
int main()
{

    Tree t;
    node* root = t.createNode(10);
    t.insertIntoBinaryTree(root,20);
    t.insertIntoBinaryTree(root,30);
    t.inorderTraversal(root);
    return 0;
}