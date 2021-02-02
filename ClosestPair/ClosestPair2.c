#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void quickSort(void *x,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
int stack[1024][2],top,pp,lb,ub,y,e,f,size;
void *g=malloc(es);
size=upperBound-lowerBound+1;
top=size;
top--;
stack[top][0]=lowerBound;
stack[top][1]=upperBound;
while(top!=size)
{
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(p2f(x+(e*es),x+(es*lb))<=0) e++;
while(p2f(x+(f*es),x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,x+(e*es),es);
memcpy(x+(e*es),x+(f*es),es);
memcpy(x+(f*es),g,es);
}
else
{
memcpy(g,x+(f*es),es);
memcpy(x+(f*es),x+(lb*es),es);
memcpy(x+(lb*es),g,es);
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
free(g);
}

typedef struct __$__point
{
int x;
int y;
}Point;

int comparator(void *left,void *right)
{
return (((Point *)left)->x)-(((Point *)right)->x);
}

void getInput(Point *points)
{
points[0].x=1;
points[1].x=1;
points[2].x=1;
points[3].x=2;
points[4].x=2;
points[5].x=3;
points[6].x=3;
points[7].x=4;
points[8].x=4;
points[9].x=5;
points[10].x=5;
points[11].x=6;
points[12].x=6;
points[13].x=7;
points[14].x=7;
points[15].x=8;
points[16].x=8;
points[17].x=9;
points[18].x=10;
points[19].x=10;
points[20].x=11;
points[21].x=11;
points[0].y=3;
points[1].y=6;
points[2].y=8;
points[3].y=3;
points[4].y=7;
points[5].y=5;
points[6].y=9;
points[7].y=8;
points[8].y=10;
points[9].y=7;
points[10].y=10;
points[11].y=6;
points[12].y=9;
points[13].y=4;
points[14].y=10;
points[15].y=3;
points[16].y=6;
points[17].y=4;
points[18].y=7;
points[19].y=10;
points[20].y=9;
points[21].y=11;
}

typedef struct __$__closest_pair
{
Point *point1;
Point *point2;
double dist;
}ClosestPair;

ClosestPair * closest(Point *points,int lb,int ub)
{
int i,j,dx,dy;
double dist;
ClosestPair *closestPair;
closestPair=(ClosestPair *)malloc(sizeof(ClosestPair));
i=lb;
j=lb+1;
closestPair->point1=&points[i];
closestPair->point2=&points[j];
dx=points[j].x-points[i].x;
dy=points[j].y-points[i].y;
closestPair->dist=sqrt((dx*dx)+(dy*dy));
for(i=lb;i<ub;i++)
{
for(j=i+1;j<=ub;j++)
{
dx=points[j].x-points[i].x;
dy=points[j].y-points[i].y;
dist=sqrt((dx*dx)+(dy*dy));
if(dist<closestPair->dist)
{
closestPair->point1=&points[i];
closestPair->point2=&points[j];
closestPair->dist=dist;
}
}
}
return closestPair;
}

int main()
{
Point *points;
Point *point1,*point2;
ClosestPair *pair1,*pair2;
points=(Point *)malloc(sizeof(Point)*22);
getInput(points);
quickSort(points,0,21,sizeof(Point),comparator);
pair1=closest(points,0,10);
pair2=closest(points,11,21);
if(pair1->dist<pair2->dist)
{
point1=pair1->point1;
point2=pair1->point2;
printf("Closest : (%d,%d),(%d,%d) dist : %f\n",point1->x,point1->y,point2->x,point2->y,pair1->dist);
}
else
{
point1=pair2->point1;
point2=pair2->point2;
printf("Closest : (%d,%d),(%d,%d) dist : %f\n",point1->x,point1->y,point2->x,point2->y,pair2->dist);
}
free(points);
free(pair1);
free(pair2);
return 0;
}
