#include<iostream>
#define MAXN 660
using namespace std;
int n=0;
char a[MAXN][MAXN];
int main()
{
  register int i=0,j=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  for(i=0;i<n;++i)
  {
  	for(j=0;j<n;++j)
  	{
  	  if(a[i][j]=='.')
  	  {
  	    cout<<i+1<<' '<<j+1<<endl;
	  }
	}
  }
  cout<<"-1 -1"<<endl;
  return 0;
}
