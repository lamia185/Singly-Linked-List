#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int id;
    struct node *next;
};

 void push(node **head_ref,int id){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->id=id;
    new_node->next=*head_ref;
    *head_ref=new_node;

 }

 void printlist(node *n){
    while(n!=NULL){
        cout<<n->id<<endl;
        n=n->next;
    }
 }

 void delete_node(node **head_ref,int position){
    int flag=0;

    node *temp=*head_ref,*prev_node;

    if(temp!=NULL && position==0){
        *head_ref=temp->next;
        free(temp);
        flag++;
        return;
    }

    while(temp!=NULL && flag!=position){
        prev_node=temp;
        temp=temp->next;
        flag++;
    }

    if(temp==NULL || temp->next==NULL)
        return;

    if(flag==position){
        prev_node->next=temp->next;
        free(temp);
    }
 }

int main(){
    int n;
    node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    cout<<"Before delete"<<endl;
    printlist(head);

    cout<<"Position you want to delete"<<endl;
    cin>>n;
    delete_node(&head,n);
    cout<<"After delete"<<endl;
    printlist(head);
}
