#include<iostream>
#define MAXN 22
using namespace std;
struct res
{
  int cnt,val;
}f[1<<MAXN],g[1<<MAXN];
int a[MAXN],b[MAXN],cnta=0,cntb=0,n=0,m=0,ans=0x7fffffff;
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  cin>>m;
  for(i=1;i<=m;++i)
  {
  	cin>>b[i];
  }
  for(i=1;i<(1<<n);++i)
  {
  	++cnta;
  	for(j=0;j<n;++j)
  	{
  	  if(1<<j&i)
  	  {
  	    ++f[cnta].cnt;
  	    f[cnta].val+=a[j+1];
	  }
    }
  }
  for(i=1;i<(1<<m);++i)
  {
  	++cntb;
  	for(j=0;j<m;++j)
  	{
  	  if(1<<j&i)
  	  {
  	    ++g[cntb].cnt;
  	    g[cntb].val+=b[j+1];
	  }
	}
  }
  for(i=1;i<=cnta;++i)
  {
  	for(j=1;j<=cntb;++j)
  	{
  	  if(f[i].val==g[j].val)
  	  {
  	    ans=min(ans,f[i].cnt+g[j].cnt);
	  }
	}
  }
  if(ans==0x7fffffff)
  {
  	cout<<"impossible"<<endl;
  }
  else
  {
  	cout<<ans<<endl;
  }
  return 0;
}
