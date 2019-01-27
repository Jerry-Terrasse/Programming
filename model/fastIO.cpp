#include<cstdio>
namespace fastIO
{
  #define M_fIO 1<<17
  char buf[M_fIO],*p=buf,*ed=buf;
  inline void gt();
  inline void read(int&);
}
using namespace std;
using namespace fastIO;
int main()
{
  int a=0;
  freopen("data.txt","r",stdin);
  read(a);
  printf("%d",a);
  return 0;
}
inline void fastIO::read(int &x)
{
  for(x=0;*p<'0'|*p>'9';)
  {
    if(p==ed)
    {
      gt();
    }
    ++p;
  }
  for(;*p>='0'&*p<='9';)
  {
    if(p==ed)
    {
      gt();
    }
    else
    {
      x=(x<<1)+(x<<3)+(*p^48);
    }
    ++p;
  }
  return;
}
inline void fastIO::gt()
{
  p=buf;
  ed=buf+fread(buf,1,M_fIO,stdin);
  return;
}
