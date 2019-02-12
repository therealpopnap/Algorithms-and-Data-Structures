#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i;
	double sum=0.0;
	printf("Enter n ");
	scanf("%d",&n);
		double a[n];
		for (i=0; i<n; i++) {
		
			printf("Enter %d elements of the array ",n);
			scanf("%lf",&a[i]);
		}
	
	double *pointer=&a;
	
		for (i=0; i<n; i++) {
			sum += *pointer;
			pointer++;
		}
			printf("The sum of %d elements of the array is %lf ",n,sum);
	return 0;
}
