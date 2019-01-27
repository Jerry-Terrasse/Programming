#include<iostream>
#include<stack>
#include<map>
#define IF else if
using namespace std;
stack<char>q;
map<char,int>mp;
inline bool isnumber(char);
inline bool higherthan(const char&,const char&);
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  mp.insert(make_pair('(',0));
  mp.insert(make_pair('+',1));
  mp.insert(make_pair('-',1));
  mp.insert(make_pair('*',2));
  mp.insert(make_pair('/',2));
  string s="";
  cin>>s;
  for(;i<s.length();i++)
  {
  	if(isnumber(s[i]))
  	{
  	  cout<<s[i]<<endl;
	}
#define supersign ')'
	IF(s[i]== supersign )
#undef supersign
	{
	  for(;q.top()!='(';q.pop())
	  {
	  	cout<<' '<<q.top()<<' '<<endl;
	  }
	  q.pop();
	}
	IF(s[i]=='(')
	{
	  q.push('(');
	}
	else
	{ 
	  for(;!q.empty() && higherthan(q.top() ,s[i] );q.pop())
	  {
	  	cout<<' '<<q.top()<<' '<<endl;
	  }
	  q.push(s[i]);
	}
  }
  for(;!q.empty();q.pop())
  {
  	cout<<' '<<q.top()<<' '<<endl;
  }
  cout<<endl;
  return 0;
}
inline bool higherthan(const char &__ORIginal_beta__ ,const char &__COMParing_alpha__)
{
  return (bool )mp[__ORIginal_beta__]>=mp[__COMParing_alpha__];
}
inline bool isnumber(char __a_char_maybe_between_0_to_9__)
{
  return (bool)('0'<=__a_char_maybe_between_0_to_9__)  and  (__a_char_maybe_between_0_to_9__<='9');
}
