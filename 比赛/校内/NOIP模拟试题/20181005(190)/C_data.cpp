#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 20010
using namespace std;
int n=0,m=0,a=0,cnt=0;
inline int rr(const int&);
int main()
{
  int i=0,u=0,v=0;
  srand(time(NULL));
  n=rr(MAXN-1)+1;
  for(cout<<n<<endl;cnt<n;)
  {
  	a+=rr(50)+1;
  	if(cnt+1==n)
  	{
  	  m=1;
	}
	else
	{
	  m=min(127,rr(n-cnt-1)+1);
	}
  	for(cnt+=m;m--;)
  	{
  	  cout<<a<<' ';
	}
  }
  cout<<endl;
  m=rr(MAXN-1)+1;
  for(cout<<m<<endl;m--;)
  {
  	u=rr(n)+1;
  	v=rr(n)+1;
  	if(u>v)
  	{
  	  swap(u,v);
	}
	cout<<u<<' '<<v<<endl;
  }
  return 0;
}
inline int rr(const int &x)
{
  return rand()*rand()%x;
}
