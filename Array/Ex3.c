#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Point {

 double x,y;
 
 } Point;

double distance(struct Point a, struct Point b) {
	double distance= (sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
	printf("The distance is %lf",distance);
}

int main(int argc, char *argv[]) {
	struct Point a,b;
		printf("Enter coordinates of a ");
		scanf("%lf %lf",&a.x,&a.y);
		printf("Enter coordinates of b ");
		scanf("%lf %lf",&b.x,&b.y);

		
		distance(a,b);
		
	
		
	
	return 0;
}
