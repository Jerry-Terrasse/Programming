#include<iostream>
#include "memory.h"
#include<queue>
#define MAXN 30030
#define MAXT 8
using namespace std;
int dgr[MAXN],t=0,n=0,m=0;
vector<int>e[MAXT][MAXN];
priority_queue<int,vector<int>,greater<int> >q;
//inline void clear(priority_queue<int,vector<int>,greater<int> >&);
inline void read(int&);//only belong N+
int main()
{
  int i=0,j=0,u=0,v=0;
  for(read(t);t--;)
  {
	memset(dgr,0,sizeof(dgr));
	for(read(n),read(m);m--;)
	{
	  read(u);read(v);
	  e[t][u].push_back(v);
	  dgr[v]++;
	}
	for(i=1;i<=n;i++)
	{
	  if(!dgr[i])
	  {
	  	q.push(i);
	  }
	}
	for(;q.size();)
	{
	  i=q.top();
	  q.pop();
	  cout<<i<<' ';
	  for(j=0;j<e[t][i].size();j++)
	  {
	  	dgr[e[t][i][j]]--;
		if(!dgr[e[t][i][j]])
	  	{
	  	  q.push(e[t][i][j]);
		}
	  }
	}
	cout<<endl;
  }
  return 0;
}
inline void read(int &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  return;
}
/*inline void clear(priority_queue<int,vector<int>,greater<int> > &q)
{
  priority_queue<int,vector<int>,greater<int> >empty;
  swap(empty,q);
  return;
}*/
