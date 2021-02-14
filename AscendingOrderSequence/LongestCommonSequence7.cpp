#include<iostream>
#include<utility>
#include<queue>
using namespace std;
int main()
{
int x[9]={12,3,92,-3,76,54,12,93,78};
int flags[9]={0,0,0,0,0,0,0,0,0};
int e,f,prev,noel,maxss;
queue<queue<pair<int,int>>> list;
maxss=0;
for(e=0;e<=7;e++)
{
if(flags[e]) continue;
queue<pair<int,int>> queue;
noel=0;
prev=e;
for(f=e+1;f<=8;f++)
{
if(x[f]>x[prev])
{
queue.push(pair<int,int>(prev,x[prev]));
noel++;
prev=f;
flags[f]=1;
}
}
if(prev>e)
{
noel++;
if(noel<maxss) continue;
if(noel>maxss)
{
maxss=noel;
while(!list.empty()) list.pop();
}
queue.push(pair<int,int>(prev,x[prev]));
list.push(queue);
}
}
while(!list.empty())
{
queue<pair<int,int>> q=list.front();
list.pop();
while(!q.empty())
{
pair<int,int> p=q.front();
q.pop();
cout<<"("<<p.first<<") "<<p.second<<" ";
}
cout<<endl;
}
return 0;
}
