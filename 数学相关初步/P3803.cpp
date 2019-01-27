#include<cstdio>
#include<cmath>
#define ld double
#define MAXN 1100000
#define abs(x) ((x)<0?-(x):(x))
using namespace std;
struct cp
{
  ld a,b;
  inline cp(const ld &x=0,const ld &y=0){a=x,b=y;}
  inline void operator+=(const cp&);
  inline void operator-=(const cp&);
  inline cp operator-(const cp&);
  inline cp operator*(const cp&);
  inline cp operator+(const cp&);
}mmp[MAXN<<4],a[MAXN<<1],b[MAXN<<1],*top;
int n=0,m=0,outer=0;
char c='\0';
void dft(cp*,const int&,const char&);
inline void read(int&);
void write(const int&);
inline void New(const int&,cp*&);
inline void Del(cp*);
int main()
{
  int i=0,j=0;
  //freopen("P3803#7.in","r",stdin);
  top=mmp;
  read(n);read(m);
  outer=n+m+1;
  for(i=0;i<=n;++i)
  {
  	read(j);
  	a[i]=j;
  }
  for(i=0;i<=m;++i)
  {
  	read(j);
  	b[i]=j;
  }
  n=(1<<(int)ceil(log2(n+m)));
  if(n<2)
  {
  	n=2;
  }
  dft(a,n>>1,1);
  dft(b,n>>1,1);
  for(i=0;i<n;++i)
  {
  	a[i]=a[i]*b[i];
  }
  dft(a,n>>1,-1);
  for(j=0;j<outer;++j)
  {
    printf("%.0lf",abs(a[j].a)/n);
	  putchar(' ');
  }
  return 0;
}
void dft(cp *a,const int &n,const char &o)
{
  //write(n);
  //putchar('\n');
  if(n==1)
  {
  	a[0]+=a[1];
  	a[1]=a[0]-a[1]-a[1];
	return;
  }
  if(!n)
  {
  	return;
  }
  cp *w,*wn,*mem[2];
  int i=0;
  New(n,mem[0]);New(n,mem[1]);New(1,w);New(1,wn);
  w->a=1;w->b=0;wn->a=cos(M_PI/n);wn->b=sin(o*M_PI/n);
  for(i=0;i<n;++i)
  {
  	mem[0][i]=a[i<<1];
  	mem[1][i]=a[i<<1|1];
  }
  dft(mem[0],n>>1,o);
  dft(mem[1],n>>1,o);
  for(i=0;i<n;++i)
  {
  	a[i]=mem[0][i]+*w*mem[1][i];
  	a[i+n]=mem[0][i]-*w*mem[1][i];
  	*w=w->operator*(*wn);
  }
  Del(mem[0]);
  return;
}
inline void Del(cp *p)
{
	top=p;
	return;
}
inline void New(const int &x,cp* &p)
{
	p=top;top+=x;
	return;
}
inline cp cp::operator+(const cp &y)
{
  return cp(a+y.a,b+y.b);
}
inline cp cp::operator*(const cp &y)
{
  return cp(a*y.a-b*y.b,b*y.a+a*y.b);
}
inline cp cp::operator-(const cp &y)
{
  return cp(a-y.a,b-y.b);
}
inline void cp::operator-=(const cp &y)
{
  a-=y.b;b-=y.b;
  return;
}
inline void cp::operator+=(const cp &y)
{
  a+=y.a;b+=y.b;
  return;
}
inline void read(int &x)
{
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10^48);
  return;
}
