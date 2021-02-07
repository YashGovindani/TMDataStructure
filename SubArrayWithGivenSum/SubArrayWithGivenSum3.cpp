// Using Map
#include<iostream>
#include<map>

int main()
{
int x[]={4,-2,7,-6,9,3};
std::map<int,int> sumMap;
std::map<int,int>::iterator it;
int ei,si,sum,requiredSum;
requiredSum=8;
for(si=0,ei=0,sum=0;ei<=5;ei++)
{
sum+=x[ei];
if(sum==requiredSum) break;
it=sumMap.find(sum-requiredSum);
if(it!=sumMap.end())
{
si=it->second+1;
break;
}
sumMap[sum]=ei;
}
if(ei<=5) printf("(%d,%d)\n",si,ei);
else printf("Sub array with required sum does not exist\n");
return 0;
}
