#include<iostream>
#define MAXN 55
using namespace std;
int a[MAXN],n=0,l=0,r=0,ans=0,x=0,y=0,sum=0;
int main()
{
  int i=0,j=0,k=0;
  //freopen("group.in","r",stdin);freopen("group.out","w",stdout);
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  cin>>l>>r;
  for(i=1;i<=n;++i)
  {
  	x+=max(a[i]-r,0);
  	y+=max(l-a[i],0);
  	sum+=a[i];
  }
  if(sum>n*r||sum<n*l)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  cout<<max(x,y)<<endl;
  return 0;
}
