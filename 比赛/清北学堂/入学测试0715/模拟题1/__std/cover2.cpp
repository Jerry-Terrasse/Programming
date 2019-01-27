#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll read(){
  ll ans=0;
  char last=' ',ch=getchar();
  while(ch<'0' || ch>'9')last=ch,ch=getchar();
  while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
  if(last=='-')ans=-ans;
  return ans;
}
//head
#define N 1100
ll f[N][N];
pr a[N];
int n,k,nn;
int main(){
	freopen("cover.in","r",stdin);
//	freopen("cover2.out","w",stdout);
	n=read();k=read();
	rep(i,1,n)a[i].first=read(),a[i].second=read();
	sort(a+1,a+n+1);
	nn=1;
	rep(i,2,n)
		if(a[nn].second<a[i].second)a[++nn]=a[i];
	n=nn;
	rep(i,0,k)
		rep(j,0,n)f[i][j]=-1000000;
	f[0][0]=0;
	int ans=0;
	rep(i,1,k)
		rep(j,i,n){
			rep(j2,i-1,j-1)
				f[i][j]=max(f[i][j],f[i-1][j2]+a[j].second-max(a[j].first,a[j2].second));
			ans=max((ll)ans,f[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}