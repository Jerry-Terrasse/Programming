#include<iostream>
#include<cstring>
#include<map>
#define MAXN 50010
using namespace std;
int us[MAXN],n=0;
string name[MAXN];
map<string,int>no;
inline void add(string);
int father(int);
int main()
{
  int i=0,mom=0;
  string cmd="";
  //freopen("gen.in","r",stdin);
  for(i=0;i<=MAXN-1;us[i]=i,i++);
  for(;;)
  {
  	cin>>cmd;
	if(cmd[0]=='?')
	{
	  cmd.erase(0,1);
	  cout<<cmd<<" "<<name[father(no[cmd])]<<endl;
	}
	if(cmd[0]=='+')
	{
	  cmd.erase(0,1);
	  add(cmd);
	  if(father(mom)!=father(no[cmd]))
	  {
	  	us[us[no[cmd]]]=us[mom];
	  }
	  continue;
	}
	if(cmd[0]=='#')
	{
	  cmd.erase(0,1);
	  add(cmd);
	  mom=no[cmd];
	  continue;
	}
  	if(cmd[0]=='$')
  	{
	  return 0;
	}
  }
  return 0;
}
inline void add(string hum)
{
  if(!no.count(hum))
  {
  	n++;
  	no.insert(make_pair(hum,n));
  	name[n]=hum;
  }
  return;
}
int father(int x)
{
  return us[x]==x?x:(us[x]=father(us[x]));
}
