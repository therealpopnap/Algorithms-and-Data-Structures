#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct _Node { //Node's defenition
 	int number;
 	char name[50];
 	struct _Node *pnext; 
 	
} Node; 

Node* initNode(int songuoi, char name[]) { //Initialize a node
	Node* node = (Node*)malloc(sizeof*node);
	node->number=songuoi;
	strcpy(node->name,name);
	node->pnext=NULL;
	return node;
}

void display(Node *temp) { //Display trains
	while (temp != NULL) {
		if (temp->number!=-1){	
			printf("Train block %s has %d passenger(s)\n",temp->name, temp->number);
			temp=temp->pnext;
		}
		else temp=temp->pnext;
	}
	printf("\n");
}

void insert(Node *pHead, Node *newNode) { //Insert a train to the list
	
	 while (pHead->pnext != NULL) {
	 	pHead=pHead->pnext;
	 } 
	 pHead->pnext=newNode;
} 

void deleteMT(Node *pHead) { //Delete train blocks with 0 passenger
	Node *check, *save;
	int nextnumber;
	while (pHead->pnext != NULL) {
		check=pHead->pnext;
		nextnumber=check->number;
		if (nextnumber==0) {
			save=pHead->pnext;
			pHead->pnext=save->pnext;
			free(save);
	}
	else pHead=pHead->pnext;
	}
}

int main(int argc, char *argv[]) {
	Node *pHead=NULL, *a;
	int n,i,number,option,choice;
	char name[50];
	printf("Exercise 1 Linked List - Truong Si Thi Vu - Bi8-189\n");
	printf("\n");
	pHead=initNode(-1,name);
	printf("Enter the number of trains ");
	scanf("%d",&n);
	if (n==0) { 
		printf("Empty list\n");
	} 
	else {
	
	for (i=0;i<n;i++) {
		printf("Enter the name of train number %d ",i+1);
		scanf("%s",name);
		printf("Enter the number of passengers on block number %d ",i+1);
		scanf("%d",&number);
		
		a=initNode(number,name);
		insert(pHead,a);
	} }
	printf("Do you want to continue? Enter 1 for Yes or 0 for No ");
	scanf("%d",&choice);
	if (choice==1) {
	
	do {
	choice=0;
	printf("Enter 1 if you want to add a new train block\n");
	printf("Enter 2 if you want to delete empty train blocks\n");
	printf("Enter 3 if you want to display the train\n");
	printf("Enter 0 if you want to stop ");
	scanf("%d",&option);
		if (option==1) {
		printf("Enter the name of train number %d ",i+1);
		scanf("%s",name);
		printf("Enter the number of passengers on train block number %d ",i+1);
		scanf("%d",&number);
		
		a=initNode(number,name);
		insert(pHead,a);
	}
	
	if (option==2) {
		deleteMT(pHead);
	}
	
	if (option==3) {
		display(pHead);
	}

	printf("Do you want to continue? Enter 1 for yes or 0 for No");
	scanf("%d",&choice);
	} while(choice==1);
}

	return 0;
}
