#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#define ll long long
#define H 621641
//#define H   70000000
using namespace std;
int up[H];
map<int,int>mp[H];
string cmd="",ifo="";
inline void def(string);
inline void setvar(string,string);
int exa(string);
inline int hash(string);
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;cin>>cmd>>ifo;)
  {
  	if(cmd=="int")
  	{
  	  def(ifo);
	}
	else if(cmd=="cout")
	{
	  cout<<exa(ifo)<<endl;
	}
	else
	{
	  setvar(cmd,ifo);
	}
  }
  return 0;
}
inline void setvar(string cmd,string ifo)
{
  int name=hash(cmd.substr(0,cmd.find('[')));
  cmd=cmd.substr(cmd.find('[')+1,cmd.length()-cmd.find('[')-2);
  int idx=exa(cmd),val=exa(ifo);
  if(idx<up[name])
  {
  	if(!mp[name].count(idx))
  	{
  	  mp[name].insert(make_pair(idx,val));
	}
	else
	{
	  mp[name][idx]=val;
	}
  }
  else
  {
  	cout<<-1<<endl;
  	exit(0);
  }
  return;
}
int exa(string ifo)
{
  if(isdigit(ifo[0]))
  {
  	int ans=0,i=0;
  	for(i=0;i<ifo.length();++i)
  	{
  	  ans=(ans<<1)+(ans<<3)+(ifo[i]^48);
	}
	return ans;
  }
  else
  {
  	int name=hash(ifo.substr(0,ifo.find('[')));
  	ifo=ifo.substr(ifo.find('[')+1,ifo.length()-ifo.find(('['))-2);
  	int idx=exa(ifo);
  	if(idx<up[name])
  	{
  	  if(mp[name].count(idx))
  	  {
  	    return mp[name][idx];
	  }
	  else
	  {
	  	mp[name].insert(make_pair(idx,0));
	  	return 0;
	  }
	}
	else
	{
	  cout<<-1<<endl;
	  exit(0);
	}
  }
}
inline void def(string cmd)
{
  int name=hash(cmd.substr(0,cmd.find('[')));
  cmd=cmd.substr(cmd.find('[')+1,cmd.length()-cmd.find('[')-2);
  up[name]=exa(cmd);
  return;
}
inline int hash(string s)
{
  ll ans=0;
  int i=0;
  for(i=0;i<s.length();++i)
  {
	ans*=H;
  	ans+=s[i];
  	ans%=H;
  }
  return ans;
}
