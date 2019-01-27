#include<iostream>
#include<set>
#define MAXN 10010
using namespace std;
string s="";
int n=0,ans=0;
set<unsigned long long>st;
void hs();
int main()
{
  int i=0;
  for(cin>>n;i<n;i++)
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
  	x+=s[i]-'/';
  	x*=13331;
  }
  if(st.find(x)==st.end())
  {
  	st.insert(x);
  	ans++;
  }
  return;
}
