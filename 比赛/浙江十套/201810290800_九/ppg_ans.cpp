#include<iostream>
#define ll long long
#define MAXN 64
#define max(x,y) ((x)<(y)?(y):(x))
#define abs(x) ((x)<0?-(x):(x))
#define dis(u,v) (abs(x[u]-x[v])+abs(y[u]-y[v]))
using namespace std;
ll us[MAXN],x[MAXN],y[MAXN],r=0,l=0,n=0,ans=0;
inline void init();
int find(const int&);
int main()
{
  int i=0,j=0;
  bool bo=false;
  freopen("ppg.in","r",stdin);freopen("ppg.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>x[i]>>y[i];
  }
  for(i=1;i<=n;++i)
  {
  	for(j=i+1;j<=n;++j)
  	{
  	  ans=max(ans,dis(i,j));
	}
  }
  r=ans+1>>1;
  for(;l+1<r;)
  {
  	ans=l+r+1>>1;
  	init();
  	for(i=1;i<=n;++i)
  	{
  	  for(j=i+1;j<=n;++j)
  	  {
  	    if((dis(i,j)+1>>1)<=ans)
  	    {
  	      us[find(i)]=find(j);
		}
	  }
	}
	for(i=2,bo=true;i<=n;++i)
	{
	  if(find(i)!=find(1))
	  {
	  	bo=false;
	  	break;
	  }
	}
	if(bo)
	{
	  r=ans;
	}
	else
	{
	  l=ans;
	}
  }
  cout<<r<<endl;
  return 0;
}
int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline void init()
{
  register int i=0;
  for(i=1;i<=n;++i)
  {
  	us[i]=i;
  }
  return;
}
