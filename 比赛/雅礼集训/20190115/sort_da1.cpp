#include<iostream>
#include<ctime>
#include<cstdlib>
#include<set>
//#define MAXN 100000
#define MAXN 15
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
set<int>st;
int main()
{
  register int i=0;
  srand(time(NULL));
  n=11;
  cout<<n<<endl;
  for(;n--;)
  {
    i=rr(MAXN)+1;
    if(st.count(i))
    {
      ++n;
    }
    else
    {
      st.insert(i);
      cout<<i<<' ';
    }
  }
  return 0;
}