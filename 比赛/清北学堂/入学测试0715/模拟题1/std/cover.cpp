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
#define N 110000
ll f[2][N];
pr a[N];
int n,k,nn,q[N];
ll b[N],c[N];
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n=read();k=read();
	rep(i,1,n)a[i].first=read(),a[i].second=read();
	sort(a+1,a+n+1);
	nn=1;
	rep(i,2,n)
		if(a[nn].second<a[i].second)a[++nn]=a[i];
	n=nn;k=min(k,n);
	rep(i,0,1)
		rep(j,0,n)f[i][j]=-1000000;
	f[0][0]=0;
	int ans=0;
	rep(i,0,k-1){
		b[0]=f[0][0];
		rep(j,1,n)b[j]=max(f[0][j],b[j-1]);
		rep(j,0,n)c[j]=f[0][j]-a[j].second;
		int t=1,w=0,z=0;
		rep(j,i+1,n){
			while(a[z+1].second<=a[j].first)++z;
			while(t<=w && c[j-1]>=c[q[w]])--w;
			q[++w]=j-1;
			while(t<=w && q[t]<=z)++t;
			f[1][j]=b[z]+a[j].second-a[j].first;
			if(t<=w)f[1][j]=max(f[1][j],c[q[t]]+a[j].second);
			ans=max((ll)ans,f[1][j]);
		}
		rep(j,0,n)f[0][j]=f[1][j],f[1][j]=-1000000;
	}
	
	printf("%d\n",ans);
	return 0;
}