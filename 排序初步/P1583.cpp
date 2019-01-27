#include<cstdio>
#include<algorithm>
using namespace std;
struct fri
{
  int w,id;
  inline void input(int);
  inline void work(int);
  inline void outline();
}a[20005];
int n=0,k=0,e[10];
int cmp(fri,fri);
int main()
{
  int i=0;
  scanf("%i%i",&n,&k);
  for(i=0;i<10;i++)
  {
  	scanf("%i",&e[i]);
  }
  for(i=0;i<n;i++)
  {
  	a[i].input(i);
  }
  sort(a,a+n,cmp);
  for(i=0;i<n;i++)
  {
  	a[i].work(i);
  }
  sort(a,a+n,cmp);
  for(i=0;i<k;i++)
  {
  	a[i].outline();
  }
  printf("\n");
  return 0;
}
inline void fri::input(int i)
{
  scanf("%i",&w);
  id=i+1;
}
inline int cmp(fri a,fri b)
{
  return (a.w>b.w)||((a.w==b.w)&&(a.id<b.id));
}
inline void fri::work(int index)
{
  w+=e[index%10];
}
inline void fri::outline()
{
  printf("%i ",id);
}
