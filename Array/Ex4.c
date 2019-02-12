#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Point {
	double x1,y1,x2,y2,x3,y3;
} point1, point2, point3;

void rectanglecheck(struct Point point1, struct Point point2) {
	double area=0;
	double side1,side2;
	side1=point1.x1-point2.x2;
	side2=point1.y1-point2.y2;
	
	if (side1<0) side1=-side1;
	if (side2<0) side2=-side2;
	area=side1*side2;
	if ((point1.x1==point2.x2) || (point1.y1==point2.y2)) {
	
		printf("No\n");
		printf("Re-enter coordinates of point 1 ");
		scanf("%lf %lf",&point1.x1,&point1.y1);
	 
		printf("Re-enter coordinates of point 2 ");
		scanf("%lf %lf",&point2.x2,&point2.y2);
	
		rectanglecheck(point1,point2);
	}
	else {
	
		printf("Yes\n");
		printf("The area is %lf\n",area);
		}
	}


int main(int argc, char *argv[]) {
	struct Point point1,point2,point3;
	printf("Enter coordinates of point 1 ");
	scanf("%lf %lf",&point1.x1,&point1.y1);
	 
	printf("Enter coordinates of point 2 ");
	scanf("%lf %lf",&point2.x2,&point2.y2);
	
	double maxy=point1.y1; 
	double miny=point2.y2;
	if (point2.y2>point1.y1) {maxy=point2.y2; miny=point1.y1;}
	
	double maxx=point1.x1; 
	double minx=point2.x2; 
	if (point2.x2>point1.x1) {maxx=point2.x2; minx=point1.x1;}
	
	rectanglecheck(point1,point2);
	
	printf("Enter coordinates of point 3 ");
	scanf("%lf %lf",&point3.x3,&point3.y3);


	if ((point3.x3<maxx) && (point3.x3>minx) && (point3.y3>miny) && (point3.y3<maxy)) 
	printf("1"); else printf("0"); 
	return 0;
}
