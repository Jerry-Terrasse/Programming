#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
  srand(time(NULL));
  cout<<rand()%17<<' '<<rand()%17<<endl;
  return 0;
}
