#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 10
using namespace std;
inline int rr(const int&);
int main()
{
  int i=0;
  srand(time(NULL));
  cout<<rr(MAXN)+1<<' '<<rr(10)+1<<endl;
  return 0;
}
inline int rr(const int &x)
{
  return rand()*rand()%x;
}
