#include<iostream>
#include<queue>
#define MAXN 100010
using namespace std;
priority_queue<int>push;
priority_queue<int,vector<int>,greater<int> >pop;
int a=0,n=0;
void add(int);
inline void output();
int main()
{
  int i=1;
  for(cin>>n;i<=n;i++)
  {
  	cin>>a;
	add(a);
	if(i&1)
	{
	  output();
	}
  }
  return 0;
}
inline void output()
{
  if(push.size()<pop.size())
  {
  	cout<<pop.top()<<endl;
  }
  else
  {
  	cout<<push.top()<<endl;
  }
  return;
}
void add(int x)
{
  if(pop.empty() || x>=pop.top())
  {
  	if(pop.size()>push.size())
  	{
  	  push.push(pop.top());
  	  pop.pop();
  	  add(x);
	}
	else
	{
	  pop.push(x);
	}
  }
  else if(push.empty() || x<=push.top())
  {
  	if(push.size()>pop.size())
  	{
  	  pop.push(push.top());
  	  push.pop();
  	  add(x);
	}
	else
	{
	  push.push(x);
	}
  }
  else
  {
  	if(push.size()<pop.size())
  	{
  	  push.push(x);
	}
	else
	{
	  pop.push(x);
	}
  }
  return;
}
