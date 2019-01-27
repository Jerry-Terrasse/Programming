#include<iostream>
#include<queue>
using namespace std;
inline bool ok(string);
void dfs(int);
int n=0,ml=0;
char wir[2000];
char ds[5000];
int main()
{
  int i=0;
  bool bo=false;
  cin>>n;
  for(;i<n;i++)
  {
  	cin>>wir[i];
  	if(ml<wir[i].length())
  	{
  	  ml=wir[i].length();
	}
  }
  ml*=2;
  memset(ds,'0',sizeof(ds));
  dfs(0);
  cout<<"NIE"<<endl;
  return 0;
}
void dfs(int x)
{
  
}
inline bool ok(string s)
{
  int mid=s.length()/2;
  return s.substr(0,mid)==s.substr(mid,mid);
}
