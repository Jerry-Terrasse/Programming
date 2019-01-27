#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
#define MAXN 110
using namespace std;
stringstream sio;
int n=0;
vector<int>v;
int main()
{
  string cmd="";
  int i=0,j=0,a=0;
  getline(cin,cmd,'\n');
  for(sio<<cmd;cin>>a;v.push_back(a));
  cin>>a>>cmd;
  for(i=0;i<cmd.length();i++)
  {
    if(cmd[i]=='I')
    {
      cin>>a;
      v.push_back(a);
	}
	else
	{
	  cin>>a;
	  for(j=0;i<v.size();j++)
	  {
	    if(v[j]==a)
	    {
	      v.erase(v.begin()+j);
	      break;
		}
	  }
	}
  }
  for(i=0;i<v.size();j++)
  {
    cout<<v[j]<<' ';
  }
  return 0;
}
