#include<iostream>
#include<ctime>
using namespace std;
int e=0,s=0;
int main()
{
  int i=0;
  s=clock();
  system("sort.exe <sort#4.in >sort.out");
  e=clock();
  cout<<e-s<<endl;
  return 0;
}
