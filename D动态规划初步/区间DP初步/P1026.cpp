//P1026 统计单词个数
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 220
#define MAXM 11
#define MAXK 44
#define INF 0x3f3f3f3f
#define max(x,y) ((x)=(x)<(y)?(y):(x))
using namespace std;
int g[MAXN][MAXN],f[MAXK][MAXN],h[MAXN],n=0,m=0,k=0,p=0;
string wd[MAXM],s="",ln="";
inline bool cmp(const string&,const string&);
int main()
{
  register int i=0,j=0,l=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>p>>k;
  for(;p--;)
  {
    cin>>ln;
    s+=ln;
  }
  n=s.length();
  cin>>m;
  for(i=1;i<=m;++i)
  {
    cin>>wd[i];
  }
  sort(wd+1,wd+m+1,cmp);
  for(i=1;i<=n;++i)
  {
    h[i]=INF;
    for(j=1;j<=m;++j)
    {
      if(s.substr(i-1,n-i+1).find(wd[j])==0)
      {
        h[i]=i+wd[j].length()-1;
        break;
      }
    }
  }
  for(i=1;i<=n;++i)
  {
    for(j=i;j<=n;++j)
    {
      for(l=i;l<=j;++l)
      {
        if(h[l]<=j)
        {
          ++g[i][j];
        }
      }
    }
  }
  for(i=1;i<=k;++i)
  {
    for(j=1;j<=n;++j)
    {
      for(l=i-1;l<j;++l)
      {
        max(f[i][j],f[i-1][l]+g[l+1][j]);
      }
    }
  }
  cout<<f[k][n]<<endl;
  return 0;
}
inline bool cmp(const string &x,const string &y)
{
  return x.length()<y.length();
}