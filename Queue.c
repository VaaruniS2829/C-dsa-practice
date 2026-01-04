#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Function to check if queue is full */
int isFull() {
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

/* Function to check if queue is empty */
int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

/* Enqueue operation */
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

/* Dequeue operation */
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d removed from queue\n", queue[front]);
    front++;
}

/* Peek operation */
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

/* Display operation */
void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

/* Main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
