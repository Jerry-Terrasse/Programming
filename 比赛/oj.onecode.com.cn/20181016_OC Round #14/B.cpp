#include<iostream>
#include<algorithm>
#define MAXN 110
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
struct cpt
{
  int c[6],w,id;
  bool bad;
}a[MAXN];
int n=0;
inline bool cmp(const cpt&,const cpt&);
int main()
{
  int i=0,j=0,k=0;
  bool bo=false,sam=false;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=5;++j)
  	{
  	  cin>>a[i].c[j];
	}
	cin>>a[i].w;
	a[i].bad=false;
	a[i].id=i;
  }
  for(i=1;i<=n;++i)
  {
  	for(j=1;j<=n;++j)
  	{
  	  if(j==i)
  	  {
  	    continue;
	  }
	  bo=false;sam=true;
  	  for(k=1;k<=5;++k)
  	  {
  	    if(a[i].c[k]>a[j].c[k])
  	    {
  	      bo=true;
  	      break;
		}
		if(a[i].c[k]!=a[j].c[k])
		{
		  sam=false;
		}
	  }
	  if((!bo)&&(!sam))
	  {
	  	a[i].bad=true;
	  }
	}
  }
  sort(a+1,a+n+1,cmp);
  cout<<a[1].id<<endl;
  return 0;
}
inline bool cmp(const cpt &a,const cpt &b)
{
  return (a.bad<b.bad)||((a.bad==b.bad)&&(a.w<b.w));
}
