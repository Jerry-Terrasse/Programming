#include<iostream>
using namespace std;
int c[2]={0,0},m[2]={0,0},o[2]={0,0};
int main()
{
  int i=0,j=0;
  freopen("bs.in","r",stdin);freopen("bs.out","w",stdout);
  ios::sync_with_stdio(0);
  while(cin>>c[0]>>c[1]>>m[0]>>m[1])
  {
  	if(m[0]==0)
  	{
  	  cout<<m[1]<<endl;
	  continue;
	}
	if(m[1]==0)
	{
	  cout<<m[0]<<endl;
	  continue;
	}
  	o[0]=c[0]/m[0];
  	o[1]=c[1]/m[1];
  	if(o[0]==o[1])
  	{
  	  cout<<max(m[0],m[1])+(m[0]+m[1])*(o[0]-1)<<endl;
	  continue;
	}
	if(o[0]<o[1])
	{
	  cout<<o[0]*(m[0]+m[1])+m[1]<<endl;
	  continue;
	}
	if(o[0]>o[1])
	{
	  cout<<o[1]*(m[0]+m[1])+m[0]<<endl;
	  continue;
	}
  }
  fclose(stdin);fclose(stdout);
  return 0;
}
