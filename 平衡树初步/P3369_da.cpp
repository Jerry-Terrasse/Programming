#include<iostream>
#include<algorithm>
#include<fstream>
#include<ctime>
#define MAXN 100010
#define rr(x) (rand()%(x))
using namespace std;
int a[MAXN],cnt=0,n=0,m=0;
ofstream fin;
ofstream fout;
inline int getrank(int);
inline int getval(int);
inline int getpre(int);
inline int getnxt(int);
int main()
{
  register int i=0,x=0;
  srand(time(NULL));
  fin.open("P3369.in");
  fout.open("P3369.ans");
  n=10;
  fin<<n<<endl;
  m=n>>1;
  n-=m;
  for(i=1;i<=m;++i)
  {
    a[++cnt]=rr(MAXN);
    fin<<"1 "<<a[cnt]<<endl;
  }
  m=n>>1;
  n-=m;
  for(i=1;i<=m;++i)
  {
    x=rr(cnt)+1;
    fin<<"2 "<<a[x]<<endl;
    a[x]=a[cnt--];
  }
  for(;n--;)
  {
    i=rr(4);
    if(i==0)
    {
      x=rr(cnt)+1;
      fin<<"3 "<<a[x]<<endl;
      fout<<getrank(a[x])<<endl;
    }
    if(i==1)
    {
      x=rr(cnt)+1;
      fin<<"4 "<<x<<endl;
      fout<<getval(x)<<endl;
    }
    if(i==2)
    {
      x=rr(MAXN)+a[1]+1;
      fin<<"5 "<<x<<endl;
      fout<<getpre(x)<<endl;
    }
    if(i==3)
    {
      x=rr(MAXN)%a[1];
      fin<<"6 "<<x<<endl;
      fout<<getnxt(x)<<endl;
    }
  }
  return 0;
}
inline int getrank(int x)
{
  int ret=0;
  sort(a+1,a+cnt+1);
  ret=lower_bound(a+1,a+cnt+1,x)-a;
  return ret;
}
inline int getval(int x)
{
  sort(a+1,a+cnt+1);
  return a[x];
}
inline int getpre(int x)
{
  int ret=0;
  sort(a+1,a+cnt+1);
  ret=lower_bound(a+1,a+cnt+1,x)-a-1;
  return a[ret];
}
inline int getnxt(int x)
{
  int ret=0;
  sort(a+1,a+cnt+1);
  ret=upper_bound(a+1,a+cnt+1,x)-a;
  return a[ret];
}