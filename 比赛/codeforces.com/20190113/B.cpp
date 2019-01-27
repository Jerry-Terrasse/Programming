#include<iostream>
#include<queue>
#define MAXN 100010
using namespace std;
int f[MAXN],n=0,m=0;
queue<int>q;
int main()
{
  register int i=0,j=0,a=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(i=1;i<=m;++i)
  {
    cin>>a;
    if(!f[a])
    {
      q.push(a);
    }
    ++f[a];
    if(q.size()==n)
    {
      cout<<'1';
      for(j=1;j<=n;++j)
      {
        a=q.front();q.pop();
        --f[a];
        if(f[a])
        {
          q.push(a);
        }
      }
    }
    else
    {
      cout<<'0';
    }
  }
  return 0;
}