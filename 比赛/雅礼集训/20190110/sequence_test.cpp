#include<iostream>
using namespace std;
int main()
{
  register int i=0,j=0;
  for(i=0;i<=10;++i)
  {
    for(j=0;j<=10;++j)
    {
      cout<<i<<'&'<<j<<'='<<(i&j)<<' ';
    }
    cout<<endl;
  }
  return 0;
}