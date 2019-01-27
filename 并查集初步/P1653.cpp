#include<iostream>
using namespace std;
int emm[MAXN][2],num[MAXN],a[MAXN],us[MAXN],l[MAXN],r[MAXN],ans[MAXN],n=0,t=0;
int find(const int&);
int main()
{
  int i=0;
  cin>>n>>m;
  for(i=1;i<=n;++i)
  {
  	cin>>l[i]>>r[i];
  }
  for(i=1;i<=m;++i)
  {
  	cin>>num[i]>>a[i];
  	--a[i];
  	emm[num[i]][a[i]]=1;
  }
  for(i=1;i<=n;++i)
  {
  	us[i]=i;
  }
  for(i=1;i<=n;++i)
  {
  	if(l[i]!=-1&&!emm[i][0])
  	{
  	  us[us[find(i)]]=us[find(l[i])];
	}
	if(r[i]!=-1&&!emm[i][1])
	{
	  us[find(i)]=find(r[i]);
	}
  }
  for(i=1;i<=n;++i)
  {
  	if(find(i)==find(1))
  	{
  	  ans[i]=-1;
	}
  }
  for(t=m;t>=1;--t)
  {
  	us[find(num[t])]=find(a[t]?r[num[t]]:l[num[t]]);
  	
  	if((!ans[i])&&find(num[i]))
  }
  return 0;
}
int find(const int &x)
{
  if(us[x]==x)
  {
  	
  }
  else
  {
  	
  }
}
