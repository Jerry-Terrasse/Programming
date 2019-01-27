#include<iostream>
#include<cstdlib>
#include<ctime>
//#define MAXN 1010
#define MAXN 200020
#define rr(x) (rand()%(x))
using namespace std;
int us[MAXN],n=0;
inline int find(const int&);
inline void init();
int main()
{
  register int o=0,i=0,j=0;
  srand(time(NULL));
  n=200000;
  cout<<n<<endl;
  for(o=0;o<2;++o,(cout<<endl))
  for(init(),i=1;i<n;)
  {
    j=rr(n)+1;
    if(i+1==j||find(i+1)==find(j))
    {
      continue;
    }
    us[us[i+1]]=us[j];
    cout<<j<<' ';
    ++i;
  }
  cout<<rr(n-1)+1<<endl;
  return 0;
}
inline void init()
{
  register int i=0;
  for(i=1;i<=n;++i)
  {
    us[i]=i;
  }
  return;
}
inline int find(const int &x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}