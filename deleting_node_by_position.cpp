#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct node{
   int data;
   struct node *next;
};

void printlist(struct node *n){
    while(n!=NULL){
        cout<<n->data<<endl;
        n=n->next;
    }
}

void delete_node(struct node **head_ref,int position){
     if(*head_ref==NULL)
        return;

     struct node *temp=*head_ref;

     if(position==0){
        *head_ref=temp->next;
        free(temp);
        return;
     }

     for(int i=0;temp!=NULL && i<position-1;i++)
        temp=temp->next;

     if(temp==NULL || temp->next==NULL)
        return;

     struct node *next=temp->next->next;
     free(temp->next);
     temp->next=next;

}

int main(){

    int n;
    struct node *head=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    struct node *forth=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=forth;
    forth->data=4;
    forth->next=NULL;

    cout<<"Before delete"<<endl;
    printlist(head);

    cout<<"Position you want to delete"<<endl;
    cin>>n;
    delete_node(&head,n);

    cout<<"After delete node by position"<<endl;
    printlist(head);
}
