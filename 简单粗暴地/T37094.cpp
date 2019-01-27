#include<iostream>
using namespace std;
int n=0,x=0;
inline void read(int&);
int main()
{
  read(n);
  for(cout<<n;n--;read(x));
  return 0;
}
inline void read(int &x)
{
  char w=1,c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar())
  {
  	if(c=='-')
  	{
  	  w=-1;
	}
  }
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  x*=w;
  return;
}
