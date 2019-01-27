#include<bits/stdc++.h>
#define MAXN 100000010
#define ok ak
using namespace std;
const int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int x=0,y=0;
bool ok[MAXN];
int main()
{
  int i=0,j=0,k=0,l=0;
  bool b=false;
  //freopen("seven.in","r",stdin);freopen("seven.out","w",stdout);
  scanf("%i",&x);
  ok[7]=1;
  if(x>p[8])
  {
  	y=p[8];
  }
  else
  {
  	y=x;
  }
  for(i=1;p[i]<y;i++)
  {
  	for(j=1;j<=6;j++)
  	{
  	  for(k=0;k<p[i];k++)
  	  {
        ok[p[i]*j+k]=ok[k];
      }
    }
    for(k=0;k<p[i];k++)
  	{
      ok[p[i]*7+k]=1;
    }
    for(j=8;j<=9;j++)
    {
      for(k=0;k<p[i];k++)
  	  {
        ok[p[i]*j+k]=ok[k];
      }
    }
  }
  for(i=0,j=1,k=1,l=0;j+l*p[8]<x;)
  {
    if(j==p[8])
    {
      j=0;
      l++;
	}
	if(k==7)
    {
      b^=1;
      k=0;
	}
	else if(ok[j] || l==7)
    {
      b^=1;
	}
    j++;k++;
    if(b)
    {
      i--;
    }
    else
    {
      i++;
    }
  }
  for(;i<0;i+=1337);
  for(;i>=1337;i-=1337);
  printf("%i\n",i+1);
  //fclose(stdin);fclose(stdout);
  return 0;
}
