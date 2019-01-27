#include<iostream>
#include<iomanip>
#define ld long double
#define MAXN 16
#define o 1e-9
#define ieql(x,y) ((x-y<-o)||(x-y>o))
using namespace std;
int n=0;
ld f[MAXN],l=0,r=0;
inline void cal(const ld&,ld&);
int main()
{
  int i=0;
  ld a=0,b=0,fa=0,fb=0;
  ios::sync_with_stdio(0);
  for(cin>>n>>l>>r;i<=n;i++)
  {
  	cin>>f[i];
  }
  for(;ieql(l,r);)
  {
  	a=b=(l+r)/3;
  	a+=l/3;
  	b+=r/3;
  	cal(a,fa);
  	cal(b,fb);
  	if(fa<fb)
  	{
  	  l=a;
	}
	else
	{
	  r=b;
	}
  }
  cout<<fixed<<setprecision(5)<<(l+r)/2<<endl;
  return 0;
}
inline void cal(const ld &x,ld &ans)
{
  int i=1;
  for(ans=f[0];i<=n;i++)
  {
  	ans*=x;
  	ans+=f[i];
  }
  return;
}
