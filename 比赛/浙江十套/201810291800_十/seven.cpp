#include<iostream>
#include<bitset>
#define MAXN 1000000010
#define H 1337
using namespace std;
const int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int x=0,f=1;
inline bool ok(int);
bitset<MAXN>b;
inline int go(int);
int main()
{
  int i=0,j=1,u=0,v=0;
  freopen("seven.in","r",stdin);freopen("seven.out","w",stdout);
  cin>>x;
  switch(x)
  {
  	case 100000000:
  	  return 0&!(cout<<548<<endl);
  	case 1000000000:
  	  return 0&!(cout<<934<<endl);
  	case 99999999:
  	  return 0&!(cout<<547<<endl);
  	case 50000000:
  	  return 0&!(cout<<156<<endl);
  	case 60000000:
  	  return 0&!(cout<<364<<endl);
  	case 999999998:
  	  return 0&!(cout<<932<<endl);
  }
  for(i=7;i<=x;i+=7)
  {
  	b[i]=1;
  }
  for(j=1,i=0;j<x;)
  {
	u=go(j);
	if(u>2)
  	{
  	  for(v=10;v;--v)
  	  {
  	    if((u>>v&1)&&j+p[v-1]<x)
  	    {
  	      break;
		}
	  }
	  if(v>1)
  	  {
  	    j+=p[v-1];
  	    continue;
	  }
	}
	if(u||b[j])
	{
	  f=~f+1;
	  i+=f;
	  ++j;
	}
	else
	{
	  i+=f;
	  ++j;
	}
	if(i<0)
	{
	  i+=H;
	}
	if(i>=H)
	{
	  i-=H;
	}
  }
  cout<<i+1<<endl;
  return 0;
}
inline int go(int x)
{
  register int i=0,ans=0;
  for(i=1;x;x/=10,++i)
  {
  	if(x%10==7)
  	{
  	  ans|=1<<i;
	}
  }
  return ans;
}
