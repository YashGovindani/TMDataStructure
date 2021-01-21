#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long myPow(int base,int power)
{
// at current stage the logic works only for positive number and positve power
int subPower;
long subValue1,subValue2;
if(power==1) return base;
subPower=power/2;
subValue1=myPow(base,subPower);
if(power%2) subValue2=subValue1*((long)base);
else subValue2=subValue1;
return subValue1*subValue2;
}

typedef struct __$__combination
{
char *key;
long keyLength;
char *currentValue;
long valueLength;
long *indexes;
long currentIndex;
long count;
}Combination;

void initCombination(Combination *combination,const char *key,long valueLength)
{
long i;
combination->keyLength=strlen(key);
combination->key=(char *)malloc(sizeof(char)*(combination->keyLength+1));
strcpy(combination->key,key);
combination->currentValue=(char *)malloc(sizeof(char)*(valueLength+1));
combination->valueLength=valueLength;
for(i=0;i<valueLength;i++) combination->currentValue[i]=key[0];
combination->currentValue[i]='\0';
combination->indexes=(long *)malloc(sizeof(long)*(valueLength));
for(i=0;i<valueLength;i++) combination->indexes[i]=0;
combination->currentIndex=0;
combination->count=myPow(combination->keyLength,valueLength);
}

int hasNext(Combination *combination)
{
return combination->currentIndex<combination->count;
}

void getNext(Combination *combination,char *str)
{
long i;
if(!hasNext(combination)) return;
for(i=combination->valueLength-1;i>=0;i--)
{
combination->indexes[i]++;
if(combination->indexes[i]<combination->keyLength) break;
combination->indexes[i]=0;
}
strcpy(str,combination->currentValue);
if(i<0) i++;
while(i<combination->valueLength)
{
combination->currentValue[i]=combination->key[combination->indexes[i]];
i++;
}
combination->currentIndex++;
}

void clear(Combination *combination)
{
free(combination->key);
free(combination->currentValue);
free(combination->indexes);
}

int main()
{
char str[4];
Combination *combination;
combination=(Combination *)malloc(sizeof(Combination));
initCombination(combination,"YASH",2);
while(hasNext(combination))
{
getNext(combination,str);
printf("%s\n",str);
}
clear(combination);
free(combination);
return 0;
}
