//#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
using namespace std;
struct cpt
{
  int s,w,id;
}a[200000],c[200000];
int n=0,r=0,q=0;
inline bool cmp(const cpt&,const cpt&);
void msort(int,int);
int main()
{
  freopen("P1309#2.in","r",stdin);
  int i=0,j=0,k=0;
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
  sort(a,a+n,cmp);
  //printf("competiting\n");
  for(k=0;k<r;k++)
  {
    /*for(i=0;i<n;i++)
  	{
  	  printf("%i ",a[i].id);
	}
	printf("\n");*/
	for(i=0;i<n;i+=2)
    {
      a[j=i+(a[i].w<a[i+1].w)].s++;
      /*for(;j;j--)
      {
      	if((a[j-1].s>a[j].s)||((a[j-1].s==a[j].s)&&(a[j-1].id<a[j].id)))
      	{
      	  break;
		}
		swap(a[j],a[j-1]);
	  }*/
    }
    msort(0,n-1);
  }
  printf("%i",a[q].id+1);
  fclose(stdin);
}
inline bool cmp(const cpt& x,const cpt& y)
{
  return (x.s>y.s)||((x.s==y.s)&&(x.id<y.id));
}
void msort(int l,int r)
{
  if(l+1==r)
  {
  	if(cmp(a[l],a[r]))
  	{
  	  return;
	}
	{
	  swap(a[l],a[r]);
	  return;
	}
  }
  else if(l>=r)
  {
  	return;
  }
  int i=l,mid=(l+r)/2,j=mid+1,p=l;
  msort(l,mid);
  msort(mid+1,r);
  for(;(i<=mid)&&(j<=r);)
  {
  	if(cmp(a[i],a[j]))
  	{
  	  c[p++]=a[i++];
	}
	else
	{
	  c[p++]=a[j++];
	}
  }
  for(;i<=mid;c[p++]=a[i++]);
  for(;j<=r;c[p++]=a[j++]);
  for(i=l;i<=r;a[i]=c[i],i++);
  return;
}
