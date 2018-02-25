#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

struct node{
    int id;
    struct node *next;
}*LLone,*LLtwo,*Mergelist;

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

struct node *mergelinked_list(struct node *LLone,struct node *LLtwo){
    struct node *resulthead,*resulttail,*temp;
    resulthead=resulttail=NULL;

    while(1){

        if(LLone==NULL){
        resulttail->next=LLtwo;
        break;
    }

     if(LLtwo==NULL){
        resulttail->next=LLone;
        break;
    }

    if(LLone->id<=LLtwo->id){
        temp=LLone;
        LLone=LLone->next;
    }
    else{
        temp=LLtwo;
        LLtwo=LLtwo->next;
    }

    if(resulthead==NULL){
        resulthead=resulttail=temp;
    }
    else{
        resulttail->next=temp;
        resulttail=temp;
    }
    resulttail->next=NULL;

    }

    return resulthead;
};


int main(){

    LLone=LLtwo=Mergelist=NULL;

    push(&LLone,10);
    push(&LLone,8);
    push(&LLone,5);
    push(&LLone,3);

    cout<<"First linked list"<<endl;
    printlist(LLone);

    push(&LLtwo,9);
    push(&LLtwo,7);
    push(&LLtwo,4);
    push(&LLtwo,1);

    cout<<"First linked list"<<endl;
    printlist(LLtwo);

    Mergelist=mergelinked_list(LLone,LLtwo);
    cout<<"Merged linked list"<<endl;
    printlist(Mergelist);
    return 0;
}

