#include<iostream>
#define MAXN 110
using namespace std;
int c[MAXN],n=0;
int main()
{
  freopen("toy.in","r",stdin);
  freopen("toy.out","w",stdout);
  int i=0,j=0,a=0;
  cin>>n;
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=n;j++)
  	{
  	  cin>>a;
	  if(a==1 || a==3)
	  {
	  	c[i]=1;
	  }
	}
  }
  a=0;
  for(i=1;i<=n;i++)
  {
  	if(!c[i])
  	{
  	  a++;
	}
  }
  cout<<a<<endl;
  for(i=1;i<=n;i++)
  {
  	if(!c[i])
  	{
  	  cout<<i<<' ';
	}
  }
  cout<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
