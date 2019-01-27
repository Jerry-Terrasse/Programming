#include<iostream>
#define MAXN 10010
using namespace std;
int us[MAXN],n=0,m=0;
int fa(int);
int main()
{
  int i=0,x=0,y=0,z=0;
  cin>>n>>m;
  for(i=1;i<=n;us[i]=i,i++);
  for(i=1;i<=m;i++)
  {
  	cin>>z>>x>>y;
  	if(z&1)
  	{
  	  if(fa(x)!=fa(y))
	  {
	  	us[us[x]]=us[y];
	  }
	}
	else
	{
	  if(fa(x)==fa(y))
	  {
	  	cout<<'Y'<<endl;
	  }
	  else
	  {
	  	cout<<'N'<<endl;
	  }
	}
  }
  return 0;
}
int fa(int x)
{
  return us[x]==x?x:(us[x]=fa(us[x]));
}
