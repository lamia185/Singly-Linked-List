#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

int flag=0;

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

void recurse(struct node *n){
    if(n==NULL)
        return;

    recurse(n->next);

    cout<<n->id<<endl;
}

int main(){

    struct node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    cout<<"Before recursive reverse"<<endl;
    printlist(head);

    cout<<"After recursive reverse"<<endl;
    recurse(head);

    return 0;
}

