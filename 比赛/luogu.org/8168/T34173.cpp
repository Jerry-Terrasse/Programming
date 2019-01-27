#include<iostream>
#define ll long long
using namespace std;
struct mat
{
  ll e[4];
  mat(int a=0,int b=0,int c=0,int d=0){e[0]=a;e[1]=b;e[2]=c;e[3]=d;}
  inline mat operator*(mat&);//special
  inline void pro();
}ans(1,0,0,1),ak(1,1,1,0);
ll a=0,b=0,n=0;
int main()
{
  ll k=1;
  cin>>a>>b>>n;
  for(;b;)
  {
  	if(b&1)
  	{
  	  k*=a;
	}
	a*=a;
	b>>=1;
  }
  k--;
  for(;k;)
  {
  	if(k&1)
  	{
  	  ans=ak*ans;
	}
	ak.pro();
	k>>=1;
  }
  cout<<ans.e[0]<<endl;
  return 0;
}
inline void mat::pro()
{
  mat AB(0,0,0,0);
  AB.e[0]=e[0]*e[0]+e[1]*e[2];
  AB.e[0]%=n;
  AB.e[1]=e[0]*e[1]+e[1]*e[3];
  AB.e[1]%=n;
  AB.e[2]=AB.e[1];
  AB.e[3]=AB.e[0]-AB.e[2];
  AB.e[3]%=n;
  *this=AB;
  return;
}
inline mat mat::operator*(mat &B)
{
  mat AB(0,0,0,0);
  AB.e[0]=e[0]*B.e[0]+e[1]*B.e[2];
  AB.e[0]%=n;
  AB.e[1]=e[0]*B.e[1]+e[1]*B.e[3];
  AB.e[1]%=n;
  AB.e[2]=e[2]*B.e[0]+e[3]*B.e[2];
  AB.e[2]%=n;
  AB.e[3]=e[2]*B.e[1]+e[3]*B.e[3];
  AB.e[3]%=n;
  return AB;
}
