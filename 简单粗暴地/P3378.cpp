#include<iostream>
#include<queue>
using namespace std;
int t=0;
priority_queue<int>q;
int main()
{
  register int o=0,x=0;
  ios::sync_with_stdio(false);
  cin>>t;
  for(;t--;)
  {
    cin>>o;
    if(o==1)
    {
      cin>>x;
      q.push(-x);
    }
    else if(o==2)
    {
      cout<<-q.top()<<endl;
    }
    else
    {
      q.pop();
    }
  }
  return 0;
}