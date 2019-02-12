#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node* nodePtr;
struct Node {
	int data;
	nodePtr pleft, pright, pparent;
};


nodePtr newNode(int data) {
	nodePtr node = (nodePtr)malloc(sizeof(struct Node));
	node->data=data;
	node->pleft=NULL;
	node->pright=NULL;

	return node;
}

nodePtr insert(nodePtr root, int data) {

	if (root==NULL) {
		root=newNode(data);
	}

	else if (data<=root->data) {
		root->pleft=insert(root->pleft,data);
	}

	else if (data>root->data) {
		root->pright=insert(root->pright,data);
	}

	return root;
}

int cnt = 0;
int id=0;

void initEmptyNodes(nodePtr cur, int cur_h, int max_h,int array[],int n)
{
int i;
 printf("ID: %10d || Current height: %10d\n", ++cnt, cur_h);
  if (cur_h == max_h) // This is leaf node.
  {
    // Put your code here so that
    // elements in the array should be assigned to cur->data for every leaf.    
	if (id==n) {
		cur->data=max(array,n);
		for (i=0; i<max_h; i++){
	cur->pparent->data=maxofsubleft(cur->pparent->pleft);
	cur=cur->pparent;
	}
	}
	else {
	cur->data=array[id];
    id=id+1;
	for (i=0; i<max_h; i++){
	cur->pparent->data=maxofsubleft(cur->pparent->pleft);
	cur=cur->pparent;
	}
}
    return;
  }
  cur->pleft = newNode(-1);
  cur->pleft->pparent=cur;
  initEmptyNodes(cur->pleft, cur_h + 1, max_h,array,n);
  cur->pright = newNode(-1);
  cur->pright->pparent=cur;
  initEmptyNodes(cur->pright, cur_h + 1, max_h,array,n);
}


int maxofsubleft(nodePtr root) 
{ 
  
    if (root == NULL) 
      return INT_MIN; 
  
    int temp = root->data; 
    int lefttemp = maxofsubleft(root->pleft); 
    int righttemp = maxofsubleft(root->pright); 
    if (lefttemp > temp) temp=lefttemp; 
    if (righttemp > temp) temp=righttemp;
    return temp; 
} 


void inorder(nodePtr root) {
	if (root!=NULL) {
		inorder(root->pleft);
		printf("%d ",root->data);
		inorder(root->pright);
	}
}

void postorder(nodePtr root) {
	if (root!=NULL) {
		postorder(root->pleft);
		postorder(root->pright);
		printf("%d ",root->data);
	}
}

void preorder(nodePtr root) {
	if (root!=NULL) {
		printf("%d ",root->data);
		preorder(root->pleft);
		preorder(root->pright);
	}
}

int max(int array[], int n) {
	int i;
	int max=array[0];
	for (i=0; i<n-1; i++) {
		if (max<array[i+1]) max=array[i+1];
	}
	return max;
}


int main(int argc, char *argv[]) {
	printf("To implement a different structure for the tree, we do the following\n");
	printf("Create an empty tree with height = log 2 of n (n=array length)\n");
	printf("Fill the array in all the leaf notes then build from the bottom\n");
	
	printf("\n");
	
	printf("Enter the number of elements in the array ");
	int n;
	scanf("%d",&n);
	int array[n];
	double temp=log(n);
	double temp2=log(2);
	double height=temp/temp2;
	double heighttemp=ceil(height);
	int h = heighttemp;

	nodePtr root=NULL;
	int i;
	printf("Enter the elements (NOTE: THE ARRAY MUST BE SORTED) ");
	for (i=0;i<n;i++) {
		scanf("%d",&array[i]);
	}


  root = newNode(-1);
  printf("\n");
  initEmptyNodes(root, 0, h,array,n);
	

	printf("\n");
	printf("In-order traversal is    "); inorder(root);
	printf("\n");
	printf("Pre-order traversal is   "); preorder(root);
	printf("\n");
	printf("Post-order traversal is  "); postorder(root);
	printf("\n");
	




	return 0;
}
