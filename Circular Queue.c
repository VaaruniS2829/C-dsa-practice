#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

/* Insert element into circular queue */
void enqueue(int x)
{
    if ((front == (rear + 1) % SIZE))
    {
        printf("Circular Queue is FULL\n");
        return;
    }

    if (front == -1)   // first insertion
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    cq[rear] = x;
    printf("Inserted: %d\n", x);
}

/* Delete element from circular queue */
void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if (front == rear)   // only one element
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

/* Display circular queue */
void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = front;
    while (1)
    {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

/* Main function */
int main()
{
    int choice, x;

    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
