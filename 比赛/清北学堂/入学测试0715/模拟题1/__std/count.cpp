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
char B[3][3];
bool check(char ch1, char ch2, char a, char b, char c) {
  if (a != ch1 && a != ch2) return 0;
  if (b != ch1 && b != ch2) return 0;
  if (c != ch1 && c != ch2) return 0;
  if (ch2 == '#')return 1;
  if (a != ch1 && b != ch1 && c != ch1) return 0;
  if (a != ch2 && b != ch2 && c != ch2) return 0;
  return true;
}
int win(char ch1, char ch2){
  if (check(ch1, ch2, B[0][0], B[1][1], B[2][2])) return 1;
  if (check(ch1, ch2, B[0][2], B[1][1], B[2][0])) return 1;
  rep(i,0,2){
    if (check(ch1, ch2, B[0][i], B[1][i], B[2][i])) return 1;
    if (check(ch1, ch2, B[i][0], B[i][1], B[i][2])) return 1;
  }
  return 0; 
}
int main(){
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  rep(i,0,2)scanf("%s",B[i]);
  int ans1=0,ans2=0;
  rep(i,'A','Z')
    ans1+=win(i,'#');
  rep(i,'A','Z')
    rep(j,i+1,'Z')
      ans2+=win(i,j);
  printf("%d\n%d\n",ans1,ans2);
  return 0;
}
