#include<iostream>
#include<queue>
using namespace std;
inline bool ok(string);
int n=0;
string wir[2000];
queue<string>bs;
int main()
{
  int i=0,ml=0;
  string a="",b="";
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
  bs.push("0");
  bs.push("1");
  for(;!bs.empty();)
  {
  	a=bs.front();
  	//cout<<a.length()<<endl;
	if(a.length()>=ml && (!(a.length()&1)) && ok(a))
  	{
  	  cout<<"TAK"<<endl;
  	  return 0;
	}
  	b=a+"0";
  	twice:;
  	bo=true;
  	for(i=0;i<n;i++)
  	{
  	  if(-1!=b.find(wir[i]))
  	  {
  	  	bo=false;
  	  	break;
	  }
	}
	if(bo)
	{
	  bs.push(b);
	}
	if(b[b.length()-1]=='0')
	{
	  b=a+"1";
	  goto twice;
	}
  	bs.pop();
  }
  cout<<"NIE"<<endl;
  return 0;
}
inline bool ok(string s)
{
  int mid=s.length()/2;
  return s.substr(0,mid)==s.substr(mid,mid);
}
