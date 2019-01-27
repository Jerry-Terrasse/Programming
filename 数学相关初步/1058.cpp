#include<bits/stdc++.h>
using namespace std;
long double a=0,b=0,c=0,d=0,x[2]={0,0};
inline void output(long double,long double);
inline int sgn(long double);
int main()
{
  scanf("%Lf%Lf%Lf",&a,&b,&c);
  d=b*b-4*a*c;
  if(d<0)
  {
  	printf("No answer!");
  }
  else
  {
  	x[0]=(-b-sqrt(b*b-4*a*c))/(2*a);
  	x[1]=(-b+sqrt(b*b-4*a*c))/(2*a);
  	for(int i=0;i<=1;i++)
  	{
  	  if(-x[i]==0)
  	  {
  	  	x[i]==0;
	  }
	}
	if(x[0]==x[1])
	{
	  printf("x1=x2=%.5Lf",x[0]);
	}
	else
	{
	  x[0]<x[1]?output(x[0],x[1]):output(x[1],x[0]);
	}
  }
  return 0;
}
inline void output(long double pp,long double ap)
{
  int spp=sgn(pp),sap=sgn(ap);
  long double opp=abs(pp),oap=abs(ap);
  printf("x1=");
  if(spp==1)
  {
  	printf("%.5Lf",opp);
  }
  else if(spp==-1)
  {
  	printf("-%.5Lf",opp);
  }
  else if(spp==0)
  {
  	printf("0");
  }
  printf(";x2=");
  if(sap==1)
  {
  	printf("%.5Lf",oap);
  }
  else if(sap==-1)
  {
  	printf("-%.5Lf",oap);
  }
  else if(sap==0)
  {
  	printf("0");
  }
  //printf("x1=%.5Lf;x2=%.5Lf",spp*opp,sap*oap);
  return;
}
inline int sgn(long double ppap)
{
  if(ppap>0)
  {
  	return 1;
  }
  else if(ppap==0)
  {
  	return 0;
  }
  else
  {
  	return -1;
  }
}
