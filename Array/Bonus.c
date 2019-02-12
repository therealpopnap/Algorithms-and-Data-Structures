#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[9];
	int sum=0;
	int i;
	long int n;
	printf("Enter the code ");
	scanf("%d",&n);
	
	for (i=8; i>-1; i--){
	{
		a[i]= n % 10;
		n=n/10;
		if (n==0) break;
	}
	
}
	for (i=0; i<9; i++) {
	
	sum= sum + a[i] * (i+1);
}

	printf("%d",sum%11);
	return 0;
}
