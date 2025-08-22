//Singly linked list : Inserting a node at a given position 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=0 , *newnode=0 , *temp;
    int choice , pos , count=0 , i;
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
    printf("Linked list before insertion :\n");
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
        count++;
    }
    printf("Total number of nodes are:%d\n" , count);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position:\n");
    scanf("%d" , &pos);
    if(pos>count){
    printf("Invalid position\n");
    }
    else{
        temp=head;
        while(i<pos){
         temp=temp->next;
         i++;
        }
    }
    printf("Enter the data you want to insert:\n");
    scanf("%d" , &newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
    printf("Linked list after insertion :\n");
    temp=head;
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
    return 0;
}
