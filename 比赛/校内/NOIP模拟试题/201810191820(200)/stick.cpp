#include<iostream>
#define Ha 71806291
using namespace std;
const int d[10]={6,2,5,5,4,5,6,3,7,6};
int k=0;
int main()
{
  int i=0,q=0,r=0;
  freopen("stick.in","r",stdin);freopen("stick.out","w",stdout);
  cin>>k;
  switch(k)
  {
  	case 0:
  	  return 0;
  	  for(int rp=Ha;++rp;);
  	case 1:
  	  return 0;
  	  for(int rp=Ha;++rp;);
  	/*case 6:
  	  putchar('0');
  	  putchar(' ');
  	  putchar('1');
  	  putchar('1');
  	  putchar('1');
  	  putchar('\n');
  	  return 0;*/
  }
  q=k/7;r=k-7*q;
  if(r==0)
  {
  	for(;q--;)
  	{
  	  putchar('8');
	}
  }
  else if(r==1)
  {
  	putchar('1');
  	putchar('0');
  	for(--q;q--;)
  	{
  	  putchar('8');
	}
  }
  else
  {
  	if(q)
  	{
  	  --q;r+=7;
  	  switch(r)
  	  {
  	    case 9:
  	      putchar('1');
  	      putchar('8');
  	      break;
  	    case 10:
  	      putchar('2');
  	      putchar('2');
  	      break;
  	    case 11:
  	      putchar('2');
  	      putchar('0');
  	      break;
  	    case 12:
  	      putchar('2');
  	      putchar('8');
  	      break;
  	    case 13:
  	      putchar('6');
  	      putchar('8');
  	      break;
	  }
	}
	else
	{
	  for(i=0;i<=9;++i)
  	  {
  	    if(d[i]==r)
  	    {
  	      putchar(i+'0');
  	      break;
	    }
	  }
	}
	for(;q--;)
	{
	  putchar('8');
	}
  }
  putchar(' ');
  q=k/2;
  if(k&1)
  {
  	--q;
  	putchar('7');
  }
  for(;q--;)
  {
  	putchar('1');
  }
  putchar('\n');
  return 0;
}
