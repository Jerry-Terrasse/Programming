#include<iostream>
#include<cmath>
using namespace std;
int zs[99999],szs=0,mi=0;
int main()
{
  int i=0,j=0,a=0,b=0;
  bool k=false;
  cin>>a>>b;
  for(i=max(2,a);i<=b;i++)
  {
    k=true;
	for(j=2;j<=sqrt(i);j++)
    {
      if(i%j==0)
      {
      	k=false;
        break;
	  }
	}
	if(k)
	{
	  szs++;//about zs[-1]
	  zs[szs]=i;
	  mi=max(mi,zs[szs]-zs[szs-1]);
	  //cout<<i<<",";
	}
  }
  cout<<mi<<endl;
  return 0;
}
