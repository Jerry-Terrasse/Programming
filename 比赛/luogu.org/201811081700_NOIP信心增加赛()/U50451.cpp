#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cmath>
#define int long long
#define ld long double
//#define MAXT 10
#define MINT 1e-7
#define dt 0.997
#define MAXN 5050
#define rr(x) (rand()%(x))
#define sqr(x) ((x)*(x))
#define max(x,y) ((x)<(y)?(y):(x))
#define abs(x) (x<0?-(x):(x))
#define register 
using namespace std;
int x[MAXN],y[MAXN],z[MAXN],w[MAXN],n=0,MAXT=10;
ld ansx=0,ansy=0,ansz=0,ans=1e77;
inline void read(int&);
void write(const int&);
inline void SA();
inline void calc(const ld&,const ld&,const ld&,ld&);
signed main()
{
  register int i=0,j=0;
  float lim=0;
  srand((int)new char);
  read(n);
  for(i=1;i<=n;++i)
  {
  	read(x[i]);read(y[i]);read(z[i]);read(w[i]);
  	MAXT=max(MAXT,max(abs(x[i]),max(abs(y[i]),abs(z[i]))));
  }
  if(n<=100)
  {
  	lim=0.87;
  }
  else
  {
  	lim=1.37;
  }
  for(;(float)clock()/CLOCKS_PER_SEC<lim;SA());
  /*for(i=1000;i--;)
  {
  	SA();
  }*/
  printf("%.2f\n%.2f\n%.2f\n%.2f\n",(double)ansx,(double)ansy,(double)ansz,(double)ans);
  return 0;
}
inline void calc(const ld &xy,const ld &yz,const ld &zx,ld &ans)
{
  register int i=0;
  for(i=1,ans=0;i<=n;++i)
  {
  	ans+=sqrt((sqr(x[i]-xy)+sqr(y[i]-yz)+sqr(z[i]-zx)))*w[i];
  }
  return;
}
inline void SA()
{
  register ld t=MAXT,x=(rr(3)-1)*rand(),y=(rr(3)-1)*rand(),z=(rr(3)-1)*rand();
  register ld sum=0,newsum=0,dx=0,dy=0,dz=0;
  register char o=0;
  for(calc(x,y,z,sum);t>MINT;t*=dt)
  {
  	/*
	dx=x+t*rand()/RAND_MAX;
  	dy=y+t*rand()/RAND_MAX;
  	dz=z+t*rand()/RAND_MAX;
  	*/
  	o=rr(3);
  	dx=x;dy=y;dz=z;
  	if(o==0)
  	{
  	  dx+=t*(rr(3)-1);
  	}
  	else if(o==1)
  	{
  	  dy+=t*(rr(3)-1);
  	}
  	else
  	{
  	  dz+=t*(rr(3)-1);
  	}
  	/*dx=x+t*(rr(3)-1);
  	dy=y+t*(rr(3)-1);
  	dz=z+t*(rr(3)-1);*/
  	calc(dx,dy,dz,newsum);
  	if(newsum<sum)
  	{
  	  x=dx;y=dy;z=dz;
  	  sum=newsum;
  	  if(newsum<ans)
  	  {
  	  	ans=sum;
  	  	ansx=x;ansy=y;ansz=z;
  	  }
  	}
  	else if(exp(-t)<(ld)rand()/RAND_MAX)
  	{
  	  x=dx;y=dy;z=dz;
  	  sum=newsum;
  	}
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
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
