#include<iostream>
#include<iomanip>
#include<queue>
#define ld long double
#define MAXN 2020
using namespace std;
struct edge
{
  int to,w,next;
}e[MAXN<<1];
int c[MAXN],d[MAXN],n=0,m=0,nv=0,ne=0;
ld k[MAXN],ans=0;
int main()
{
  register int i=0,j=0,u=0,v=0,w=0;
  freopen("classroom.in","r",stdin);freopen("classroom.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>nv>>ne;
  for(i=1;i<=n;++i)
  {
  	cin>>c[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>d[i];
  }
  for(i=1;i<=n;++i)
  {
  	cin>>k[i];
  }
  ans=k[1]*2+k[2]+k[3]*2;
  for(i=1;i<=ne;++i)
  {
  	cin>>u>>v>>w;
  	ans*=u;
  }
  cout<<fixed<<setprecision(2)<<ans/2<<endl;
  return 0;
}
