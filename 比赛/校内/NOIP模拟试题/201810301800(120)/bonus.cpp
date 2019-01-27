#include<iostream>
#include<iomanip>
#define ld long double
#define MAXN 16
using namespace std;
int a[MAXN][MAXN],cnt[MAXN],p[MAXN],n=0,k=0,sum=0;
int main()
{
  int i=0,j=0;
  freopen("bonus.in","r",stdin);freopen("bonus.out","w",stdout);
  cin>>k>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>p[i];
  	for(cin>>j;j;cin>>j)
  	{
  	  a[i][++cnt[i]]=j;
	}
  }
  for(i=1;i<=n;++i)
  {
  	sum+=max(p[i],0);
  }
  cout<<fixed<<setprecision(6)<<(ld)sum*k/n<<endl;
  return 0;
}
