#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#define MAXN 2000020
#define ppp 1333331
#define ll long long
using namespace std;
struct movie
{
  ll id,ado,sbt;
}mv[MAXN];
ll a[MAXN],cnt[MAXN],n=0,m=0,cntcnt=0;
map<ll,ll>mp;
ll hx(ll);
inline bool cmp(const movie&,const movie&);
int main()
{
  ll i=0,s=0;
  cin>>n;
  for(;i<n;i++)
  {
  	cin>>s;
  	a[i]=hx(s);
  	cnt[a[i]]++;
  }
  cin>>m;
  for(i=0;i<m;i++)
  {
    cin>>s;
    mv[i].id=i;
    mv[i].ado=hx(s);
  }
  for(i=0;i<m;i++)
  {
    cin>>s;
    mv[i].sbt=hx(s);
  }
  sort(mv,mv+m,cmp);
  cout<<mv[0].id+1<<endl;
  return 0;
}
inline bool cmp(const movie &a,const movie &b)
{
  return (cnt[a.ado]>cnt[b.ado])||(cnt[a.ado]==cnt[b.ado]&&cnt[a.sbt]>cnt[b.sbt]);
}
ll hx(ll s)
{
  if(mp.count(s))
  {
  	return mp[s];
  }
  else
  {
  	cntcnt++;
	mp.insert(make_pair(s,cntcnt));
	return cntcnt;
  }
}
