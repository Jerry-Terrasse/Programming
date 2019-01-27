#include<iostream>
#include<ctime>
#include<cstdlib>
#define ll long long
#define MAXN 100010
#define rr(x) (rand()*rand()%(x))
using namespace std;
ll n=0,m=0,p=0;
int main()
{
  ll i=0,u=0,v=0;
  srand(time(NULL));
  n=rr(MAXN)+1;m=rr(MAXN)+1,p=rr(MAXN)+1;
  cout<<n<<' '<<m<<' '<<p<<endl;
  for(i=1;i<=n;++i)
  {
  	cout<<rr(MAXN)<<' ';
  }
  for(cout<<endl;m--;)
  {
  	i=rr(3)+1;
  	u=rr(n)+1;
  	v=rr(n)+1;
  	if(u>v)
  	{
  	  u^=v^=u^=v;
	}
  	switch(i)
  	{
  	  case 1:
  	  	cout<<1<<' '<<u<<' '<<v<<' '<<rr(MAXN)<<endl;
  	  	break;
  	  case 2:
  	  	cout<<2<<' '<<u<<' '<<v<<' '<<rr(MAXN)<<endl;
  	  	break;
  	  case 3:
  	  	cout<<3<<' '<<u<<' '<<v<<' '<<endl;
  	  	break;
	}
  }
  return 0;
}
