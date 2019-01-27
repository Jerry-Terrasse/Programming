#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAXN 30030
#define MAX 30000
#define rr(x) (rand()%(x))
using namespace std;
int us[MAXN],n=0,t=0;
inline int find(const int&);
int main()
{
  register int i=0,u=0,v=0;
  srand(time(NULL));
  t=5;
  n=5;
  for(i=1;i<=n;++i)
  {
    us[i]=i;
  }
  cout<<t<<endl;
  for(;t--;)
  {
    if(rr(2))
    {
      cout<<'C'<<' '<<rr(n)+1<<' '<<rr(n)+1<<endl;
    }
    else
    {
      for(u=rr(n)+1,v=rr(n)+1;find(u)==find(v);u=rr(n)+1,v=rr(n)+1);
      us[us[u]]=us[v];
      cout<<'M'<<' '<<u<<' '<<v<<endl;
    }
  }
  return 0;
}
inline int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}