//Project about linked list
//insertion,detetaion,searching
//Written by Lamia Akter

#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

struct node{
	char name[30];
	int id;
	struct node *next;
};

void showing(struct node *n){
	while(n!=NULL){
		puts(n->name);
		cout<<n->id<<endl;
		n=n->next;
	}
}

void front_insert(struct node **head_ref){
	char name[30];
	int id;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	cout<<"Insert new name:"<<endl;
	gets(new_node->name);
	cout<<"Insert new id:"<<endl;
	cin>>new_node->id;
	new_node->next=*head_ref;
	*head_ref=new_node;
	
	
}

void middle_insert(struct node *prev_node){
	char name[30];
	int id;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	cout<<"Insert new name:"<<endl;
	cin.ignore();
	gets(new_node->name);
	fflush(stdin);
	cout<<"Insert new id:"<<endl;
	fflush(stdin);
	cin>>new_node->id;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
	

}

void end_insert(struct node *prev_node){
	char name[30];
	int id;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	cout<<"Insert new name:"<<endl;
	gets(new_node->name);
	cout<<"Insert new id:"<<endl;
	cin>>new_node->id;
	prev_node->next=new_node;
	new_node->next=NULL;
	
}

void delete_id(struct node **head_ref){
	struct node *temp=*head_ref,*prev_node;
	
	int key;
	cout<<"Input the key:"<<endl;
	cin>>key;
	
	if(temp!=NULL && temp->id==key){
		*head_ref=temp->next;
		free(temp);
		return;
	}
	
	while(temp!=NULL && temp->id!=key){
		prev_node=temp;
		temp=temp->next;
	}
	
	if(temp==NULL){
		return;
	}
	
	prev_node->next=temp->next;
	free(temp);
	
}


void delete_name(struct node **head_ref){
	struct node *temp=*head_ref,*prev_node;
	
	char key[30];
	cout<<"Input the key:"<<endl;
	cin>>key;
	
	if(temp!=NULL && (strcmp(temp->name,key)==0)){
		*head_ref=temp->next;
		free(temp);
		return;
	}
	
	while(temp!=NULL && (strcmp(temp->name,key)!=0)){
		prev_node=temp;
		temp=temp->next;
	}
	
	if(temp==NULL){
		return;
	}
	
	prev_node->next=temp->next;
	free(temp);
	
}

void search_id(struct node *temp){
	struct node *prev_node;
	int key,flag=0;
	cout<<"Input the key"<<endl;
	cin>>key;
	
	if(temp!=NULL && temp->id==key){
		cout<<"Found"<<endl;
		return;
	}
	
	while(temp!=NULL && temp->id!=key){
		prev_node=temp;
		temp=temp->next;
        flag++;
	}
	
	if(temp==NULL || flag==0){
		cout<<"Not found"<<endl;
		return;
	}	
	
	if(flag!=0){
		cout<<"Found"<<endl;
		return;
	}
}


void search_name(struct node *temp){
	struct node *prev_node;
	char key[30],flag=0;
	cout<<"Input the key"<<endl;
	cin>>key;
	
	if(temp!=NULL && (strcmp(temp->name,key)==0)){
		cout<<"Found"<<endl;
		return;
	}
	
	while(temp!=NULL && (strcmp(temp->name,key)!=0)){
		prev_node=temp;
		temp=temp->next;
        flag++;
	}
	
	if(temp==NULL || flag==0){
		cout<<"Not found"<<endl;
		return;
	}	
	
	if(flag!=0){
		cout<<"Found"<<endl;
		return;
	}
}


int main(){
	
	int n;
	cout<<"WELCOME"<<endl;
	cout<<"Menu Panel"<<endl;
	cout<<"1.Showing"<<endl;
	cout<<"2.Front Insertion"<<endl;
	cout<<"3.Middle Insertion"<<endl;
	cout<<"4.End Insertion"<<endl;
	cout<<"5.Deletation by name"<<endl;
	cout<<"6.Deletation by id"<<endl;
	cout<<"7.Searching by name"<<endl;
	cout<<"8.Searching by id"<<endl;
	cout<<"Choose your option"<<endl;
	
	struct node *head=NULL;
	struct node *second=NULL;
	struct node *third=NULL;
	struct node *forth=NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	forth=(struct node*)malloc(sizeof(struct node));
	
	cout<<"Insert name:"<<endl;
	gets(head->name);
	cout<<"Insert id:"<<endl;
	cin>>head->id;
	cin.ignore();
	
	cout<<"Insert name:"<<endl;
	gets(second->name);
	cout<<"Insert id:"<<endl;
	cin>>second->id;
	cin.ignore();
	second->next=third;
	
	cout<<"Insert name:"<<endl;
	gets(third->name);
	cout<<"Insert id:"<<endl;
	cin>>third->id;
	cin.ignore();
	third->next=forth;
	
	cout<<"Insert name:"<<endl;
	gets(forth->name);
	cout<<"Insert id:"<<endl;
	cin>>forth->id;
	cin.ignore();
	
	head->next=second;
	second->next=third;
	third->next=forth;
 	forth->next=NULL;
	while(n){
	cin>>n;
	cin.ignore();
	switch(n){
		case 1:
			showing(head);
			break;
		case 2:
			front_insert(&head);
			break;
		case 3:
		    middle_insert(head);
		    break;
		case 4:
			end_insert(head);
			break;
		case 5:
			delete_name(&head);
			break;
		case 6:
			delete_id(&head);
			break;
		case 7:
			search_id(head);
			break;
		case 8:
			search_name(head);
			break;
	    default:
	    	break;
	}
}


}
