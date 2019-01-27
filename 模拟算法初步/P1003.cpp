#include<iostream>
#include<memory.h>
using namespace std;
//short int s[9999][9999];
int main()
{
  //memset(s,-1,sizeof(s));
  int n=0,i=0,x=0,y=0;
  bool b=true;
  cin>>n;
  int a[n][4];
  memset(a,0,sizeof(a));
  for(i=0;i<=n-1;i++)
  {
    cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    a[i][2]+=a[i][0];
    a[i][3]+=a[i][1];
  }
  cin>>x>>y;
  for(i=n-1;i>=0;i--)
  {
  	if((x>=a[i][0])&&(y>=a[i][1])&&(x<=a[i][2])&&(y<=a[i][3]))
  	{
  	  cout<<i+1<<endl;
  	  b=false;
  	  break;
	}
  }
  if(b)
  {
  	cout<<-1<<endl;
  }
  /*for(i=0;i<=n-1;i++)
  {
  	cout<<a[i][0]<<a[i][1]<<a[i][2]<<a[i][3];
  }*/
  return 0;
}
