#include<iostream>
#include<cstring>
using namespace std;
struct node
{
  string name,ancestor;
  int son[100],val,cnt;
};
int f[100][2],n=0,head=0;
node p[100];
void dg(int);
int main()
{
  int i=0,j=0;
  for(cin>>n;i<n;i++)
  {
  	cin>>p[i].name>>p[i].val>>p[i].ancestor;
    if(p[i].ancestor=="NOBODY")
    {
      head=i;
	}
  }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  if(p[j].name==p[i].ancestor)
  	  {
  	    p[j].son[p[j].cnt++]=i;
  	    break;
	  }
	}
  }
  dg(head);
  cout<<max(f[head][0],f[head][1])<<endl;
  return 0;
}
void dg(int x)
{
  int i=0;
  f[x][0]=0;
  f[x][1]=p[x].val;
  for(;i<p[x].cnt;i++)
  {
  	dg(p[x].son[i]);
  	f[x][0]+=max(f[p[x].son[i]][1],f[p[x].son[i]][0]);
  	f[x][1]+=f[p[x].son[i]][0];
  }
  return;
}
