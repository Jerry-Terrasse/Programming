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
#define N 1100000
int a[N*2];
int n,k,nn;
int get(){
	return rand()%1000000000;
}
int main(){
	srand((unsigned)time(NULL));
	freopen("cover10.in","w",stdout);
	n=100000;k=100;
	printf("%d %d\n", n,k);
	rep(i,1,n*2)a[i]=get();
	sort(a+1,a+n*2+1);
	rep(i,1,n*2-5+1)
		random_shuffle(a+i,a+i+5);
	rep(i,1,n)
		printf("%d %d\n",min(a[i*2-1],a[i*2]),max(a[i*2-1],a[i*2]));
	return 0;
}