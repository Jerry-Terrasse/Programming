#include<iostream>
#define MAXN 50050
using namespace std;
int us[MAXN],dis[MAXN],n=0,k=0,ans=0;
int find(int);
int main()
{
  int i=1,o=0,x=0,y=0;
  for(cin>>n>>k;i<=n;i++)
  {
  	us[i]=i;
  }
  for(i=1;i<=k;i++)
  {
  	cin>>o>>x>>y;
  	if(x>n||y>n)
  	{
  	  ans++;
  	  continue;
	}
  	if(o&1)
  	{
  	  if(find(x)==find(y))
  	  {
  	    o=dis[x]-dis[y];
	  	for(;o<0;o+=3);
	  	for(;o>=3;o-=3);
  	    if(o%3)
  	    {
  	      ans++;
		}
	  }
	  else
	  {
	  	dis[us[y]]=dis[x]-dis[y];
		us[us[y]]=us[x];
	  }
	}
	else
	{
	  if(find(x)==find(y))
	  {
	  	o=dis[x]-dis[y];
	  	for(;o<0;o+=3);
	  	for(;o>=3;o-=3);
	  	if(o!=1)
	  	{
	  	  ans++;
		}
	  }
	  else
	  {
	  	dis[us[y]]=dis[x]-dis[y]-1;
	  	us[us[y]]=us[x];
	  }
	}
  }
  cout<<ans<<endl;
  return 0;
}
int find(int x)
{
  if(us[x]!=x)
  {
  	int y=us[x];
  	us[x]=find(y);
  	dis[x]+=dis[y];
  }
  return us[x];
}
