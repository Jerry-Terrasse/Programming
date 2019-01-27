#include<iostream>
#include<algorithm>
#define MAXL 1000010
#define MAXN 100010 
#define ll long long
using namespace std;
struct pot
{
  ll h,c;
}p[MAXN];
ll f[MAXL],n=0,t=0,ak=0,l=0,a=0,b=0;
inline bool cmp(const pot&,const pot&);
int main()
{
  ll i=1,j=0;
  freopen("max.in","r",stdin);freopen("max.out","w",stdout);
  ios::sync_with_stdio(0);
  for(cin>>l>>n>>a>>b;i<=n;i++)
  {
  	cin>>p[i].h>>p[i].c;
  }
  sort(p+1,p+n+1,cmp);
  a-=b;
  ak=a*p[n].h;
  for(i=1;i<=n;i++)
  {
  	t=a*p[i].h;
  	for(j=1;j<=t;j++)
  	{
  	  f[j]=max(f[j],f[j-1]+p[i].c);
	}
	for(j=t+1;j<=ak;j++)
	{
	  f[j]=f[j-1];
	}
  }
  cout<<f[ak]<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
inline bool cmp(const pot &a,const pot &b)
{
  return a.h<b.h;
}
