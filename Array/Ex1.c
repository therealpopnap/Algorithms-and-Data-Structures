#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b;

			printf("Enter 2 variables ");
			scanf("%lf %lf",&a,&b);
	double *pointera=&a, *pointerb=&b;
	double sum = *pointera + *pointerb;
			printf("Sum of 2 variables is %.3lf",sum);
	return 0;
}
