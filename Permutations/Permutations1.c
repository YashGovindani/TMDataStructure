#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void toDo(char *str)
{
printf("%s\n",str);
}

void __$__permutations(char *str,long start,long end,void (*p2f)(char *))
{
long i;
char g;
if(start==end)
{
p2f(str);
return;
}
for(i=start;i<=end;i++)
{
g=str[start];
str[start]=str[i];
str[i]=g;
__$__permutations(str,start+1,end,p2f);
g=str[start];
str[start]=str[i];
str[i]=g;
}
}

void permutations(char *str,void (*p2f)(char *))
{
__$__permutations(str,0,strlen(str)-1,p2f);
}

int main(int argc,char *argv[])
{
permutations(argv[1],toDo);
return 0;
}
