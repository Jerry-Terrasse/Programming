#include<iostream>
using namespace std;
int n=0,m=0;
int main()
{
  int i=0;
  freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
  cin>>n>>m;
  if(n<m)
  {
  	n^=m;m^=n;n^=m;
  }
  if(m==1)
  {
  	cout<<1<<endl;
  	return 0;
  }
  if(m==2)
  {
  	cout<<(n+1)/2<<endl;
  	return 0;
  }
  if(m==3)
  {
  	switch(n)
  	{
  	  case 3:
  	  	cout<<8<<endl;
  	  	return 0;
  	  case 5:
  	  	cout<<14<<endl;
  	  	return 0;
  	  case 6:
  	  	cout<<17<<endl;
  	  	return 0;
  	  default:
  	  	cout<<3*n<<endl;
  	  	return 0;
	}
  }
  if(m==4&&n==5)
  {
  	cout<<15<<endl;
  }
  cout<<n*m<<endl;
  return 0;
}
