#include<cstdio>
#define MAXN 440
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int st[MAXN][MAXN][MAXN],f[MAXN][MAXN],d[MAXN][MAXN],a[MAXN][MAXN],lg[MAXN],p=0,n=0,m=0,ans=0x80000000;
char c='\0',_c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,j=0,k=0,l=0,r=0,s=0,sum=0,maxd=0;
  //freopen("puzzle.in","r",stdin);freopen("puzzle.out","w",stdout);
  read(n);read(m);read(p);
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  read(a[i][j]);
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
  	  d[i][j]=p-a[i][j];
	}
  }
  for(i=1,l=max(n,m);i<=l;++i)
  {
  	for(j=1<<i;j<(1<<i+1);++j)
  	{
  	  lg[j]=i;
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  st[i][j][0]=d[i][j];
	}
	for(k=1;(1<<k)<=m;++k)
	{
	  for(j=1;j+(1<<k)<=m+1;++j)
	  {
	  	st[i][j][k]=max(st[i][j][k-1],st[i][j+(1<<k-1)][k-1]);
	  }
	}
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=m;++j)
  	{
  	  for(k=i;k<=n;++k)
  	  {
  	    for(l=j;l<=m;++l)
  	    {
  	      sum=f[k][l];
  	      sum-=f[i-1][l];
  	      sum-=f[k][j-1];
  	      sum+=f[i-1][j-1];
  	      if(i!=1||j!=1||k!=n||l!=m)
  	      {
  	        maxd=0;
		  }
		  else
		  {
		  	maxd=0x80000000;
		  }
		  for(r=i;r<=k;++r)
  	      {
  	        maxd=max(maxd,max(st[r][j][lg[l-j+1]],st[r][l-(1<<lg[l-j])+1][lg[l-j+1]]));
		  }
		  sum+=maxd;
		  if(sum>ans)
		  {
		  	ans=sum;
		  }
		}
	  }
	}
  }
  write(ans);
  putchar('\n');
  return 0;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  for(x=_c=0;c<'0'||c>'9';c=getchar())
  {
  	if(c=='-')
  	{
  	  _c=1;
	}
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  if(_c)
  {
  	x=-x;
  }
  return;
}
