#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

/* Function prototypes */
void push();
void pop();
void peek();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n================ STACK MENU ================\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Peek (Top element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/* PUSH operation */
void push()
{
    int value;
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push.\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

/* POP operation */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

/* PEEK operation */
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

/* DISPLAY operation */
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom):\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
