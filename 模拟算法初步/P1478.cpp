#include<cstdio>
#define MAXY 105
using namespace std;
int n=0,h=0,s=0,map[MAXY],ans=0;
int main()
{
  int i=0,x=0,y=0;
  scanf("%i%i%i%i",&n,&s,&i,&h);
  h+=i;
  for(i=0;i<n;i++)
  {
  	scanf("%i%i",&x,&y);
	if(x<=h)
  	{
  	  map[y]++;
	}
  }
  n=0;
  for(i=0;s>=i && i<MAXY;)
  {
  	if(map[i])
  	{
  	  s-=i;
  	  map[i]--;
  	  ans++; 
	}
	else
	{
	  i++;
	}
  }
  printf("%i",ans);
  return 0;
}
