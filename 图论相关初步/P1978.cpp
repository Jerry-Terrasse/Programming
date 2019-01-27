#include<iostream>
#include<algorithm>
#include<map>
#define ll long long
#define MAXN 100010
using namespace std;
ll a[MAXN],us[MAXN],ln[MAXN],n=0,k=0,ans=0;
map<ll,int>mp;
inline int find(const int&);
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(i=1;i<=n;++i)
  {
  	mp.insert(make_pair(a[i],i));
  }
  for(i=1;i<=n;++i)
  {
  	us[i]=i;
  }
  for(i=1;i<=n;++i)
  {
  	if((!(a[i]%k))&&mp.count(a[i]/k)&&find(i)!=find(mp[a[i]/k]))
  	{
  	  us[us[i]]=us[mp[a[i]/k]];
	}
  }
  for(i=1;i<=n;++i)
  {
  	++ln[find(i)];
  }
  for(i=1;i<=n;++i)
  {
  	ans+=ln[i]+1>>1;
  }
  cout<<ans<<endl;
  return 0;
}
inline int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
