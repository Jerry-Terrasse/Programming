#include<iostream>
#define MAXN 30030
#define MAX 30000
#define abs(___) ((___)<0?-(___):(___))
using namespace std;
int us[MAXN],siz[MAXN],d[MAXN],n=0,t=0;
inline int find(const int&);
inline void merge(const int&,const int&);
inline void init();
int main()
{
  register int i=0,j=0,u=0,v=0;
  register char o='\0';
  ios::sync_with_stdio(false);cin.tie(0);
  init();
  cin>>t;
  for(;t--;)
  {
    cin>>o>>u>>v;
    if(o=='C')
    {
      if(find(u)==find(v))
      {
        cout<<abs(d[u]-d[v])-1<<endl;
      }
      else
      {
        cout<<"-1"<<endl;
      }
    }
    else
    {
       merge(find(u),find(v));
    }
  }
  return 0;
}
inline void init()
{
  register int i=0;
  for(i=1;i<=MAX;++i)
  {
    siz[i]=1;
    us[i]=i;
  }
  return;
}
inline void merge(const int &u,const int &v)
{
  us[u]=v;
  d[u]+=siz[v];
  //siz[u]=siz[v]+=siz[u];
  siz[v]+=siz[u];
  siz[u]=0;
  return;
}
inline int find(const int &x)
{
  if(us[x]==x)
  {
    return x;
  }
  int fx=find(us[x]);
  d[x]+=d[us[x]];
  return us[x]=fx;
  //siz[x]=siz[us[x]];
  //return us[x];
}