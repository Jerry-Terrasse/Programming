#include<cstdio>
#include<cstring>
#include "memory.h"
#define MAXL 1010
#define H 1000000000
#define w_w 9 
using namespace std;
struct lll
{
  int dat[MAXL],p,o;
  inline void init();
  inline void input();
  inline void output();
  inline lll* operator=(const lll&);
  inline bool operator==(const lll&);
  inline lll* operator+=(lll&);
  inline lll operator+(lll&);
  inline lll* operator-=(lll&);
  inline lll operator-(lll&);
  inline lll* operator*=(const lll&);
  inline lll operator*(const lll&);
  inline lll* operator*=(const int&);
  inline lll operator*(const int&);
}a,b;
char ch='\0',str[MAXL*w_w];
inline void read(int&);
void write(const int&);
void w_write(const int&,const int&);
int main()
{
  int i=0;
  a.input();b.input();
  a+=b;
  a.output();
  putchar('\n');
  return 0;
}
inline lll* operator-=(lll &b)
{
  
  
  
  
  int i=0;
  return *this;
}
inline lll operator+=(lll &b)
{
  lll ans=*this;
  ans-=b;
  return ans;
}
inline void w_write(const int &x,const int &bt)
{
  if(x<=9)
  {
  	for(int i=bt;i<w_w;++i)
  	{
  	  putchar('0');
	}
	putchar(x+'0');
  }
  else
  {
  	w_write(x/10,bt+1);
  	putchar(x%10+'0');
  }
}
inline void lll::output()
{
  int i=p-1;
  if(o)
  {
  	putchar('-');
  }
  write(dat[p]);
  for(;i;--i)
  {
  	w_write(dat[i],1);
  }
  return;
}
inline void lll::input()
{
  int i=0,j=0;
  p=0;
  scanf("%s",str);
  if(str[0]=='-')
  {
  	o=1;
  	for(i=1;s[i];++i)
  	{
  	  s[i-1]=s[i];
	}
	s[i-1]='\0';
  }
  for(i=strlen(str)-w_w;i>=0;i-=w_w)
  {
  	++p;
	for(j=0;j<w_w;++j)
  	{
  	  dat[p]=(dat[p]<<1)+(dat[p]<<3)+(str[i+j]^48);
	}
  }
  i+=w_w;
  if(i>0)
  {
  	++p;
  }
  for(j=0;j<i;++j)
  {
  	dat[p]=(dat[p]<<1)+(dat[p]<<3)+(str[j]^48);
  }
  return;
}
inline void lll::init()
{
  p=0;o=0;
  memset(dat,0,sizeof(dat));
  return;
}
inline lll lll::operator+(lll &b)
{
  lll ans;
  ans=*this;
  ans+=b;
  return ans;
}
inline lll* lll::operator+=(lll &b)
{
  if(o)
  {
  	o=0;
	if(b.o)
  	{
  	  b.o=0;
  	  a+=b;
  	  b.o=1;
	}
	else
	{
	  a-=b;
	}
	o^=1;
  }
  else
  {
  	if(b.o)
  	{
  	  b.o=0;
  	  a-=b;
  	  b.o=1;
	}
	else
	{
	  a+=b;
	}
  }
  int i=0;
  for(i=1;i<=b.p;++i)
  {
  	dat[i]+=b.dat[i];
  	dat[i+1]+=dat[i]/H;
  	dat[i]%=H;
  }
  for(;dat[i];++i)
  {
  	dat[i+1]+=dat[i]/H;
  	dat[i]%=H;
  }
  p=i-1;
  return this;
}
inline lll* lll::operator=(const lll &b)
{
  p=b.p;o=b.o;
  memcpy(dat,b.dat,sizeof(dat));
  return this;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
  return;
}
inline void read(int &x)
{
  for(x=0;ch<'0'||ch>'9';ch=getchar());
  for(;ch>='0'&&ch<='9';ch=getchar())
  {
	x=(x<<1)+(x<<3)+(ch^48);
  }
  return;
}
