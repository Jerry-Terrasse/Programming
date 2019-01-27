#include<iostream>
#include<algorithm>
#define MAXN 5050
using namespace std;
int a[MAXN],n=0,ans=0;
bool b[MAXN];
int main()
{
  int i=0,j=0,cnt=0;
  freopen("box.in","r",stdin);freopen("box.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(i=1;i<=n;++i)
  {
  	if(b[i])
  	{
  	  continue;
	}
	b[i]=cnt=1;
	for(j=i;j<=n;++j)
	{
	  if(b[j]||cnt>a[j])
	  {
	  	continue;
	  }
	  b[j]=1;
	  ++cnt;
	}
	++ans;
  }
  cout<<ans<<endl;
  return 0;
}
