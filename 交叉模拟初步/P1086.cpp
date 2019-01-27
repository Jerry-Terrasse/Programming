#include<iostream>
#include<algorithm>
#include "memory.h"
#include<cmath>
using namespace std;
struct huasheng
{
  int p,x,y;
}a[400];
int m=0,n=0,t=0,s=0;
bool cop(huasheng a,huasheng b)
{
  return a.p>b.p;
}
int main()
{
  cin>>m>>n>>t;
  int i=0,j=0,k=0,x=0,y=0;
  for(i=0;i<m;i++)
  {
  	for(j=0;j<n;j++)
  	{
  	  cin>>a[k].p;
  	  if(a[k].p)
  	  {
  	  	a[k].x=i;
  	  	a[k].y=j;
		k++;
	  }
	}
  }
  sort(a,a+max(k,0),cop);
  t-=a[0].x+1;
  if(t<a[0].x+2)
  {
  	goto output;
  }
  else
  {
  	s+=a[0].p;
  	t--;
    x=a[0].x;y=a[0].y;
  }
  for(i=1;i<=k-1;i++)
  {
  	t-=abs(x-a[i].x);
  	t-=abs(y-a[i].y);
    if(t<a[i].x+2)
    {
      goto output;
    }
    else
    {
      s+=a[i].p;
  	  t--;
      x=a[i].x;y=a[i].y;
      //cout<<"I'm on ("<<x<<","<<y<<")"<<endl;
    }
  }
  output:;
  cout<<s<<endl;
  return 0;
}
