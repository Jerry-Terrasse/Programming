#include<iostream>
#include<ctime>
//#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
  unsigned long long x=0,y=0;
  srand(time(NULL));
  x=rand();
  y=rand();
  cout<<x<<endl<<y<<endl;
}
