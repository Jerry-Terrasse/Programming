#include<iostream>
#define MAXN 32
#define MAXS 25050
using namespace std;
int f[1<<16-1][MAXS],no[MAXN],ext[MAXS],n=0,k=0,ans=0;
int main()
{
  int i=1,j=0,l=0;
  for(cin>>n>>k;i<=n;i++)
  {
  	cin>>no[i];
  	ext[no[i]]=1;
  	f[1][no[i]]=1;
  }
  for(i=2;i<=n;i++)
  {
	for(j=1;j<MAXS;j++)
  	{
  	  if(!ext[j])
  	  {
  	    continue;
	  }
  	  for(l=1;l+k<j;l++)
  	  {
  	    f[i][j]+=f[i-1][l];
	  }
	  for(l=j+k+1;l<MAXS;l++)
	  {
	    f[i][j]+=f[i-1][l];
	  }
	}
  }
  for(i=1;i<MAXS;i++)
  {
  	ans+=f[n][i];
  }
  cout<<ans<<endl;
  return 0;
}
