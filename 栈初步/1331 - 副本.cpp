#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
stringstream sio;
stack<int>n;
stack<int>o;
int main()
{
  string m="";
  int i=0,a=0,b=0;
  char c='\0';
  for(;'@'!=(c=getchar());)
  {
  	switch(c)
  	{
  	  case '+':
  	  	a=n.top();
  	  	n.pop();
		b=n.top();
		n.pop();
		b+=a;
		n.push(b);
  	  	break;
  	  case '-':
  	  	a=n.top();
  	  	n.pop();
		b=n.top();
		n.pop();
		b-=a;
		n.push(b);
  	  	break;
  	  case '*':
  	  	a=n.top();
  	  	n.pop();
		b=n.top();
		n.pop();
		b*=a;
		n.push(b);
  	  	break;
  	  case '/':
  	  	a=n.top();
  	  	n.pop();
		b=n.top();
		n.pop();
		b/=a;
		n.push(b);
  	  	break;
	  case '.':
  	  	sio.str("");
  	  	sio.clear();
  	  	sio<<m;
  	  	m="";
  	  	sio>>a;
  	  	n.push(a);
  	  	break;
  	  default:
  	  	m+=c;
  	  	break;
	}
  }
  cout<<n.top()<<endl;
  return 0;
}
