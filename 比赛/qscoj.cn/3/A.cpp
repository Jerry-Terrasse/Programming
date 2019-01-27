#include<iostream>
#include<set>
#include<cstring>
using namespace std;
int n=0,ans=0;
string s="";
set<unsigned long long>st;
void hs();
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  for(cin>>n;n;n--)
  {
  	cin>>s;
	hs();
  }
  cout<<ans<<endl;
  return 0;
}
void hs()
{
  unsigned long long x=0;
  int i=0;
  for(;i<s.length();i++)
  {
  	x+=s[i];
  	x*=13331;//2333;
  }
  if(st.find(x)==st.end())
  {
  	st.insert(x);
  	ans++;
  }
  return;
}
