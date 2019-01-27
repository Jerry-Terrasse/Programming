#include<cstdio>
#define MAXN 15
#define oo 0.000001
using namespace std;
int l=0,n=0;
long double d=0,f=0,x[MAXN][2]={0},y[MAXN][2]={0};
inline bool ok(long double,long double);
int main()
{
  int i=0;
  long double xx=0,yy=0;
  scanf("%i%i",&n,&l);
  d=(long double)l*0.8/n;
  for(;i<n;i++)
  {
  	scanf("%lf%lf",&x[i][0],&y[i][0]);
  	x[i][1]=x[i][0]+d;
  	x[i][0]-=d;
  	y[i][1]=y[i][0]+d;
  	y[i][0]-=d;
  }
  f=d*oo;
  for(xx=0;xx<=l;xx+=f)
  {
  	for(yy=0;yy<=l;yy+=f)
  	{
  	  if(ok(xx,yy))
  	  {
  	  	printf("%.3lf ",xx);
  	  	printf("%.3lf\n",yy);
  	  	return 0;
	  }
	}
  }
  printf("GG\n");
  return 0;
}
inline bool ok(long double xx,long double yy)
{
  int i=0;
  bool bo=true;
  for(;i<n;i++)
  {
  	if((x[i][0]-oo<=xx)&&(x[i][1]+oo>=xx)&&(y[i][0]-oo<=yy)&&(y[i][1]+oo>=yy))
  	{
  	  bo=false;
	}
  }
  return bo;
}
