#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode *root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(0);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    root->left->right->left = createNode(3);
    root->left->right->right = createNode(5);

    struct TreeNode *p = createNode(2);
    struct TreeNode *q = createNode(8);
    struct TreeNode *result = lowestCommonAncestor(root, p, q);
    printf("LCA: %d\n", result->val); // Output: 6

    // You can add more test cases here

    return 0;
}
