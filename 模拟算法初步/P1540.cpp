#include<iostream>
#define MAXM 105
using namespace std;
int n=0,m=0,s=1,h=0,t=0,q[MAXM];
int main()
{
  int i=1,j=0,a=0;
  bool bo=false;
  cin>>m>>n;
  cin>>a;
  q[0]=a;
  for(;i<n;i++)
  {
  	cin>>a;
  	bo=true;
	for(j=h;1;j++)
  	{
  	  if(j==m)
  	  {
  	    j=0;
	  }
	  if(q[j]==a)
  	  {
  	    bo=false;
  	    break;
	  }
	  if(j==t)
	  {
	  	break;
	  }
	}
	if(bo)
	{
	  s++;
	  t++;
	  if(t==m)
	  {
	  	t=0;
	  }
	  q[t]=a;
	  if(s>1 && h==t)
	  {
	  	h++;
	  	if(h==m)
	  	{
	  	  h=0;
		}
	  }
	}
  }
  cout<<s<<endl;
  return 0;
}
