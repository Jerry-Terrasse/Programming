#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;
int a[MAXN],f[MAXN],n=1;
inline void read(int&);
int main()
{
  int i=0,l=1,*p=NULL;
  for(read(a[n]);a[n]!=-1;)
  {
  	read(a[++n]);
  }
  f[1]=a[1];
  for(i=2;i<n;i++)
  {
  	if(f[l]>=a[i])
  	{
  	  f[++l]=a[i];
	}
	else
	{
	  p=upper_bound(f+1,f+l+1,a[i],greater<int>());
	  *p=a[i];
	}
  }
  cout<<l<<endl;
  f[1]=a[1];
  l=1;
  for(i=2;i<n;i++)
  {
  	if(f[l]<a[i])
  	{
  	  f[++l]=a[i];
	}
	else
	{
	  p=lower_bound(f+1,f+l+1,a[i]);
	  *p=a[i];
	}
  }
  cout<<l<<endl;
  return 0;
}
inline void read(int &x)
{
  int w=1;
  char c=getchar();
  for(x=0;c>'9' || c<'0';c=getchar())
  {
  	if(c=='-')
  	{
  	  w=-w;
	}
	if(c==EOF)
	{
	  x=-1;
	  return;
	}
  }
  for(;'0'<=c && c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  x*=w;
  return;
}
