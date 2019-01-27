#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 100050
#define p 1000000007
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
using namespace std;
ll b[MAXN],c[MAXN],d[MAXN],n=0,m=0,q=0,ans=1;
char ch='\0';
inline void read(ll&);
inline ll arc(ll);
int main()
{
  ll i=1,o=0,x=0,y=0,z=0;
  for(read(n),read(q);i<=n;i++)
  {
  	read(o);
  	c[i]=max(c[i-1],o);
  }
  c[n+1]=0x3f3f3f3f3f3f3f3f;
  for(i=1;i<=n;i++)
  {
  	read(b[i]);
  	d[i]=min(b[i],c[i]);
  	if(d[i])
  	{
  	  ans*=d[i];
  	  ans%=p;
	}
	else
	{
	  m++;
	}
  }
  for(;q--;)
  {
  	read(o);read(x);read(y);
  	if(o)
  	{
  	  if(d[x])
  	  {
  	    if(b[x]<c[x])
  	    {
  	      ans*=arc(b[x]);
  	      ans%=p;
  	      ans*=d[x]=min(y,c[x]);
  	      ans%=p;
	    }
	  }
	  else
	  {
	  	d[x]=min(y,c[x]);
	  	if(d[x])
	  	{
	  	  ans*=d[x];
	  	  ans%=p;
	  	  m--;
		}
	  }
	  b[x]=y;
	}
	else
	{
	  if(d[x])
	  {
	  	z=lower_bound(c+x,c+n+2,y)-c;
  	  for(i=x;i<z;i++)
  	  {
  	    if(c[i]<b[i])
  	    {
  	      ans*=arc(c[i]);
  	      ans%=p;
  	      ans*=d[i]=min(b[i],y);
  	      ans%=p;
		}
		c[i]=y;
	  }
	  }
	  else
	  {
	  	z=lower_bound(c+x,c+n+2,y)-c;
  	  for(i=x;i<z;i++)
  	  {
  	    if(c[i]<b[i])
  	    {
  	      d[i]=min(b[i],y);
  	      if(d[i])
  	      {
		    ans*=d[i];
		    ans%=p;
			m--;
		  }
		}
		c[i]=y;
	  }
	  }
	}
	if(m)
	{
	  printf("0\n");
	}
	else
	{
	  printf("%lld\n",ans);
	}
  }
  return 0;
}
inline void read(ll &x)
{
  for(x=0,ch=getchar();ch<'0'||ch>'9';ch=getchar());
  for(;ch>='0'&&ch<='9';ch=getchar())
  {
  	x=(x<<1)+(x<<3)+ch-'0';
  }
  return;
}
inline ll arc(ll n)
{
  ll ans=1,k=p-2;
  for(;k;)
  {
  	if(k&1)
  	{
  	  ans*=n;
  	  ans%=p;
	}
	k>>=1;
	n*=n;
	n%=p;
  }
  return ans;
}
