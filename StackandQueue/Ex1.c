#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	char can;
	struct Node *pnext;
} *top=NULL;


void push(char can) {
	struct Node *node;
	node = (struct Node*)(malloc(sizeof*node));
	node->can=can;
	
	if (top == NULL) {
		node->pnext=NULL;
	}
	else
		node->pnext=top;
	top=node;
	printf("%c is pushed\n",node->can);
}

void pop()
{	

   if(top == NULL)
      printf("\nStack is empty\n");
   else{
      struct Node *temp = top;
    
      printf("%c", temp->can);
      top = temp->pnext;
      free(temp);
   }
}

/*void display()
{
   if(top == NULL)
      printf("\nStack is Empty\n");
   else{
      struct Node *temp = top;
      while(temp->pnext != NULL){
	 printf("%c--->",temp->letter);
	 temp = temp -> pnext;
      }
	  printf("%c--->NULL",temp->letter);
   }
}   */
int main(int argc, char *argv[]) {
	printf("Fried Meat\n\n");
	char str[50];
	printf("Enter name ");
	gets(str);
	
	int length=strlen(str);
	int i;
	
	for (i=0;i<length;i++) {
		push(str[i]);
	}
	
	 printf("The reverse name is : ");
	for (i=0;i<length;i++) {
		pop();
	}

	
	return 0;
}
