#include<bits/stdc++.h>
#include<cstring>
#include<stdlib.h>
using namespace std;


struct Node{
	int id;
	struct Node *next;
};

void delete_node(struct Node **head_ref){
	struct Node *temp = *head_ref,*prev;

	int key;
	puts("Enter id to delete");
	cin>>key;

	if(temp!=NULL && temp->id==key){
		*head_ref = temp->next;
        free(temp);
        return;
	}
	 while (temp != NULL && temp->id != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
	return;

    prev->next = temp->next;
    free(temp);

  }

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

    delete_node(&head);
	printlist(head);

	return 0;
}
