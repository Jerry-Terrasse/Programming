#include<iostream>
#define MAXN 1010
#define MAXK 11
using namespace std;
int st[MAXK][MAXN],top[MAXK],h[MAXN],n=0,k=2,ans=0;
inline void add(int,int);
int main()
{
  int i=0;
  freopen("stone.in","r",stdin);freopen("stone.out","w",stdout);
  for(cin>>n;i<n;i++)
  {
  	cin>>h[i];
  }
  for(i=0;i<n;i++)
  {
  	add(0,h[i]);
  }
  for(i=0;i<k;i++)
  {
  	ans+=top[i];
  }
  cout<<ans<<endl;
  return 0;
}
inline void add(int p,int x)
{
  if(p>k)
  {
  	return;
  }
  int i=0;
  for(i=top[p];i>=0&&st[p][i]>=x;i--);
  if(i==top[p])
  {
  	st[p][i+1]=x;
  	top[p]++;
  }
  else
  {
  	add(p+1,st[p][i+1]);
  	st[p][i+1]=x;
  }
  return;
}
