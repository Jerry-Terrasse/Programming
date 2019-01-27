#include<iostream>
#include<cstring>
#define ll long long
#define MAXL 100010
#define lbt(x) x&-x
using namespace std;
char s[MAXL],t[MAXL];
ll c[MAXL],ls=0,lt=0,ans=0;
inline void add(ll,ll);
inline ll sum(ll);
int main()
{
  ll i=0;
  freopen("string.in","r",stdin);freopen("string.out","w",stdout);
  cin>>s>>t;
  ls=strlen(s);lt=strlen(t);
  for(i=0;i<ls;i++)
  {
  	if(s[i]=='b')
  	{
  	  add(i+1,1);
	}
  }
  for(i=0;i<lt;i++)
  {
    if(t[i]=='a')
    {
      ans+=sum(i+ls-lt+1)-sum(i);
	}
	else
	{
	  ans+=ls-lt+1+sum(i)-sum(i+ls-lt+1);
	}
  }
  cout<<ans<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
inline void add(ll p,ll x)
{
  ll i=p;
  for(;i<=ls;i+=lbt(i))
  {
  	c[i]+=x;
  }
  return;
}
inline ll sum(ll p)
{
  ll i=p,ans=0;
  for(;i>0;i-=lbt(i))
  {
  	ans+=c[i];
  }
  return ans;
}
