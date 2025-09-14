Doubly linked list : To maintain tail pointer

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head , *tail;
void create();
void main(){
    create();
}
void create(){
    struct node*newnode , *head=0 ;
    int choice;
    while(choice){
    printf("Enter data:");
    scanf("%d" , &newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    printf("Do you want to continue(0,1)?");
    scanf("%d" , &choice);
}
}
