// Find the length of linked list //
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=0 , *newnode=0 , *temp , *nextnode;
    int choice , pos ,i , count=0;
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
    printf("Linked list \n");
    temp=head;
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
        count++;
    }
    printf("Length is %d" , count);
    return 0;
}
