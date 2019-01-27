#include<iostream>
#include<algorithm>
#define ld long double
using namespace std;
int a[10];
int main()
{
  register int i=0;
  for(i=1;i<=7;++i)
  {
    a[i]=i;
  }
  cout<<lower_bound(a+1,a+8,5)-a<<endl;
  cout<<upper_bound(a+1,a+8,5)-a<<endl;
  return 0;
}