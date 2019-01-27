#include<iostream>
#define MAXN 1000010
using namespace std;
int q[MAXN],idq[MAXN],idp[MAXN],p[MAXN];
int ans[MAXN],ql=0,qr=-1,pl=0,pr=-1,n=0,k=0;
inline void read(int&);
int main()
{
  int i=1,a=0;
  ios::sync_with_stdio(0);
  for(read(n),read(k);i<=n;i++)
  {
  	read(a);
  	for(;qr>=ql && q[qr]>=a;qr--);
  	q[++qr]=a;
  	idq[qr]=i;
  	if(idq[ql]+k==i)
  	{
  	  ql++;
	}
	for(;pr>=pl && p[pr]<=a;pr--);
  	p[++pr]=a;
  	idp[pr]=i;
  	if(idp[pl]+k==i)
  	{
  	  pl++;
	}
	if(i<k)
	{
	  continue;
	}
	cout<<q[ql]<<' ';
	ans[i]=p[pl];
  }
  cout<<endl;
  for(i=k;i<=n;i++)
  {
  	cout<<ans[i]<<' ';
  }
  cout<<endl;
  return 0;
}
inline void read(int &x)
{
  char w=1,c=getchar();
  x=0;
  for(;c<'0' || c>'9';c=getchar())
  {
  	if(c=='-')
  	{
  	  w=-1;
	}
  }
  for(;c>='0' && c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  x*=w;
  return;
}
