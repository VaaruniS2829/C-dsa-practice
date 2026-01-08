#include <stdio.h>
#include <stdlib.h>

/* Structure definition */
struct abb
{
    int info;
    struct abb *p;
    struct abb *n;
};

typedef struct abb *node;

/* Global header pointer */
node header = NULL;

/* Function declarations */
node getnode();
void ins();     // insert at right
void insl();    // insert to left of given element
void del();     // delete a given element
void disp();    // display list

/* MAIN FUNCTION */
int main()
{
    int ch;
    while(1)
    {
        printf("\n\n--- DOUBLY LINKED LIST ---");
        printf("\n1. Insert at right");
        printf("\n2. Insert to left of element");
        printf("\n3. Delete element");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: ins(); break;
            case 2: insl(); break;
            case 3: del(); break;
            case 4: disp(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}

/* CREATE NODE */
node getnode()
{
    node temp;
    temp = (node)malloc(sizeof(struct abb));
    if(temp == NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }
    temp->p = NULL;
    temp->n = NULL;
    return temp;
}

/* INSERT AT RIGHT (END) */
void ins()
{
    node temp, cur;
    int x;

    temp = getnode();
    printf("\nEnter element to insert: ");
    scanf("%d",&x);
    temp->info = x;

    if(header == NULL)
    {
        header = temp;
        return;
    }

    cur = header;
    while(cur->n != NULL)
        cur = cur->n;

    cur->n = temp;
    temp->p = cur;
}

/* INSERT TO LEFT OF GIVEN ELEMENT */
void insl()
{
    node temp, ele;
    int x, y;

    if(header == NULL)
    {
        printf("\nEmpty list");
        return;
    }

    printf("\nEnter element to be inserted: ");
    scanf("%d",&y);
    printf("\nInsert %d to left of which element? ", y);
    scanf("%d",&x);

    temp = getnode();
    temp->info = y;

    /* Case 1: insert before first node */
    if(header->info == x)
    {
        temp->n = header;
        header->p = temp;
        header = temp;
        return;
    }

    /* Case 2: insert before middle node */
    ele = header;
    while(ele != NULL && ele->info != x)
        ele = ele->n;

    if(ele != NULL)
    {
        temp->p = ele->p;
        temp->n = ele;
        ele->p->n = temp;
        ele->p = temp;
    }
    else
        printf("\nElement not found");
}

/* DELETE A GIVEN ELEMENT */
void del()
{
    node cur;
    int x;

    if(header == NULL)
    {
        printf("\nEmpty list");
        return;
    }

    printf("\nEnter element to delete: ");
    scanf("%d",&x);

    cur = header;

    /* Search element */
    while(cur != NULL && cur->info != x)
        cur = cur->n;

    if(cur == NULL)
    {
        printf("\nElement not found");
        return;
    }

    /* If first node */
    if(cur == header)
    {
        header = cur->n;
        if(header != NULL)
            header->p = NULL;
        free(cur);
        return;
    }

    /* If last node */
    if(cur->n == NULL)
    {
        cur->p->n = NULL;
        free(cur);
        return;
    }

    /* Middle node */
    cur->p->n = cur->n;
    cur->n->p = cur->p;
    free(cur);
}

/* DISPLAY LIST */
void disp()
{
    node temp;

    if(header == NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nList elements: ");
    temp = header;
    while(temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->n;
    }
}
