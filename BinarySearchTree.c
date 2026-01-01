#include <stdio.h>
#include <stdlib.h>

/* --------- Structure of BST Node --------- */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* --------- Create a New Node --------- */
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* --------- Insert into BST --------- */
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

/* --------- Inorder Traversal --------- */
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* --------- Search in BST --------- */
int search(struct node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* --------- Main Function --------- */
int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    int key = 40;
    if (search(root, key))
        printf("\n%d found in BST", key);
    else
        printf("\n%d not found in BST", key);

    return 0;
}
