#include <stdio.h>
#include <stdlib.h>

typedef struct _Node { //Node's definition
 	int coso,somu,size;
 	struct _Node *pnext; 
 	
} Node; 

Node* initNode(int coso, int somu) { //Initialize node with data = somu (degree) and coso (constant)
	Node* node = (Node*)malloc(sizeof*node);
	node->somu=somu;
	node->coso=coso;
	node->pnext=NULL;
	return node;
}
void display(Node *temp) { //Display function
	sort(temp);
	printf("f(x) = ");
	while (temp != NULL) {
		if (temp->coso != -1) {
			
			printf("%d*x^%d + ",temp->coso,temp->somu);
			temp=temp->pnext;
		}
	else temp=temp->pnext;
	}
}

int addsamedegree(Node *pHead, int somu, int coso) {
	int flag=0;	//test if there is already a term with the same degree
	while (pHead != NULL) {
		if (pHead->somu==somu) { //If Yes => add two constants
			flag=1;
			pHead->coso+=coso;
			break;
		} 
		pHead=pHead->pnext;
		
		}
	return flag; //return flag 
}


void deletedegree(Node *pHead,int somu) {
	Node *check, *save;
	int nextdegree;
	while (pHead->pnext != NULL) {
		check=pHead->pnext;
		nextdegree=check->somu;
		if (nextdegree==somu) {
			save=pHead->pnext;
			pHead->pnext=save->pnext;
			free(save);
	}
	else pHead=pHead->pnext;
	}
}

void insert(Node *pHead, Node *newNode) { //Insert node to the link 
	 pHead->size++;
	 while (pHead->pnext != NULL) {
	 	pHead=pHead->pnext;
	 } 
	 pHead->pnext=newNode;
}

long int power(int somu, int x) {
	int i,powerresult=1;
	for (i=0; i<somu; i++) {
		powerresult=powerresult*x;
	}
	return powerresult;
}

long int calculate(Node *pHead, int x) {
	long int sum=0;
	while (pHead !=NULL) {
		if (pHead->coso != -1) {
		sum+= pHead->coso * power(pHead->somu,x);
		pHead=pHead->pnext;
	} else pHead=pHead->pnext;
}
	return sum;
}

void swapcs(Node *a, Node *b) 
{ 
    int temp = a->coso; 
    a->coso = b->coso; 
    b->coso = temp; 
} 

void swapsm(Node *a, Node *b) 
{ 
    int temp = a->somu; 
    a->somu = b->somu; 
    b->somu = temp; 
} 

void sort(Node *pHead) {
	int i;
	Node *temp;
	temp=pHead;
	for (i=0; i< pHead->size; i++) {
		while (pHead->pnext != NULL) {
			if (pHead->somu > pHead->pnext->somu) {
				swapsm(pHead,pHead->pnext);
				swapcs(pHead,pHead->pnext);
			}
			pHead=pHead->pnext;
		} pHead=temp;
	}
}

int main(int argc, char *argv[]) {
	Node *pHead=NULL, *a;
	int n,i,coso,somu,option,choice,degree,x;
	pHead=initNode(-1,-1);
	pHead->size=0;
	
	printf("Exercise 2 Linked List - Truong Si Thi Vu - Bi8-189\n");
	printf("\n");
	printf("Do you want to continue? Enter 1 for Yes or 0 for No ");
	scanf("%d",&choice);
	if (choice==1) {
	
	do {
	choice=0;
	printf("Enter 1 if you want to add a new term\n");
	printf("Enter 2 if you want to delete a term\n");
	printf("Enter 3 if you want to display the function\n");
	printf("Enter 4 if you want to calculate the funciton ");
	scanf("%d",&option);
	
	if (option==1) {
		printf("Enter the constant of the term ");
		scanf("%d",&coso);
		printf("Enter the degree of the term ");
		scanf("%d",&somu);
		a=initNode(coso,somu); //Initialize node
		 
		if (addsamedegree(pHead,somu,coso)==0) { //If there are no same degrees then insert node to link
	
				insert(pHead,a);
		}
		
	}
	
	if (option==2) {
		printf("Enter the degree you want to delete ");
		scanf("%d",&degree);
		deletedegree(pHead,degree);
	}
	
	if (option==3) {
		display(pHead);
	}
	
	if (option==4) {
		printf("Enter x ");
		scanf("%d",&x);
		printf("The result of the function is %d",calculate(pHead,x));
	}

	printf("\nDo you want to continue? Enter 1 for Yes or 0 for No ");
	scanf("%d",&choice);
	} while(choice==1);
}
	return 0;

}
