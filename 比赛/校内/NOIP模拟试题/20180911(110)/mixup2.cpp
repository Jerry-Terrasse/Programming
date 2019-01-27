#include<iostream>
#include "memory.h"
#define MAXN 20
#define ll long long
#define ok(x) (x<-k)||(x>k)
using namespace std;
ll f[(1<<17)-1][MAXN],no[MAXN],n=0,k=0,ans=0;
ll dfs(int,int);
int main()
{
  int i=1,j=0,l=0;
  freopen("mixup2.in","r",stdin);freopen("mixup2.out","w",stdout);
  memset(f,-1,sizeof(f));
  for(cin>>n>>k;i<=n;i++)
  {
  	cin>>no[i];
  	f[1<<i>>1][i]=1;
  }
  for(i=1;i<=n;i++)
  {
  	ans+=dfs((1<<n)-1,i);
  }
  cout<<ans<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
ll dfs(int a,int x)
{
  if(f[a][x]!=-1)
  {
  	return f[a][x];
  }
  int i=0;
  f[a][x]=0;
  for(i=0;i<n;i++)
  {
  	if((i+1!=x)&&(a&(1<<i))&&(ok(no[i+1]-no[x])))
  	{
  	  f[a][x]+=dfs(a^(1<<x>>1),i+1);
	}
  }
  return f[a][x];
}
