#include<iostream>
#include<stack>
#include<sstream>
#include<map>
using namespace std;
stringstream sio;
map<char,int>pr;
stack<int>n;
stack<char>o;
int main()
{
  pr.insert(make_pair('(',0));
  pr.insert(make_pair('+',1));
  pr.insert(make_pair('-',1));
  pr.insert(make_pair('*',2));
  pr.insert(make_pair('/',2));
  char c='\0';
  string m="";
  for(;'\n'!=(c=getchar());)
  {
  	switch(c)
  	{
  	  case '(':
  	  	o.push(c);
  	  	break;
  	  case ')':
  	  	cout<<' ';
		for(;'('!=o.top();cout<<o.top(),o.pop());
  	  	o.pop();
  	  	break;
  	  case '+':
	  case '-':
	  case '*':
	  case '/':
	  	cout<<' ';
		for(;(!o.empty()) && (pr[o.top()]>=pr[c]);o.pop())
		{
		  cout<<o.top();
		}
		o.push(c);
		break;
	  default:
  	  	cout<<c;
  	  	break;
	}
  }
  for(;!o.empty();o.pop())
  {
  	cout<<o.top();
  }
  return 0;
}
