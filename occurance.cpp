
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

int occur(struct node *n,int index){
    int coun=0;
    struct node *current=n;

    while(current!=NULL){
        if(current->id==index){
            coun++;
        }
        current=current->next;
    }
    return coun;
}

int main(){

    struct node *head=NULL;
    push(&head,5);
    push(&head,1);
    push(&head,3);
    push(&head,2);
    push(&head,1);


    printlist(head);

    cout<<"1 occurance is: "<<occur(head,1)<<endl;

    return 0;
}

