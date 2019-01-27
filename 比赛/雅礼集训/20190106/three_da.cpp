#include<iostream>
using namespace std;
int n=0;
int main()
{
  register int i=0;
  n=5000;
  cout<<n<<endl;
  for(i=1;i<n;++i)
  {
    cout<<i<<' '<<i+1<<endl;
  }
  cout<<0<<endl;
  return 0;
}