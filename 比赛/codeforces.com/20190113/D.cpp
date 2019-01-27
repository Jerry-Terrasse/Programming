#include<iostream>
#define MAXN 1001
#define MAX 666
#define MID 499
using namespace std;
int use[MAXN][MAXN],x[MAXN],y[MAXN],a=0,b=0;
inline bool check();
inline bool calc();
int main()
{
  register int i=0,k=0,u=0,v=0,dx=0;
  ios::sync_with_stdio(false);cin.tie(0);
  for(i=0;i<MAXN;++i)
  {
    use[0][i]=use[MAXN-1][i]=use[i][0]=use[i][MAXN-1]=1;
  }
  cin>>a>>b;
  for(i=1;i<=MAX;++i)
  {
    cin>>x[i]>>y[i];
    use[x[i]][y[i]]=1;
  }
  for(;a!=MID||b!=MID;)
  {
    if(check())
    {
      cout<<a<<' '<<b<<endl;
      cout.flush();
      return 0;
    }
    else
    {
      if(a<MID)
      {
        ++a;
      }
      else if(a>MID)
      {
        --a;
      }
      if(b<MID)
      {
        ++b;
      }
      else if(b>MID)
      {
        --b;
      }
      cout<<a<<' '<<b<<endl;
      cout.flush();
    }
    cin>>k>>u>>v;
    use[x[k]][y[k]]=0;
    x[k]=u;y[k]=v;
    use[u][v]=1;
  }
  if(calc())
  {
    dx=1;
  }
  else
  {
    dx=-1;
  }
  for(;;)
  {
    if(check())
    {
      
      cout<<a<<' '<<b<<endl;
      cout.flush();
      return 0;
    }
    else
    {
      a+=dx;b+=dx;
      
      cout<<a<<' '<<b<<endl;
      cout.flush();
    }
  }
  return 0;
}
inline bool calc()
{
  register int i=0,ret=0;
  for(i=1;i<=MAX;++i)
  {
    if(x[i]<MID||y[i]<MID)
    {
      ++ret;
    }
  }
  return ret<=MAX/2;
}
inline bool check()
{
  register int i=0,j=0;
  for(i=1;i<=MAX;++i)
  {
    if(x[i]==a+1||x[i]==a-1)
    {
      for(j=-1;j<=1;++j)
      {
        if(!use[x[i]][b+j])
        {
          a=x[i];b+=j;
          return true;
        }
      }
    }
    if(y[i]==b+1||y[i]==b-1)
    {
      for(j=-1;j<=1;++j)
      {
        if(!use[a+j][y[i]])
        {
          a+=j;b=y[i];
          return true;
        }
      }
    }
  }
  return false;
}