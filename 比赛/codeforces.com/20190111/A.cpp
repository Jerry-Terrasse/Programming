#include<iostream>
using namespace std;
int l=0,r=0,d=0,q=0;
int main()
{
  register int i=0;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>q;
  for(;q--;)
  {
    cin>>l>>r>>d;
    if(d<l)
    {
      cout<<d<<endl;
    }
    else
    {
      if(r%d)
      {
        cout<<r+d-r%d<<endl;
      }
      else
      {
        cout<<r+d<<endl;
      }
    }
  }
  return 0;
}