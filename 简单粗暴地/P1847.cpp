//P1847 轰炸II
#include<iostream>
#define MAXN 2020
using namespace std;
struct boom
{
  int a,b,c,d;
  inline void input();
  inline bool have(const int&,const int&);
}a[MAXN];
int n=0,m=0;
int main()
{
  register int i=0,u=0,v=0,cnt=0,id=0;
  register boom *p=NULL,*end=NULL;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  for(p=a,end=a+n;p!=end;++p)
  {
    p->input();
  }
  for(;m--;)
  {
    cin>>u>>v;
    cnt=0;
    for(p=a;p!=end;++p)
    {
      if(p->have(u,v))
      {
        ++cnt;
        id=p-a;
      }
    }
    if(cnt)
    {
      cout<<"YES "<<cnt<<' '<<id+1<<endl;
    }
    else
    {
      cout<<"NO "<<endl;
    }
  }
  return 0;
}
inline bool boom::have(const int &x,const int &y)
{
  return a<=x&&x<=c&&b<=y&&y<=d;
}
inline void boom::input()
{
  cin>>a>>b>>c>>d;
  return;
}