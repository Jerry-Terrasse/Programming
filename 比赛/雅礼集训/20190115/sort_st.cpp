#include<iostream>
using namespace std;
int main()
{
  register int i=0;
  for(i=1;i<=100;++i)
  {
    cout<<i%11%7%12<<endl;
  }
  return 0;
}