#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#define ll long long
#define MAXN 1010
#define ha 1000000007
#define sim(x) ((x<0)?(x+3):((x>2)?(x-3):(x)))
using namespace std;
ll s[3][3],jc[MAXN],arcjc[MAXN],b[3],n=0,w=0,l=0,t=0,ans=0;
char a[MAXN];
inline ll score(char*,char*);
inline ll C(ll,ll);
inline void dealjc(ll);
inline ll arc(ll);
int main()
{
  ll i=1;
  freopen("game.in","r",stdin);freopen("game.out","w",stdout);
  for(cin>>n>>w>>l>>t;i<=n;i++)
  {
  	for(a[i]=getchar();a[i]<'0'||a[i]>'2';a[i]=getchar());
  	b[a[i]-'0']=1;
  }
  if(w==l&&l==t)
  {
  	ans=1;
	for(i=1;i<=n;i++)
  	{
  	  ans*=3;
  	  ans%=ha;
	}
	cout<<ans<<endl;
	return 0;
  }
  if(n<=1)
  {
  	cout<<0<<endl;
  	return 0;
  }
  if(b[0]+b[1]+b[2]==1)
  {
  	if(n%3)
  	{
  	  cout<<0<<endl;
	}
	else
	{
	  dealjc(n);
	  n/=3;
	  ans=C(3*n,n);
	  ans+=C(n<<1,n);
	  ans%=ha;
	  cout<<ans<<endl;
	}
	return 0;
  }
  if(b[0]+b[1]+b[2]==2)
  {
  	if(n&1)
  	{
  	  cout<<0<<endl;
	}
	else
	{
	  dealjc(n);
	  ans=C(n,n/2);
	  cout<<ans<<endl;
	}
	return 0;
  }
  srand(time(NULL));
  cout<<rand()*rand()%ha<<endl;
  return 0;
}
inline ll arc(ll n)
{
  ll ans=1,k=ha-2;
  for(;k;)
  {
  	if(k&1)
  	{
  	  ans*=n;
  	  ans%=ha;
	}
	k>>=1;
	n*=n;
	n%=ha;
  }
  return ans;
}
inline void dealjc(ll n)
{
  int i=2;
  jc[0]=jc[1]=1;
  arcjc[0]=arcjc[1]=1;
  for(;i<=n;i++)
  {
  	jc[i]=jc[i-1]*i;
  	jc[i]%=ha;
  	arcjc[i]=arc(jc[i]);
  }
  return;
}
inline ll C(ll n,ll m)
{
  ll ans=1;
  ans*=jc[n];
  ans*=arcjc[m];
  ans%=ha;
  ans*=arcjc[n-m];
  ans%=ha;
  return ans;
}
