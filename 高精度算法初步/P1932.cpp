#include<cstdio>
#include<cstring>
#define ll long long
#define MAXL 4010
//#define MAX 33700
#define MAX 3010
#define H 100000
#define w_w 5
#define idg(x) ((x>='0')&&(x<='9'))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
const int p[5]={1,10,100,1000,10000};
struct lll
{
  ll a[MAXL],len;
  inline lll();
  inline void init();
  void input();
  inline void operator=(const lll&);
  inline lll operator+(const lll&);
  inline void operator+=(const lll&);
  inline void add(const lll&,const int&);
  inline lll operator-(const lll&);
  inline void operator-=(const lll&);
  inline lll operator*(const lll&);
  inline lll operator*(const int&);
  inline void operator*=(const int&);
  inline void operator*=(const lll&);
  inline void operator/=(const lll&);
  inline lll operator/(const lll&);
  inline lll operator/(const int&);
  inline void operator/=(const int&);
  inline lll operator%(const lll&);
  inline bool operator<(const lll&);
  inline lll operator+(const int&);
  inline void operator+=(const int&);
  inline void output();
}w[MAX],a,b,ans;
char str[MAXL<<3];
inline void init();
inline void write(const int&);
inline void _write(int x);
//#define EMMM
int main()
{
  int i=0;
  #ifdef EMMM
  freopen("P1932#2.in","r",stdin);
  #endif
  init();
  a.input();
  b.input();
  ans.init();
  ans=a+b;
  ans.output();
  putchar('\n');
  ans.init();
  if(a<b)
  {
  	putchar('-');
  	ans=b-a;
  }
  else
  {
  	ans=a-b;
  }
  ans.output();
  putchar('\n');
  ans.init();
  ans=a*b;
  ans.output();
  putchar('\n');
  ans.init();
  ans=a/b;
  ans.output();
  putchar('\n');
  ans=a-ans*b;
  ans.output();
  putchar('\n');
  return 0;
}
inline void _write(int x)
{
  register int i=0;
  for(i=w_w-1;i>=0;--i)
  {
  	putchar(x/p[i]^48);
  	x%=p[i];
  }
  return;
}
inline void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline lll lll::operator+(const int &b)
{
  lll ans=*this;
  ans+=b;
  return ans;
}
inline void lll::operator+=(const int &b)
{
  register int i=0;
  a[1]+=b;
  for(i=1;a[i]>9;++i)
  {
  	a[i+1]+=a[i]/H;
  	a[i]%=H;
  }
  len=max(len,i-1);
  return;
}
inline lll lll::operator/(const int &b)
{
  lll ans=*this;
  ans/=b;
  return ans;
}
inline void lll::operator/=(const int &b)
{
  register int i=0;
  for(i=len;i;--i)
  {
  	a[i-1]+=a[i]%b*H;
  	a[i]/=b;
  }
  for(i=1;i<=len;++i)
  {
  	a[i+1]+=a[i]/H;
  	a[i]%=H;
  }
  for(;!a[len];--len);
  return;
}
inline lll lll::operator%(const lll &b)
{
  return operator-(operator/(b)*b);
}
inline lll lll::operator/(const lll &x)
{
  register int i=0;
  lll ans;
  for(int lim=len-x.len+1;w[i].len<=lim;++i);
  for(;i>=0;--i)
  {
  	//printf("%d",i);
	ans+=w[i];
  	if(operator<(ans*x))
  	{
  	  ans-=w[i];
	}
  }
  return ans;
}
/*
inline lll lll::operator/(const lll &b)
{
  if(operator<(b))
  {
  	lll ans;
  	ans.len=1;
  	return ans;
  }
  lll l,r,mid;
  l.len=max(0,len-b.len-1)+1;
  r.len=max(0,len-b.len+1)+1;
  l.a[max(1,l.len)]=1;
  r.a[max(1,r.len)]=1;
  for(int cnt=0;l+1<r;++cnt)
  {
  	mid=(l+r)/2;
  	if(cnt==900)
  	{
  	  ++cnt;
  	  --cnt;
	}
  	printf("%d:%d:%d:%d\n",cnt,l.len,mid.len,r.len);
  	//mid.output();
  	//putchar('\n');
  	if(operator<(mid*b))
  	{
  	  r=mid;
	}
	else
	{
	  l=mid;
	}
  }
  return l;
}
*/
inline void lll::output()
{
  register int i=0;
  write(a[len]);
  for(i=len-1;i;--i)
  {
  	_write(a[i]);
  }
  return;
}
inline bool lll::operator<(const lll &x)
{
  if(len!=x.len)
  {
  	return len<x.len;
  }
  else
  {
  	register int i=0;
  	for(i=len;i;--i)
  	{
  	  if(a[i]!=x.a[i])
  	  {
  	    return a[i]<x.a[i];
	  }
	}
  }
  return false;
}
inline void init()
{
  int i=0;
  w[0].len=w[0].a[1]=1;
  for(i=1;i<MAX;++i)
  {
  	w[i]=w[i-1]*2;
  }
  return;
}
inline void lll::operator*=(const lll &b)
{
  *this=*this*b;
  return;
}
/*inline lll lll::operator*(const lll &b)
{
  register int i=0,j=0;
  lll ans;
  for(i=1;i<=b.len;++i)
  {
  	ans.add(*this*b.a[i],i-1);
  }
  return ans;
}*/
inline lll lll::operator*(const lll &x)
{
  register int i=0,j=0;
  lll ans;
  ans.len=len+x.len;
  for(i=1;i<=x.len;++i)
  {
  	for(j=1;j<=len;++j)
  	{
  	  ans.a[i+j-1]+=a[j]*x.a[i];
  	  //ans.a[i+j]+=a[i+j-1]/H;
  	  //ans.a[i+j-1]%=H;
	}
  }
  for(i=1;i<=ans.len||ans.a[i];++i)
  {
    ans.a[i+1]+=ans.a[i]/H;
    ans.a[i]%=H;
  }
  for(;!ans.a[ans.len];--ans.len);
  return ans;
}
inline lll lll::operator*(const int &b)
{
  lll ans;
  ans=*this;
  ans*=b;
  return ans;
}
inline void lll::operator*=(const int &b)
{
  register int i=0;
  for(i=1;i<=len;++i)
  {
  	a[i]*=b;
  }
  for(i=1;i<=len||a[i];++i)
  {
  	a[i+1]+=a[i]/H;
  	a[i]%=H;
  }
  len=i-1;
  return;
}
inline lll lll::operator-(const lll &b)
{
  lll ans=*this;
  ans-=b;
  return ans;
}
inline void lll::operator-=(const lll &b)
{
  register int i=0;
  for(i=1;i<=b.len;++i)
  {
  	a[i]-=b.a[i];
  }
  for(i=1;i<=len;++i)
  {
  	for(;a[i]<0;)
  	{
  	  --a[i+1];
  	  a[i]+=H;
	}
  }
  for(;len>1&&!a[len];--len);
  return;
}
inline void lll::add(const lll &b,const int &p)
{
  register int i=0;
  len=max(len,p+b.len);
  for(i=1;i<=b.len;++i)
  {
  	a[p+i]+=b.a[i];
  }
  for(i=1;i<=len||a[i];++i)
  {
  	a[i+1]+=a[i]/H;
  	a[i]%=H;
  }
  len=i-1;
  return;
}
inline lll lll::operator+(const lll &b)
{
  lll ans=*this;
  ans+=b;
  return ans;
}
inline void lll::operator+=(const lll &b)
{
  register int i=0;
  len=max(len,b.len);
  for(i=1;i<=b.len;++i)
  {
  	a[i]+=b.a[i];
  }
  for(i=1;i<=len||a[i];++i)
  {
  	a[i+1]+=a[i]/H;
  	a[i]%=H;
  }
  len=i-1;
  return;
}
inline void lll::operator=(const lll &b)
{
  len=b.len;
  memcpy(a,b.a,sizeof(a));
  return;
}
void lll::input()
{
  register int l=0,i=0,j=0;
  init();
  scanf("%s",str);
  l=strlen(str);
  j=l%w_w;
  len=l/w_w+1;
  for(i=0;j--;++i)
  {
  	a[len]=(a[len]<<1)+(a[len]<<3)+(str[i]^48);
  }
  for(j=len-1;j;--j)
  {
  	for(l=0;l<w_w;++l)
  	{
  	  a[j]=(a[j]<<1)+(a[j]<<3)+(str[i+l]^48);
	}
	i+=w_w;
  }
  if(!a[len])
  {
  	--len;
  }
  return;
}
/*
void lll::input(const int &x)
{
  register char c=0;
  register int i=0,j=0;
  init();
  for(;c<'0'|c>'9';c=getchar());
  for(i=1;c>='0'&c<='9';c=getchar(),++i)
  {
  	a[i]=c^48;
  }
  len=i-1;
  for(i=1,j=len;i<j;a[i++]^=a[j--]^=a[i]^=a[j]);
  return;
}
*/
inline void lll::init()
{
  len=1;
  memset(a,0,sizeof(a));
  return;
}
inline lll::lll()
{
  init();
  return;
}
