#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define ld long double
#define MAXN 1010
#define MINT 1e-13
#define eql(x,y) ((x-y>-1e-18)&&(x-y<1e-18))
using namespace std;
struct vector
{
  ld a,b;
  inline void operator+=(const vector&);
  inline void operator-=(const vector&);
  inline void operator=(const vector&);
  inline vector operator+(const vector&);
  inline vector operator-(const vector&);
  inline bool operator==(const vector&);
  inline vector operator*(const ld&);
  inline void operator++();
  inline ld operator!();
};
struct thing
{
  vector hole;
  int w;
};
thing a[MAXN];
int n=0,m=0,summ=0;
ld t=0,sum,newsum;
vector ans,dx,pos,zero;
inline void cal(ld&);
inline int rr(int);
int main()
{
  int i=1;
  srand(time(NULL));
  for(cin>>n;i<=n;i++)
  {
  	cin>>a[i].hole.a>>a[i].hole.b>>a[i].w;
  	t=max(t,max(a[i].hole.a,a[i].hole.b));
  	pos+=a[i].hole;
  	summ+=a[i].w;
  }
  pos=pos*((ld)1/n);
  ans=pos;
  for(cal(sum);t>MINT;t*=0.998+(ld)1/n/666)
  {
	++dx;
  	pos+=dx;
  	cal(newsum);
  	if(newsum<sum)
  	{
  	  sum=newsum;
  	  ans=pos;
	}
	else if(exp(-t)<(ld)rr(1000000)/1000000)
	{
	  sum=newsum;
	}
	else
	{
	  pos-=dx;
	}
  }
  cout<<fixed<<setprecision(3)<<ans.a<<' '<<ans.b<<endl;
  return 0;
}
inline int rr(int x)
{
  return rand()*rand()%x;
}
inline void cal(ld &sum)
{
  int i=0;
  sum=0;
  for(i=1;i<=n;i++)
  {
  	sum+=(!(pos-a[i].hole))*a[i].w;
  }
  //sum/=summ;
  return;
}
inline ld vector::operator!()
{
  return sqrt(a*a+b*b);
}
inline void vector::operator++()
{
  a=t*(rand()%3-1);
  b=t*(rand()%3-1);
  if(a==0&&b==0)
  {
  	this->operator++();
  }
  return;
}
inline bool vector::operator==(const vector& beta)
{
  return eql(a,beta.a)&&eql(b,beta.b);
}
inline void vector::operator=(const vector& beta)
{
  a=beta.a;
  b=beta.b;
  return;
}
inline void vector::operator-=(const vector &beta)
{
  a-=beta.a;
  b-=beta.b;
  return;
}
inline void vector::operator+=(const vector &beta)
{
  a+=beta.a;
  b+=beta.b;
  return;
}
inline vector vector::operator*(const ld &lambda)
{
  vector gamma;
  gamma.a=a*lambda;
  gamma.b=b*lambda;
  return gamma;
}
inline vector vector::operator-(const vector &beta)
{
  vector gamma;
  gamma.a=a-beta.a;
  gamma.b=b-beta.b;
  return gamma;
}
inline vector vector::operator+(const vector &beta)
{
  vector gamma;
  gamma.a=a+beta.a;
  gamma.b=b+beta.b;
  return gamma;
}
