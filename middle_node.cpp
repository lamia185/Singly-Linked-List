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

void print_middle(struct node *n,int length){
    int coun=0,l,m;
    m=length/2;
    struct node *current=n;
    while(current!=NULL){

        if(coun==m){
            l=current->id;
            cout<<"Middle element: "<<l<<endl;
            return;
        }
        else
            current=current->next;
             coun++;
    }
}

int main(){

    struct node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    printlist(head);

    print_middle(head,5);

    return 0;
}

