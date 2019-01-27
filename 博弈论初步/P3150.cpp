#include<iostream>
using namespace std;
int n=0,a=0;
int main()
{
  register int i=0;
  cin>>n;
  for(;n--;)
  {
    cin>>a;
    cout<<(a&1?"zs wins":"pb wins")<<endl;
  }
  return 0;
}