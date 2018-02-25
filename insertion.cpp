#include<stdio.h>
#include<cstring>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **head_ref,int new_data){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}

void printlist(struct node *n){
	while(n!='\0'){
		printf("%d\n",n->data);
		n=n->next;
	}
}


int main(){
	struct node *head=NULL;
	struct node *second=NULL;
	struct node *third=NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	
	head->data=1;
	head->next=second;
	
	second->data=2;
	second->next=third;
	
	third->data=3;
	third->next=NULL;
	
	push(&head,5);
	printlist(head);
	return 0;
}

