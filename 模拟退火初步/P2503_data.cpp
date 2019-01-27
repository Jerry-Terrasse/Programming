#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 7
using namespace std;
int n=0,m=0;
inline int rr(int);
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN)+3;
  m=rr(n-2)+2;
  cout<<n<<' '<<m<<endl;
  for(;i<n;i++)
  {
  	cout<<rr(50)+1<<' ';
  }
  cout<<endl;
  return 0;
}
inline int rr(int x)
{
  return rand()*rand()%x;
}
