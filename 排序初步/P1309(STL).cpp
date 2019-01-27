#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
using namespace std;
struct cpt
{
  int s,w,id;
}a[200000];
int n=0,r=0,q=0;
inline bool cmp(const cpt&,const cpt&);
int main()
{
  int i=0,k=0;
  scanf("%i%i%i",&n,&r,&q);
  n<<=1;
  q--;
  for(i=0;i<n;i++)
  {
  	scanf("%i",&a[a[i].id=i].s);
  }
  for(i=0;i<n;i++)
  {
  	scanf("%i",&a[i].w);
  }
  for(k=0;k<r;k++)
  {
  	for(i=0;i<n;i++)
  	{
  	  printf("%i ",a[i].id);
	}
	printf("\n");
	sort(a,a+n,cmp);
    for(i=0;i<n;i+=2)
    {
      a[i+(a[i].w<a[i+1].w)].s++;
    }
  }
  sort(a,a+n,cmp);
  printf("%i",a[q].id+1);
}
inline bool cmp(const cpt& x,const cpt& y)
{
  return (x.s>y.s)||((x.s==y.s)&&(x.id<y.id));
}
