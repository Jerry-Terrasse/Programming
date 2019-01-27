#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 1010
#define rrr(x) (rand()*rand()%(x))
using namespace std;
int main()
{
  srand(time(NULL));
  cout<<rrr(MAXN)+1<<endl;
  return 0;
}
