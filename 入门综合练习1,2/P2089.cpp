#include<iostream>
using namespace std;
int dg(int);
int q=0,a[10],s=0,p=0,saved[9999][10];
int main()
{
  cin>>q;
  dg(0);
  cout<<s<<endl;
  for(int i=0;i<=s-1;i++)
  {
  	for(int j=0;j<=9;j++)
  	{
  	  cout<<saved[i][j]<<" ";
	}
	cout<<endl;
  }
}
int dg(int x)
{
  int i=0;
  if(x==9)
  {
  	a[9]=q-p;
  	if((1<=a[9])&&(a[9]<=3))
  	{
  	  for(i=0;i<=9;i++)
  	  {
  	    saved[s][i]=a[i];
	  }
	  s++;
	}
	return 0;
  }
  if(p>=q)
  {
  	return 0;
  }
  for(a[x]=1;a[x]<=3;a[x]++)
  {
  	p+=a[x];
	dg(x+1);
	p-=a[x];
  }
}
/*for(i=0;i<=9;i++)
  	  {
  	    cout<<a[i]<<" ";
	  }
	  cout<<endl;*/
