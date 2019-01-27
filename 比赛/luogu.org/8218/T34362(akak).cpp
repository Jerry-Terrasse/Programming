#include<iostream>
#define pp 554056561
#define ll long long
using namespace std;
struct mat
{
  ll e[4];
  mat(int a=0,int b=0,int c=0,int d=0){e[0]=a;e[1]=b;e[2]=c;e[3]=d;}
  inline mat operator*(mat&);//special
}ans(1,0,0,1),ak(1,1,2,1);
ll akak=0,k=0;
int main()
{
  cin>>k;
  if(k==0)
  {
  	cout<<0<<endl;
  	return 0;
  }
  k-=2;
  for(;k;)
  {
  	if(k&1)
  	{
  	  ans=ak*ans;
    }
    ak=ak*ak;
    k>>=1;
  }
  akak=ans.e[0]+ans.e[1];
  akak%=pp;
  akak*=2;
  akak%=pp;
  akak+=ans.e[2]+ans.e[3];
  akak%=pp;
  akak*=3;
  akak%=pp;
  cout<<akak<<endl;
  return 0;
}
inline mat mat::operator*(mat &B)
{
  mat AB(0,0,0,0);
  AB.e[0]=e[0]*B.e[0];
  AB.e[0]%=pp;
  AB.e[0]+=e[1]*B.e[2];
  AB.e[0]%=pp;
  AB.e[1]=e[0]*B.e[1];
  AB.e[1]%=pp;
  AB.e[1]+=e[1]*B.e[3];
  AB.e[1]%=pp;
  AB.e[2]=e[2]*B.e[0];
  AB.e[2]%=pp;
  AB.e[2]+=e[3]*B.e[2];
  AB.e[2]%=pp;
  AB.e[3]=e[2]*B.e[1];
  AB.e[3]%=pp;
  AB.e[3]+=e[3]*B.e[3];
  AB.e[3]%=pp;
  return AB;
}
