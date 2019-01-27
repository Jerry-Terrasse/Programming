//P4392 [BOI2007]Sound 静音问题
#include<iostream>
#include<queue>
#define MAXN 1000010
using namespace std;
int a[MAXN],n=0,m=0,c=0;
bool flag=false;
deque<int>q,r;
int main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>c;
  if(n<m)
  {
    cout<<"NONE"<<endl;
    return 0;
  }
  for(i=0;i<n;++i)
  {
    cin>>a[i];
  }
  for(i=0;i<m;++i)
  {
    for(;q.size()&&a[q.back()]>=a[i];q.pop_back());
    q.push_back(i);
    for(;r.size()&&a[r.back()]<=a[i];r.pop_back());
    r.push_back(i);
  }
  if(a[r.front()]-a[q.front()]<=c)
  {
    flag=true;
    cout<<1<<endl;
  }
  for(;i<n;++i)
  {
    for(;q.size()&&a[q.back()]>=a[i];q.pop_back());
    q.push_back(i);
    if(q.front()+m==i)
    {
      q.pop_front();
    }
    for(;r.size()&&a[r.back()]<=a[i];r.pop_back());
    r.push_back(i);
    if(r.front()+m==i)
    {
      r.pop_front();
    }
    if(a[r.front()]-a[q.front()]<=c)
    {
      flag=true;
      cout<<i+2-m<<endl;
    }
  }
  if(!flag)
  {
    cout<<"NONE"<<endl;
  }
  return 0;
}