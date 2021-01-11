#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void shellSort(void *x,int lb,int ub,int elementSize,long (*p2f)(void *,void *))
{
int size,diff,e,f;
void *data;
data=(void *)malloc(elementSize);
size=ub-lb+1;
diff=size/2;
while(diff>=1)
{
e=lb+diff;
while(e<=ub)
{
memcpy(data,x+(elementSize*e),elementSize);
f=e-diff;
while(f>=lb && p2f(x+(elementSize*f),data)>0)
{
memcpy(x+(elementSize*(f+diff)),x+(elementSize*f),elementSize);
f-=diff;
}
memcpy(x+(elementSize*(f+diff)),data,elementSize);
e+=diff;
}
diff/=2;
}
}

long longComparator(void *left,void *right)
{
return (*((long *)left))-(*((long *)right));
}

typedef struct _fragment
{
FILE *file;
char *fileName;
long size;
long num;
int completed;
}Fragment;

typedef struct _fragments
{
Fragment *ptr;
int count;
}Fragments;

long getFileLength(const char *fileName)
{
FILE *file;
long length;
file=fopen(fileName,"rb");
fseek(file,0,SEEK_END);
length=ftell(file);
fclose(file);
return length;
}

int fileExists(const char *fileName)
{
FILE *file;
file=fopen(fileName,"rb");
if(file)
{
fclose(file);
return 1;
}
else return 0;
}

void initFragment(Fragment *fragment,long chunkSize,long chunkCount,FILE *source)
{
char name[21];
long buffer[chunkCount];
int i;
long bytesRead;
i=0;
while(1)
{
sprintf(name,"tmp%d",i);
if(!fileExists(name)) break;
i++;
}
printf("Creating fragment with name : %s\n",name);
printf("Press enter to continue");
getchar();
fragment->fileName=(char *)malloc(sizeof(char)*(strlen(name)+1));
strcpy(fragment->fileName,name);
fragment->file=fopen(name,"wb");
bytesRead=fread(buffer,chunkSize,chunkCount,source);
fragment->size=bytesRead;
printf("Sorting to be started\n");
printf("Press enter to continue");
getchar();
shellSort(buffer,0,chunkCount,chunkSize,longComparator);
fwrite(buffer,chunkSize,bytesRead/chunkSize,fragment->file);
fclose(fragment->file);
fragment->completed=0;
printf("\nFragment created with\n name : %s, size : %ld\n",name,bytesRead);
printf("Press Enter to print fragment");
getchar();
fragment->file=fopen(name,"rb");
while(1)
{
fread(&bytesRead,sizeof(bytesRead),1,fragment->file);
if(feof(fragment->file)) break;
printf("%ld\n",bytesRead);
}
fclose(fragment->file);
}

Fragments * getSortedFragments(const char *target,int blockSize)
{
Fragments *fragments;
long fileLength;
long chunkCount;
int y;
FILE *file;
fragments=(Fragments *)malloc(sizeof(Fragments));
fileLength=getFileLength(target);
fragments->count=10;
if(fileLength%(blockSize*10)) fragments->count++;
printf("Fragments count : %d\n",fragments->count);
fragments->ptr=(Fragment *)malloc(sizeof(Fragment)*fragments->count);
file=fopen(target,"rb");
chunkCount=fileLength/(10*blockSize);
for(y=0;y<fragments->count;y++) initFragment(fragments->ptr+y,blockSize,chunkCount,file);
fclose(file);
return fragments;
}

void externalMerge(const char *targetName,Fragments *fragments)
{
FILE *target;
Fragment *fragment;
int i,si;
target=fopen(targetName,"wb");
for(i=0;i<fragments->count;i++)
{
fragment=fragments->ptr+i;
fragment->file=fopen(fragment->fileName,"rb");
fread(&fragment->num,sizeof(fragment->num),1,fragment->file);
if(feof(fragment->file)) fragment->completed=1;
}
while(1)
{
for(si=0;si<fragments->count && fragments->ptr[si].completed;si++);
if(si==fragments->count) break;
for(i=si+1;i<fragments->count;i++)
{
if(!fragments->ptr[i].completed && fragments->ptr[i].num<fragments->ptr[si].num) si=i;
}
printf("%ld\n",fragments->ptr[si].num);
fwrite(&fragments->ptr[si].num,sizeof(long),1,target);
fragment=fragments->ptr+si;
fread(&fragment->num,sizeof(fragment->num),1,fragment->file);
if(feof(fragment->file)) fragment->completed=1;
}
for(i=0;i<fragments->count;i++)
{
fragment=fragments->ptr+i;
fclose(fragment->file);
}
fclose(target);
}

void clearFragments(Fragments *fragments)
{
int i;
for(i=0;i<fragments->count;i++) remove(fragments->ptr[i].fileName);
free(fragments->ptr);
}

void externalSort(const char *fileToBeSorted)
{
Fragments *fragments;
if(!fileExists(fileToBeSorted)) return;
printf("Sorted fragment creation to be started\n");
fragments=getSortedFragments(fileToBeSorted,sizeof(long));
printf("Got sorted fragments\n");
printf("Starting external merge\n");
externalMerge(fileToBeSorted,fragments);
printf("External merge completed\n");
printf("Clearing fragments\n");
clearFragments(fragments);
printf("Fragments cleared\n");
free(fragments);
}

int main()
{
externalSort("tmp.tmp");
return 0;
}
