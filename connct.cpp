#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

struct Node{
	int id;
	struct Node *next;
};


void printlist(struct Node *n){
	while(n!=NULL){
		cout<<n->id<<endl;
		n=n->next;
	}
}

int main(){
	struct Node* head=NULL;
	struct Node* second=NULL;
	struct Node* third=NULL;
	
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	
	head->id=1;
	head->next=second;
	second->id=2;
	second->next=third;
	third->id=3;
    third->next=NULL;
    
	printlist(head);
		
	return 0;
}
