#include<iostream>
#include<vector>
#include<queue>
#define MAXN 10010
#define pr pair<int,int>
using namespace std;
vector<pr>e[MAXN];
priority_queue<pr,vector<pr>,greater<pr> >q;
int d[MAXN],u[MAXN],n=0,s=0;
int main()
{
  int i=0,f=0,g=0,w=0;
  pr p=make_pair(0,0);
  for(cin>>n>>i>>s;i;i--)
  {
  	cin>>f>>g>>w;
  	e[f].push_back(make_pair(g,w));
  }
  for(i=1;i<=n;i++)
  {
  	d[i]=0x7fffffff;
  }
  d[s]=0;
  q.push(make_pair(0,s));
  for(;!q.empty();)
  {
  	p=q.top();
  	q.pop();
  	for(i=0;i<v[p.second].size();i++)
  	{
  	  
	}
  }
  return 0;
}
