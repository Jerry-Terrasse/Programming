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
int n,x[N],c[N];
ll L,Va,Vb;
bool isMax[N];
pr a[N];
int main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	L=read();
	n=read();
	Va=read();
	Vb=read();
	rep(i,0,n-1)a[i].first=read(),a[i].second=read();
	sort(a,a+n);
	rep(i,0,n-1)x[i]=a[i].first,c[i]=a[i].second;
	int mx=0;
	per(i,n-1,0)
		if(c[i]>mx){
			isMax[i]=1;
			mx=c[i];
		}
	ll ans=0,tf=0,tb=0,lastx=0;
	rep(i,0,n-1)
		if(isMax[i]){
			ll tmp=(x[i]-lastx)*(Va-Vb);
			ans+=tmp*c[i];
			lastx=x[i];
	}
	cout<<ans<<'\n';
}
