#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
};

struct TreeNode *insert(struct TreeNode *root, int *nums, int left, int right)
{
    if (left > right)
        return 0;
    struct TreeNode *n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int i = (left + right) / 2;
    n->val = nums[i];
    n->left = insert(root, nums, left, i - 1);
    n->right = insert(root, nums, i + 1, right);
    return n;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *root = 0;
    root = insert(root, nums, 0, numsSize - 1);

    return root;
}