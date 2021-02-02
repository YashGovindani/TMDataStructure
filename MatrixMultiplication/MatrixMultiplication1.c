#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int** matrixMultiplication(int x1[4][4],int x2[4][4],int rc1,int cc1,int rc2,int cc2)
{
int i,ci,ri,num;
int **toBeReturned;
if(cc1!=rc2) return NULL;
toBeReturned=(int **)malloc(sizeof(int *)*rc1);
for(ri=0;ri<rc1;ri++)
{
toBeReturned[ri]=(int *)malloc(sizeof(int)*cc2);
for(ci=0;ci<cc2;ci++)
{
num=0;
for(i=0;i<cc1;i++) num+=x1[ri][i]*x2[i][ci];
toBeReturned[ri][ci]=num;
}
}
return toBeReturned;
}

int main()
{
int x1[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int x2[4][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}};
int **resultant;
int rowCount1,rowCount2,columnCount1,columnCount2,i,j;
rowCount1=4;
columnCount1=4;
rowCount2=4;
columnCount2=4;
resultant=matrixMultiplication(x1,x2,rowCount1,columnCount1,rowCount2,columnCount2);
for(i=0;i<rowCount1;i++)
{
for(j=0;j<columnCount2;j++) printf("%5d ",resultant[i][j]);
printf("\n");
}
return 0;
}
