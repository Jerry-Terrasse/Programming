#include<iostream>
#include<cstdlib>
#define ld long double
#define ll long long
#define MAXN 1010
//#define INF 0x7fffffffffffffff
#define eql(x,y) (((x)-(y)>-0.0000001)&&((x)-(y)<0.0000001))
using namespace std;
const ll H[7]={2147483647,19260817,2147483629,2147483587,2147483579,2147483563,2147483549};
ll arc[7][MAXN],ans[7][2],n=0,m=0,pro=0;
ld s=0,t=0;
inline void init();
inline void judge(const ll&,const ll&);
inline ll arar(ll,ll);
int main()
{
  ll i=0,j=0,k=0,INF=0x7fffffff;
  freopen("sum.in","r",stdin);freopen("sum.out","w",stdout);
  s=1;t=1;INF*=INF;
  cin>>n>>m;
  init();
  for(i=2;i<m;++i)
  {
  	s/=i;
  }
  for(i=n+1;i<n+m;++i)
  {
  	t/=i;
  }
  s-=t;
  for(k=0;k<7;++k)
  {
  	for(i=2,ans[k][0]=ans[k][1]=1;i<m;++i)
  	{
  	  ans[k][0]*=arc[k][i];
  	  ans[k][0]%=H[k];
	}
	for(i=n+1;i<n+m;++i)
	{
	  ans[k][1]*=arc[k][i];
	  ans[k][1]%=H[k];
	}
	ans[k][0]+=H[k]-ans[k][1];
	ans[k][0]*=arc[k][m-1];
	ans[k][0]%=H[k];
  }
  for(i=1;i>0;++i)
  {
  	//cout<<i<<endl;
	j=(ll)(i/s);
  	if(j>1)
  	{
  	  judge(i,j-1);
	}
	if(j<=INF)
	{
	  judge(i,j);
	}
	if(j<INF)
	{
	  judge(i,j+1);
	}
  }
  return 0;
}
inline ll arar(ll a,ll k)
{
  ll ans=1,b=H[k]-2;
  for(;b;)
  {
  	if(b&1)
  	{
  	  ans*=a;
  	  ans%=H[k];
	}
	a*=a;
	a%=H[k];
  }
  return ans;
}
inline void judge(const ll &x,const ll &y)
{
  int k=0;
  for(k=0;k<7;++k)
  {
  	pro=x%H[k];
  	if(y<MAXN)
  	{
  	  pro*=arc[k][y];
	}
  	else
  	{
  	  pro*=arar(y,k);
	}
  	pro%=H[k];
  	if(pro!=ans[k][0])
  	{
  	  return;
	}
  }
  cout<<x<<endl<<y<<endl;
  exit(0);
  return;
}
inline void init()
{
  int i=0,k=0;
  for(k=0;k<7;++k)
  {
  	for(i=2,arc[k][1]=1;i<MAXN;++i)
  	{
  	  arc[k][i]=((-H[k]/i*arc[k][H[k]%i])%H[k]+H[k])%H[k];
	}
  }
  return;
}
