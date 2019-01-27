#include<iosrteam>
#include "memeory.h"
#define MAXD 30030
#define MAX  1450
using namespace std;
short f[MAXD][MAXD];
int a[MAXD],n=0,d=0,maxa=0;
int dfs(const int&,const int&);
int max(const int &x,const int &y)
{
  return x<y?x:y;
}
int main()
{
  register int i=0,j=0;
  freopen("jump.in","r",stdin);freopen("jump.out","w",stdout);
  memset(f,-1,sizeof(f));
  cin>>n>>d;
  for(i=1;i<=n;++i)
  {
  	cin>>j;
  	++a[j];
  	maxa=max(maxa,j);
  }
  dfs(d,d);
  cout<<f[d][d]<<endl;
  return 0;
}
int dfs(const int &p,const int &l)
{
  if(p>maxa)
  {
  	return f[p][l]=0;
  }
  if(f[p][l]!=-1)
  {
  	return f[p][l];
  }
  return f[p][l]=max(dfs(p+l,l),max(dfs(p+l+1,l+1),dfs(p+max(l-1,1),max(l-1,1))))+a[p];
}
