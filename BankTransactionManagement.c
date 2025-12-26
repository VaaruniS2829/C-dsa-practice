#include <stdio.h>
#include <stdlib.h>

/* ---------- Structure ---------- */
struct node {
    int amount; // amount involved in transaction
    int type;   // 1 = deposit, 2 = withdraw
    struct node *next; 
};

/* ---------- Global Variables ---------- */
struct node *front = NULL, *rear = NULL;   // Queue
struct node *top = NULL;                   // Stack
struct node *head = NULL;                  // History
int balance = 0;

/* ---------- Add Transaction ---------- */
void addTransaction() {
    struct node *temp = malloc(sizeof(struct node));
    printf("Enter amount: ");
    scanf("%d", &temp->amount);
    printf("1.Deposit  2.Withdraw : ");
    scanf("%d", &temp->type);
    temp->next = NULL;

    if (rear == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
    printf("Transaction added to queue\n");
}

/* ---------- Process Transaction ---------- */
void processTransaction() {
    if (front == NULL) {
        printf("No pending transactions\n");
        return;
    }

    struct node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;

    if (temp->type == 1)
        balance += temp->amount;
    else if (temp->type == 2 && balance >= temp->amount)
        balance -= temp->amount;
    else {
        printf("Insufficient balance\n");
        free(temp);
        return;
    }

    /* Push to stack */
    temp->next = top;
    top = temp;

    /* Add to history */
    temp->next = head;
    head = temp;

    printf("Transaction processed successfully\n");
}

/* ---------- Undo Transaction ---------- */
void undoTransaction() {
    if (top == NULL) {
        printf("No transaction to undo\n");
        return;
    }

    struct node *temp = top;
    top = top->next;

    if (temp->type == 1)
        balance -= temp->amount;
    else
        balance += temp->amount;

    printf("Last transaction undone\n");
}

/* ---------- Display History ---------- */
void displayHistory() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("No transaction history\n");
        return;
    }

    printf("\nTransaction History:\n");
    while (temp != NULL) {
        if (temp->type == 1)
            printf("Deposit: %d\n", temp->amount);
        else
            printf("Withdraw: %d\n", temp->amount);
        temp = temp->next;
    }
}

/* ---------- Display Pending Transactions ---------- */
void pendingTransactions() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("No pending transactions\n");
        return;
    }

    printf("\nPending Transactions:\n");
    while (temp != NULL) {
        if (temp->type == 1)
            printf("Deposit: %d\n", temp->amount);
        else
            printf("Withdraw: %d\n", temp->amount);
        temp = temp->next;
    }
}

/* ---------- Main Function ---------- */
int main() {
    int choice;

    while (1) {
        printf("\n--- BANK MANAGEMENT SYSTEM ---");
        printf("\n1.Add Transaction");
        printf("\n2.Process Transaction");
        printf("\n3.Undo Transaction");
        printf("\n4.View History");
        printf("\n5.View Pending Transactions");
        printf("\n6.View Balance");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTransaction(); break;
            case 2: processTransaction(); break;
            case 3: undoTransaction(); break;
            case 4: displayHistory(); break;
            case 5: pendingTransactions(); break;
            case 6: printf("Current Balance: %d\n", balance); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
