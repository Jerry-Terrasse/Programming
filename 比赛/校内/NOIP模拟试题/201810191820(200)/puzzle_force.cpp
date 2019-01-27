#include<cstdio>
#define MAXN 330
#define fn(x,y,z) for(x=y;x<=z;++x)
using namespace std;
int f[MAXN][MAXN],d[MAXN][MAXN],a[MAXN][MAXN],p=0,n=0,m=0,ans=0x80000000;
char c='\0',_c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,j=0,k=0,l=0,r=0,s=0,sum=0;
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
  fn(i,1,n)
  	fn(j,1,m)
  	  fn(k,i,n)
  	    fn(l,j,m)
  	    {
  	      sum=f[k][l];
  	      sum-=f[i-1][l];
  	      sum-=f[k][j-1];
  	      sum+=f[i-1][j-1];
  	      if(i!=1||j!=1||k!=n||l!=m)
  	      {
  	        if(ans<sum)
  	        {
  	          ans=sum;
			}
		  }
  	      fn(r,i,k)
  	        fn(s,j,l)
  	          if(ans<sum+d[r][s])
  	          {
  	            ans=sum+d[r][s];
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
