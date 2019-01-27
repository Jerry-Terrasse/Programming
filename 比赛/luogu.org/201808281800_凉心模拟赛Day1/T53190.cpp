#include<cstdio>
using namespace std;
int a=0,b=0,H=0,t=0;
char c='\0';
inline void read(int&);
int main()
{
  register int x=0,y=0;
  register bool bo=false;
  read(t);read(H);
  for(;t--;)
  {
  	read(x);read(y);
  	a=x;b=y;bo=false;
  	x+=y;x%=H;
  	y+=x;y%=H;
  	for(;x&&y;)
  	{
  	  x+=y;
  	  if(x>=H)
  	  {
  	    x-=H;
	  }
	  if(x==0)
	  {
	  	printf("1\n");
	  	break;
	  }
	  y+=x;
	  if(y>=H)
	  {
	  	y-=H;
	  }
	  if(y==0)
	  {
	  	printf("2\n");
	  }
	  if(x==a&&y==b)
	  {
	  	bo=true;
		break;
	  }
	}
	if(bo)
	{
	  printf("error\n");
	}
  }
  return 0;
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
