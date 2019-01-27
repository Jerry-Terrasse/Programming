#include<iostream>
#define MAXN 2020
using namespace std;
int l=0,q=0;
char a[MAXN][MAXN];
int main()
{
  int i=1,j=0,u=0,v=0,ans=0;
  ios::sync_with_stdio(0);
  for(cin>>l>>q;i<=l;i++)
  {
    for(j=1;j<=l;j++)
    {
      cin>>a[i][j];
	}
  }
  for(i=0;i<=l+1;i++)
  {
  	a[0][i]=a[i][0]='%';
	a[l+1][i]=a[i][l+1]='&';
  }
  for(;q--;)
  {
  	cin>>u>>v;
  	for(ans=0;a[u][v-ans]==a[u][v+ans];ans++);
  	for(i=0;a[u-i][v]==a[u+i][v];i++);
  	cout<<(max(ans,i)<<1)-1<<endl;
  }
  return 0;
}
