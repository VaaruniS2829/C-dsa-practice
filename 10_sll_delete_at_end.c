Singly linked list delete node at end:

#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*head=0 , *newnode=0 , *temp , *prevnode=0;
void create_list();
void display_list();
void delete_at_end();
    
int main(){
     create_list();
     printf("Linked list before deletion\n");
     display_list();
     delete_at_end();
     printf("Linked list after deletion\n");
     display_list();
   
}
void create_list(){
    int choice;
    while(choice){
    newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d" , &newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue(0,1)?");
        scanf("%d" , &choice);
}
}
void display_list(){
    if(head==0){
        printf("List is Empty");
        return;
     }
    temp=head;
   
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void delete_at_end(){
    if(head==0){
        printf("List is Empty , nothing to delete\n");
        return;
     }
temp=head;
while(temp->next!=0){
    prevnode=temp;
    temp=temp->next;
}
if(temp==head){
    printf("Deleted:%d\n",head->data);
    head=0;
    free(head);
}
else{
    prevnode->next=0;
printf("Deleted:%d\n" , temp->data);
free(temp);
}
}
