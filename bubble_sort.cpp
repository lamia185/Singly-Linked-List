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

void swap_node(struct node *a,struct node *b){
    int temp=a->id;
    a->id=b->id;
    b->id=temp;
}

void bubble_sort(struct node *n){
    int swapped,i;
    struct node *ptr=n,*lptr=NULL;

    if(ptr==NULL)
        return;

    do{
        swapped=0;
        ptr=n;
        while(ptr->next!=NULL){
            if(ptr->id>ptr->next->id){
                swap_node(ptr,ptr->next);
                swapped=1;
            }
            ptr=ptr->next;
        }
     //   lptr=ptr;
    }
    while(swapped);
}



int main(){

    struct node *head=NULL;
    push(&head,2);
    push(&head,4);
    push(&head,6);
    push(&head,9);
    push(&head,1);


    printlist(head);

    bubble_sort(head);
    cout<<"Sorted linked list"<<endl;
    printlist(head);

    return 0;
}


