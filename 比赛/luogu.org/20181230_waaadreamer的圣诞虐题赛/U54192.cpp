#include<iostream>
#include<map>
#include<vector>
//#define MAXN 300300
#define int long long
#define MAXN 2010
#define H 19491001
using namespace std;
int a[MAXN],n=0,cnt=0;
long long ans=0;
map<unsigned long long,int>mp;
vector<pair<int,int> >mmp[MAXN*MAXN];
signed main()
{
  register int i=0,j=0,x=0,y=0;
  register unsigned int hs=0;
  register map<unsigned long long,int>::iterator it;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  for(i=1;i<n;++i)
  {
    for(j=i+1,hs=0;j<=n;++j)
    {
      hs+=(unsigned long long)2000000007LL+a[j]-a[j-1];
      hs*=H;
      hs%=4611686014132420609;
      if(mp.count(hs))
      {
        x=mp[hs];
        mmp[x].push_back(make_pair(i,j));
      }
      else
      {
        mmp[++cnt].push_back(make_pair(i,j));
        mp.insert(make_pair(hs,cnt));
      }
      //++mp[hs];
      //cout<<i<<','<<j<<':'<<hs<<endl;
    }
  }
  ans=n*(n-1)>>1;
  for(it=mp.begin();it!=mp.end();++it)
  {
    for(x=it->second,i=0,y=mmp[x].size();i<y;++i)
    {
      for(j=i+1;j<y;++j)
      {
        /*l1=mmp[x][i].first;
        r1=mmp[x][i].second;
        l2=mmp[x][j].first;
        r2=mmp[x][j].second;
        if(l1<l2)
        {
          
        }
        if(l1>l2)
        {
          
        }*/
        ans+=(mmp[x][i].first-mmp[x][j].second)*(mmp[x][j].first-mmp[x][i].second)<0;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}