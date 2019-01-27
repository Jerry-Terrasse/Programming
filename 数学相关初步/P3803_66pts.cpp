#include<cstdio>
//#include<complex>
#include<cmath>
#define ld double
//#define cp complex<ld>
#define MAXN 730010
//#define eql(x,y) (((x)-(y)>-1e-7)&&((x)-(y)>1e-7))
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
}mem[21][2][MAXN],a[MAXN],b[MAXN];
int n=0,m=0,outer=0;
char c='\0';
void dft(cp*,const int&,const char&,const int&);
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,j=0;
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
  dft(a,n>>1,1,0);
  dft(b,n>>1,1,0);
  for(i=0;i<n;++i)
  {
  	a[i]=a[i]*b[i];
  }
  dft(a,n>>1,-1,0);
  /*
  for(i=n;i;--i)
  {
  	if(eql(a[i].a,0))
  	{
  	  break;
    }
  }
  */
  for(j=0;j<outer;++j)
  {
    printf("%.0lf",abs(a[j].a)/n);
    //write((int)(a[j].a/n));
  	//ld x=a[j].real();
    putchar(' ');
  }
  return 0;
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
void dft(cp *a,const int &n,const char &o,const int &x)
{
  if(!n)
  {
  	return;
  }
  cp w(1,0),wn(cos(M_PI/n),sin(o*M_PI/n));
  int i=0;
  for(i=0;i<n;++i)
  {
  	mem[x][0][i]=a[i<<1];
  	mem[x][1][i]=a[i<<1|1];
  }
  dft(mem[x][0],n>>1,o,x+1);
  dft(mem[x][1],n>>1,o,x+1);
  for(i=0;i<n;++i)
  {
  	a[i]=mem[x][0][i]+w*mem[x][1][i];
  	a[i+n]=mem[x][0][i]-w*mem[x][1][i];
  	w=w*wn;
  }
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
