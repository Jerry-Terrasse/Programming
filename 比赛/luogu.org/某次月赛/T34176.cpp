#include<bits/stdc++.h>
//#define MAXN 100000000000000100
using namespace std;
long long x=0,y=0,z=0,n=0,cnt=0,ans=0;
inline long long lcm(long long,long long);
int main()
{
  long long i=0,j=0,k=0,a=0,xy=0,xz=0,yz=0,xyz=0;
  ios::sync_with_stdio(0);
  cin>>x>>y>>z>>n;
  xy=lcm(x,y);
  yz=lcm(y,z);
  xz=lcm(x,z);
  xyz=lcm(xy,z);
  a=xyz;
  cnt+=a/x;cnt+=a/y;cnt+=a/z;
  cnt-=a/xy;cnt-=a/xz;cnt-=a/yz;
  cnt+=a/xyz;
  cnt=a-cnt;
  a=n/cnt*xyz;
  cnt=0;
  cnt+=a/x;cnt+=a/y;cnt+=a/z;
  cnt-=a/xy;cnt-=a/xz;cnt-=a/yz;
  cnt+=a/xyz;
  cnt=a-cnt;
  for(;cnt<n;cnt++)
  {
  	for(;;)
  	{
  	  a++;i++;j++;k++;
	  if(i==x)
  	  {
  	    i=0;
	  }
	  if(j==y)
  	  {
  	    j=0;
	  }
	  if(k==z)
  	  {
  	    k=0;
	  }
	  if(i!=0 && j!=0 && k!=0)
	  {
	  	break;
	  }
	}
  }
  cout<<a<<endl;
  return 0;
}
inline long long lcm(long long a,long long b)
{
  long long x=0,ax=a,bx=b;
  x=__gcd(a,b);
  ax/=x;
  bx/=x;
  x*=ax;
  x*=bx;
  return x;
}
