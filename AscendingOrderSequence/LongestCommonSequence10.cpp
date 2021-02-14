#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
using namespace std;

int isByteOn(int num,int n)
{
return (num>>n)&1;
}

string getSubsequence(char *s,int length,int num)
{
int i;
string toBeReturned;
for(i=length-1;i>=0;i--)
{
if(isByteOn(num,i)) toBeReturned.insert(0,1,s[i]);
}
return toBeReturned;
}

char * longestCommonSequence(char *left,char *right)
{
int lLength,rLength,lLimit,rLimit,lsSize,rsSize,maxSize,e,f;
string ls,rs,toBeReturned;
char *temp;
lLength=strlen(left);
rLength=strlen(right);
lLimit=pow(2,lLength)-1;
rLimit=pow(2,rLength)-1;
maxSize=toBeReturned.size();
for(e=1;e<=lLimit;e++)
{
ls=getSubsequence(left,lLength,e);
lsSize=ls.size();
if(lsSize>maxSize)
{
for(f=1;f<=rLimit;f++)
{
rs=getSubsequence(right,rLength,f);
rsSize=rs.size();
if(lsSize==rsSize && ls.compare(rs)==0)
{
toBeReturned=ls;
maxSize=lsSize;
}
}
}
ls.clear();
rs.clear();
}
temp=new char[toBeReturned.size()+1];
strcpy(temp,toBeReturned.data());
return temp;
}

int main()
{
char left[10]="xjfwds";
char right[10]="tjidws";
char *lcs;
lcs=longestCommonSequence(left,right);
cout<<lcs<<endl;
free(lcs);
return 0;
}
