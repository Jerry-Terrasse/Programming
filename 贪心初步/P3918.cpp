#include<iostream>
#include<algorithm>
#define MAXK 330
using namespace std;
int c[MAXK],n=0,k=0,ans=0;
inline bool cmp(int,int);
int main()
{
  int i=0,p=0;
  for(cin>>n>>k;i<k;i++)
  {
  	cin>>c[i];
  }
  sort(c,c+k,cmp);
  p=min(n>>1,k);
  for(i=0;i<p;i++)
  {
  	ans+=c[i]*(n-2*i-1);
  }
  cout<<ans<<endl;
  return 0;
}
inline bool cmp(int a,int b)
{
  return a>b;
}
