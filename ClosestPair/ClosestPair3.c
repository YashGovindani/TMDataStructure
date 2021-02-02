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

ClosestPair * checkWithMidX(Point *points,ClosestPair *pair,int lb,int mid,int ub)
{
int start,end,i,j,dx,dy,ep;
double dist;
for(start=lb,ep=points[mid].x-pair->dist;points[start].x<ep && start<=mid;start++);
for(end=mid+1,ep=points[mid].x+pair->dist;points[end].x<ep && end<=ub;end++)
for(i=start;i<=mid;i++)
{
for(j=mid+1;j<=end;j++)
{
dx=points[j].x-points[i].x;
dy=points[j].y-points[i].y;
dist=sqrt((dx*dx)+(dy*dy));
if(dist<pair->dist)
{
pair->point1=&points[i];
pair->point2=&points[j];
pair->dist=dist;
}
}
}
return pair;
}

ClosestPair * closest(Point *points,int lb,int ub)
{
int mid,length,dx,dy;
double dist1,dist2;
ClosestPair *pair,*pair1,*pair2;
length=ub-lb+1;
mid=((lb+ub)/2);
if(length<=3)
{
pair=(ClosestPair *)malloc(sizeof(ClosestPair));
pair->point1=&points[lb];
pair->point2=&points[ub];
dx=points[ub].x-points[lb].x;
dy=points[ub].y-points[lb].y;
pair->dist=sqrt((dx*dx)+(dy*dy));
if(length==3)
{
dx=points[mid].x-points[lb].x;
dy=points[mid].y-points[lb].y;
dist1=sqrt((dx*dx)+(dy*dy));
dx=points[mid].x-points[ub].x;
dy=points[mid].y-points[ub].y;
dist2=sqrt((dx*dx)+(dy*dy));
if(dist1<pair->dist && dist1<dist2)
{
pair->point2=&points[mid];
pair->dist=dist1;
}
else if(dist2<pair->dist && dist2<dist1)
{
pair->point1=&points[mid];
pair->dist=dist2;
}
}
return pair;
}
pair1=closest(points,lb,mid);
pair2=closest(points,mid+1,ub);
if(pair1->dist<pair2->dist)
{
free(pair2);
pair=pair1;
}
else
{
free(pair1);
pair=pair2;
}
return checkWithMidX(points,pair,lb,mid,ub);
}

int main()
{
Point *points;
Point *point1,*point2;
ClosestPair *pair;
points=(Point *)malloc(sizeof(Point)*22);
getInput(points);
quickSort(points,0,21,sizeof(Point),comparator);
pair=closest(points,0,21);
point1=pair->point1;
point2=pair->point2;
printf("nearest : (%d,%d),(%d,%d)-> %f\n",point1->x,point1->y,point2->x,point2->y,pair->dist);
free(points);
free(pair);
return 0;
}
