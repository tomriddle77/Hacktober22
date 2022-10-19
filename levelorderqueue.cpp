#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left;
    struct Node *right;
    int freq;
    int data;
};

typedef struct Node node;

int n = 13;

int max(int a, int b)
{
    return a > b ? a : b;
}

node *construct_tree(int a[10], node *root, int i)
{
    if (i >= n)
        return 0;
    root = (node *)malloc(sizeof(node));
    root->data = a[i];
    root->left = construct_tree(a, root, 2 * i + 1);
    root->right = construct_tree(a, root, 2 * i + 2);
    return root;
}



void printlevelorder(node *root)
{
    if(root==0)
        return;

    queue<node *> q;
    q.push(root);
    while(q.empty()==false)
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left!=0) q.push(temp->left);
        if(temp->right!=0) q.push(temp->right);
    }
}

int main()
{

    int a[13] = {1, 2, 3, 4, 50, 6, 7, 8, 9, 10, 1, 2, 70};
    node *root = construct_tree(a, root, 0);
    printf(" LEVELORDER TRAVERSAL: ");
    printlevelorder(root);
    return 0;
}