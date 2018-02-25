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

int detect_loop(struct node *n){
        int flag=0;
    struct node *slow_ptr=n,*fast_ptr=n;

    while(slow_ptr !=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;

        if(slow_ptr==fast_ptr){
            cout<<"Loop found"<<endl;
            flag=1;
            return 0;
        }

        if(flag==0){
            cout<"Loop doesn't found"<<endl;
            return 0;
        }

    }
    return 0;
}

int main(){

    struct node *head=NULL;
    push(&head,2);
    push(&head,4);
    push(&head,6);
    push(&head,9);
    push(&head,1);

    printlist(head);

    detect_loop(head);

    return 0;
}


