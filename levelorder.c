#include <stdio.h>
#include <stdlib.h>

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

int height(node *root)
{
    if (root == 0)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

void printlevel(node*root,int level)
{
    if(level==0)
        return ;

    if(level==1)
    {
        printf("%d ", root->data);
        return;
    }
    printlevel(root->left, level - 1);
    printlevel(root->right, level - 1);
}

void printlevelorder(node*root)
{
    int h = height(root);
    for (int i = 1; i <= h;i++)
    {
        printlevel(root, i);
    }
}


int main()
{

    int a[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1,2,3};
    node *root = construct_tree(a, root, 0);
    int h = height(root);
    printf("the height of the tree is %d\n LEVELORDER TRAVERSAL: ", h);
    printlevelorder(root);
    return 0;
}