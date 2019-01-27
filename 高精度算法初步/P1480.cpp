#include<iostream>
#include<cstdio>
#include "memory.h"
#define MAXL 5050
using namespace std;
struct lll
{
  int dat[MAXL],len;
  inline lll* operator/=(const int&);
  inline void init();
  void input(const int&);
  inline void output();
  inline lll();
}a;
int b=0;
int main()
{
  int i=0;
  a.input(1);
  cin>>b;
  a/=b;
  a.output();
  return 0;
}
inline void lll::output()
{
  int i=len;
  for(;i;--i)
  {
  	cout<<dat[i];
  }
  return;
}
inline lll* lll::operator/=(const int &b)
{
  int i=len;
  for(;i;--i)
  {
  	dat[i-1]+=dat[i]%b*10;
  	dat[i]/=b;
  }
  for(;!dat[len];--len);
  return this;
}
void lll::input(const int &x)
{
  char c=getchar();
  if(isdigit(c))
  {
  	input(x+1);
    dat[len+1-x]=c^48;
  }
  else
  {
  	len=x-1;
  }
  return;
}
inline void lll::init()
{
  memset(dat,0,sizeof(dat));
  len=0;
  return;
}
inline lll::lll()
{
  init();
  return;
}
