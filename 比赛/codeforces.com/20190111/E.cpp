#include<iostream>
#define MAXN 500050
using namespace std;
int n=0,a=0,b=0;
int main()
{
  register int i=0,x=0,y=0;
  register char c='\0';
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(;n--;)
  {
    cin>>c>>x>>y;
    if(x>y)
    {
      x^=y^=x^=y;
    }
    if(c=='+')
    {
      if(a<x)
      {
        a=x;
      }
      if(b<y)
      {
        b=y;
      }
    }
    else
    {
      if(a<=x&&b<=y)
      {
        cout<<"YES"<<endl;
      }
      else
      {
        cout<<"NO"<<endl;
      }
    }
  }
  return 0;
}