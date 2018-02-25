#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};



int flag=0;
void search_node(struct node *temp,int key){
struct node *prev_node;
	if(temp!=NULL && temp->data==key){
	 cout<<"Found"<<endl;
	 return;
	}
	
	while(temp!=NULL && temp->data!=key){
		prev_node=temp;
		temp=temp->next;
		flag++;
	}
	
	if(temp==NULL || flag==0){
	 cout<<"Not Found"<<endl;
	 return;
	}
	
	if(flag!=0){
		cout<<"Found"<<endl;
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
	
	search_node(head,2);

	return 0;
}


