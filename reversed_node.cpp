#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

struct node{
    int id;
    struct node *next;
};

void push(struct node **head_ref,int id){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->id=id;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void printlist(struct node *n){
    while(n!=NULL){
        cout<<n->id<<endl;
        n=n->next;
    }
}

void reverse_node(struct node **head_ref){
    struct node *prev=NULL,*current=*head_ref,*next;
    while(current!=NULL){

        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head_ref=prev;
}

int main(){

    struct node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);


    printlist(head);

    reverse_node(&head);
    cout<<"Reversed linked list"<<endl;
    printlist(head);

    return 0;
}


