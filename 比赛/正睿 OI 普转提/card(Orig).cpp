#include<iostream>
#include<map>
#define MAXN 300030
using namespace std;
int a[MAXN],b[MAXN],num[MAXN<<1],tim[MAXN<<1],cnt=0,n=0,mx=1;
map<int,int>mp;
int main()
{
  freopen("card.in","r",stdin);freopen("card.out","w",stdout);
  int i=0;
  ios::sync_with_stdio(0); 
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i]>>b[i];
    if(mp.count(a[i]))
    {
      if(++tim[mp[a[i]]]>mx)
      {
      	mx=tim[mp[a[i]]];
	  }
	}
	else
	{
	  mp.insert(make_pair(a[i],cnt));
	  num[cnt]=a[i];
	  tim[cnt]=1;
	}
	if(mp.count(b[i]))
    {
      if(a[i]!=b[i])
	  {
	  	tim[mp[b[i]]]++;
	  }
	  if(tim[mp[b[i]]]>mx)
      {
      	mx=tim[mp[b[i]]];
	  }
	}
	else
	{
	  mp.insert(make_pair(b[i],cnt));
	  num[cnt]=b[i];
	  tim[cnt]=1;
	}
  }
  if((mx<<1)<n)
  {
  	cout<<"Impossible"<<endl;
  	return 0;
  }
  cout<<(n>>1)<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
