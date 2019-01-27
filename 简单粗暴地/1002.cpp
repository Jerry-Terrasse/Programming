#include<iostream>
using namespace std;
int main()
{
  char a[32]="";
  int i=0;
  for(;a[0]!=' ';cin.get(a[0]))
  {
  }
  for(cin.get(a[0]);a[i]!=' ';cin.get(a[++i]))
  {
  }
  cout<<a<<endl;
  return 0;
}
