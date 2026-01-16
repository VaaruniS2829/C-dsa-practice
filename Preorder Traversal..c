#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node *root = (struct node*)malloc(sizeof(struct node));
    struct node *n1   = (struct node*)malloc(sizeof(struct node));
    struct node *n2   = (struct node*)malloc(sizeof(struct node));

    root->data = 1;
    n1->data = 2;
    n2->data = 3;

    root->left = n1;
    root->right = n2;
    n1->left = NULL;
    n1->right = NULL;
    n2->left = NULL;
    n2->right = NULL;

    preorder(root);

    return 0;
}
