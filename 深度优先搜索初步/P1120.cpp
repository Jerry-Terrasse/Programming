#include<iostream>
#include<set>
#include<queue>
#define MAXN 77
using namespace std;
int a[MAXN],n=0,sum=0;
set<int>st;
priority_queue<int>q;
int main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;)
  {
    cin>>a[i];
    if(a[i]>50)
    {
      --n;
    }
    else
    {
      ++i;
    }
  }
  for(i=1;i<=n;++i)
  {
    sum+=a[i];
  }
  
  return 0;
}