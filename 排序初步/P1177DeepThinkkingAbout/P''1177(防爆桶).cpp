#include<cstdio>
#include "memory.h"
using namespace std;
long long n=0,a=0,m=0;
char s0[100000000];
char s1[100000000];
char s2[100000000];
char s3[100000000];
char s4[100000000];
char s5[100000000];
char s6[100000000];
char s7[100000000];
char s8[100000000];
char s9[100000000];
char s10[2];
int main()
{
  long long i=0,j=0,b=0,t=0;
  //memset(s,0,sizeof(s));
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
    scanf("%i",&a);
    if(m<a)
    {
      m=a;
	}
	b=a/100000000;
	switch(b)
	{
	  case 0:
	   s0[a%100000000]++;
       break;
	  case 1:
	   s1[a%100000000]++;
       break;
	  case 2:
	   s2[a%100000000]++;
       break;
      case 3:
	   s3[a%100000000]++;
       break;
      case 4:
	   s4[a%100000000]++;
       break;
      case 5:
	   s5[a%100000000]++;
       break;
      case 6:
	   s6[a%100000000]++;
       break;
      case 7:
	   s7[a%100000000]++;
       break;
      case 8:
	   s8[a%100000000]++;
       break;
	  case 9:
	   s9[a%100000000]++;
       break;
	  case 10:
	   s10[a%100000000]++;
	   break;
	}
  }
  for(b=0;b<=9;b++)
  {
  	for(i=0;(i<100000000)&&((b*100000000+i)<=m);i++)
	{
      switch(b)
	  {
	    case 0:
	     t=s0[i];
         break;
	    case 1:
	     t=s1[i];
         break;
	    case 2:
	     t=s2[i];
         break;
        case 3:
	     t=s3[i];
         break;
        case 4:
	     t=s4[i];
         break;
        case 5:
	     t=s5[i];
         break;
        case 6:
	     t=s6[i];
         break;
        case 7:
         t=s7[i];
         break;
        case 8:
	     t=s8[i];
         break;
	    case 9:
	     t=s9[i];
         break;
	    case 10:
	     t=s10[i];
	     break;
	  }
	  for(j=1;j<=t;j++)
      {
  	    printf("%i ",b*100000000+i);
	  }
	}
  }
  return 0;
}
