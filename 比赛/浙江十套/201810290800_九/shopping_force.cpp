#include<iostream>
#include<cstdlib>
#include<bitset>
#include<algorithm>
#define MAXN 16
#define MAXX 1010
using namespace std;
int a[MAXN],b[MAXN],sum=0,x=0,n=0,ans=0x7fffffff;
bitset<MAXX>bts;
void dfs(const int&);
inline void judge();
inline char cmp(const int&,const int&);
int main()
{
  register int i=0;
  freopen("shopping.in","r",stdin);freopen("shopping.out","w",stdout);
  bool bo=false;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>x>>n;
  ans=x;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  	if(a[i]==1)
  	{
  	  bo=true;
	}
  }
  if(!bo)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  sort(a+1,a+n+1,cmp);
  dfs(1);
  cout<<ans<<endl;
  return 0;
}
inline char cmp(const int &a,const int &b)
{
  return a>b;
}
inline void judge()
{
  register int i=0,j=0;
  bts.reset();
  bts[0]=1;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=b[i];++j)
  	{
  	  bts|=bts<<a[i];
	}
  }
  bts&=(1<<x+1)-1;
  if(bts.count()==x+1&&ans>sum)
  {
    ans=sum;
  }
  return;
}
void dfs(const int &x)
{
  if(x==n+1)
  {
  	judge();
  	return;
  }
  for(b[x]=0;sum<ans;++b[x],++sum)
  {
  	dfs(x+1);
  }
  sum-=b[x];
  return;
}
