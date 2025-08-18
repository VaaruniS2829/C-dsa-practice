// Singly linked list : Deleting a node from beginning //
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=0 , *newnode=0 , *temp;
    int choice;
    while(choice){
        newnode =(struct node*)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d" , &newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue (0 for no and 1 for yes)?");
        scanf("%d" , &choice);
    }
    temp=head;
    printf("Linked list before deletion :\n");
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
    if(head->next==0){
    printf("Deletion is not possible\n");
    }
    else{
        temp=head;
        head=head->next;
    printf("Deleted Element : %d\n" , temp->data);
    free(temp);
    }
    printf("Linked list after deletion :\n");
    temp=head;
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
    return 0;
}

