Doubly linked list:Insert node at beginning

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*prev;
    struct node*next;
};
struct node*head , *tail,  *newnode=0 , *temp;
void create_dll();
void display();
void insert_at_beg();

void main(){
create_dll();
printf("Linked list before insertion:\n");
display();
insert_at_beg();
printf("Linked list after insertion :\n");
display();
}
void create_dll(){
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
            newnode->prev=temp;
            temp=newnode;
        }
        printf("Do you want to continue (0 for no and 1 for yes)?");
        scanf("%d" , &choice);
    }
}
void display(){
     temp=head;
    printf("Doubly linked list:\n");
    while(temp!=0){
        printf("%d\n" , temp->data);
        temp=temp->next;
    }
}
void insert_at_beg(){
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert");
    scanf("%d" , &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;

}
