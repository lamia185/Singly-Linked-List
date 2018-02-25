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

int getNth(struct node *n,int index){
    struct node *current=n;
    int coun=0;
     while(current!=NULL){
        if(coun==index){
            return current->id;
        }
        current=current->next;
        coun++;
}
if(index>coun){
    cout<<"Element doesn't exist"<<endl;
    return 0;
}

    //assert(0);
    }

int main(){

    struct node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    printlist(head);

    cout<<"Element at index 6: "<<getNth(head,6)<<endl;


    return 0;
}
