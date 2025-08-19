// reversing a linked list //
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=0 , *newnode=0 , *temp , *nextnode , *prevnode=0 , *currentnode;
    int choice , pos ,i;
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
    printf("Linked list before reversing :\n");
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
    currentnode=nextnode=head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
    temp=head;
    printf("Linked list after reversing :\n");
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
     return 0;
}
