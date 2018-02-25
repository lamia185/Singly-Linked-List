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

void palindrome(struct node *n){
    struct node *first,*second;
    first=n;
    second=NULL;

    while(first!=NULL){
        push(&second,(first->id));
        first=first->next;
    }
    first=n;

    while(first!=NULL){
        if(first->id!=second->id){
            cout<<"Not Palindrome"<<endl;
            flag=1;
            return;
        }
        first=first->next;
        second=second->next;

    }
    if(flag==0)
    cout<<"Palindrome"<<endl;

}

int main(){

    struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    palindrome(head);


    return 0;
}

