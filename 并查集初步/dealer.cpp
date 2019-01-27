#include<iostream>
#include<map>
using namespace std;
int n=0,cnt=0;
map<int,int>mp;
inline int record(int);
int main()
{
  int u=0,v=0,e=0;
  freopen("P1955#3.in","r",stdin);
  freopen("worked.in","w",stdout);
  cin>>n>>n;
  for(;n--;)
  {
  	cin>>u>>v>>e;
  	u=record(u);
  	v=record(v);
  	cout<<u<<' '<<v<<' '<<e<<endl;
  }
  return 0;
}
inline int record(int x)
{
  if(mp.count(x))
  {
  	return mp[x];
  }
  else
  {
  	cnt++;
  	mp.insert(make_pair(x,cnt));
  	return cnt;
  }
}
