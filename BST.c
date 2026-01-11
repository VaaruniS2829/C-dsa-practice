#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

/* Create new node */
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    return x;
}

/* Insert into BST */
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;

    if (root == NULL)
        return temp;

    cur = root;
    prev = NULL;

    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

/* Find minimum node */
NODE findMin(NODE root)
{
    if (root == NULL)
        return NULL;

    while (root->llink != NULL)
        root = root->llink;

    return root;
}

/* Find maximum node */
NODE findMax(NODE root)
{
    if (root == NULL)
        return NULL;

    while (root->rlink != NULL)
        root = root->rlink;

    return root;
}

/* Count leaf nodes */
int countLeaf(NODE root)
{
    if (root == NULL)
        return 0;

    if (root->llink == NULL && root->rlink == NULL)
        return 1;

    return countLeaf(root->llink) + countLeaf(root->rlink);
}

/* Find height of tree */
int height(NODE root)
{
    int lh, rh;
    if (root == NULL)
        return 0;

    lh = height(root->llink);
    rh = height(root->rlink);

    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

/* Main function */
void main()
{
    NODE root = NULL, temp;
    int ch, n, item, i;

    while (1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1. Create BST\n");
        printf("2. Find Maximum\n");
        printf("3. Find Minimum\n");
        printf("4. Count Leaf Nodes\n");
        printf("5. Height of BST\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter elements:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &item);
                root = insert(item, root);
            }
            break;

        case 2:
            temp = findMax(root);
            if (temp == NULL)
                printf("Tree is empty\n");
            else
                printf("Maximum value = %d\n", temp->info);
            break;

        case 3:
            temp = findMin(root);
            if (temp == NULL)
                printf("Tree is empty\n");
            else
                printf("Minimum value = %d\n", temp->info);
            break;

        case 4:
            printf("Number of leaf nodes = %d\n", countLeaf(root));
            break;

        case 5:
            printf("Height of BST = %d\n", height(root));
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
