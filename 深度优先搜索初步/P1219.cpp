#include<iostream>
#define MAXN 15
using namespace std;
int a[MAXN],b[MAXN<<1],c[MAXN<<1],ans[MAXN],n=0,cnt=0;
void dfs(int);
int main()
{
  int i=0;
  cin>>n;
  dfs(1);
  cout<<cnt<<endl;
  return 0;
}
void dfs(int x)
{
  int i=0;
  if(x==n+1)
  {
  	cnt++;
    if(cnt<=3)
    {
      for(i=1;i<=n;i++)
      {
      	cout<<ans[i]<<' ';
      }
      cout<<endl;
    }
    return;
  }
  for(i=1;i<=n;i++)
  {
  	if(a[i] || b[x+i] || c[i+n-x])
  	{
  	  continue;
    }
    a[i]=b[x+i]=c[i+n-x]=ans[x]=i;
    dfs(x+1);
    a[i]=b[x+i]=c[i+n-x]=ans[x]=0;
  }
  return;
}
