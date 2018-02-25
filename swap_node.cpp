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

void swap_node(struct node **head_ref,int x,int y){
    if(x==y)
        return;
    struct node *prevx=NULL,*currx=*head_ref;
    while(currx!=NULL && currx->id!=x){
        prevx=currx;
        currx=currx->next;
    }

    struct node *prevy=NULL,*curry=*head_ref;
    while(curry!=NULL && curry->id!=y){
        prevy=curry;
        curry=curry->next;
    }

    if(currx==NULL || curry==NULL)
        return;
    if(prevx!=NULL)
        prevx->next=curry;
    else
        *head_ref=curry;

    if(prevy!=NULL)
        prevy->next=currx;
    else
        *head_ref=currx;

    struct node *temp=curry->next;
    curry->next=currx->next;
    currx->next=temp;

}

int main(){

    struct node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    cout<<"Before swapping"<<endl;
    printlist(head);

    swap_node(&head,1,5);
    cout<<"After swapping"<<endl;
    printlist(head);

    return 0;
}

