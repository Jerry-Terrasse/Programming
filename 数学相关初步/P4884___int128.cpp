#include<iostream>
#include<cctype>
#include<cmath>
#include<map>
#include<algorithm>
#include<cstdio>
#define emm __int128
using namespace std;
emm n=0,m=0,p=0,k=0,a=0,b=1;
map<emm,int>mp;
inline emm pow(emm,emm);
inline emm arc(emm);
inline void read(emm&);
void write(emm);
int main()
{
  emm i=0,j=1;
  read(k);read(m);
  k*=9;
  k++;
  k%=m;
  p=ceil(sqrt((long double)m));
  mp.insert(make_pair(1,0));
  for(i=1;i<p;i++)
  {
  	j*=10;
  	j%=m;
  	if(j==k)
  	{
  	  write(i);
  	  return 0;
	}
	if(mp.count(j))
  	{
  	  continue;
	}
	else
	{
	  mp.insert(make_pair(j,i));
	}
  }
  a=pow(10,p);
  a=arc(a);
  for(i=1;;i++)
  {
  	b*=a;
  	b%=m;
	if(mp.count(b*k%m))
	{
	  write(i*p+mp[b*k%m]);
	  return 0;
	}
  }
  return 0;
}
void write(emm x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
}
inline void read(emm &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+c-'0';
  }
  return;
}
inline emm arc(emm x)
{
  return pow(x,m-2);
}
inline emm pow(emm a,emm x)
{
  emm ans=1;
  for(;x;)
  {
  	if(x&1)
  	{
  	  ans*=a;
  	  ans%=m;
	}
	x/=2;
	a*=a;
	a%=m;
  }
  return ans;
}
