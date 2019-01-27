#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct stu
{
  int all,chn,id;
  inline void input(int);
}a[20005];
int n=0;
int cmp(stu,stu);
int main()
{
  int i=0;
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
  	a[i].input(i);
  }
  sort(a,a+n,cmp);
  n=min(5,n);
  for(i=0;i<n;i++)
  {
  	printf("%i %i\n",a[i].id,a[i].all);
  }
  printf("\n");
  return 0;
}
inline void stu::input(int i)
{
  scanf("%i",&chn);
  all+=chn;
  for(int j=0;j<=1;j++)
  {
  	scanf("%i",&id);
  	all+=id;
  }
  id=i+1;
}
inline int cmp(stu a,stu b)
{
  return (a.all>b.all)||((a.all==b.all)&&(a.chn>b.chn))||((a.all==b.all)&&(a.chn==b.chn)&&(a.id<b.id));
}
