#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define jg(x,y) ((x)==(y)?0:((x)<(y)?-1:1))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
int f[MAXN],a[MAXN],b[MAXN],n=0,ans=0;
inline char cmp(const int&,const int&);
int main()
{
  int i=0,j=0,k=0,l=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>b[i];//tian
  }
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];//qi
  }
  sort(a+1,a+n+1,cmp);
  sort(b+1,b+n+1,cmp);
  for(i=1,j=1,k=n,l=n;i<=k;)
  {
  	if(a[i]<b[j])
  	{
  	  ++i;
  	  ++j;
  	  ++ans;
	}
	else if(a[i]>b[j])
	{
	  --l;
	  ++i;
	  --ans;
	}
	else
	{
	  if(a[k]<b[l])
	  {
	  	--k;
	  	--l;
	  	++ans;
	  }
	  else if(a[k]>b[l])
	  {
	    ++i;
	    --l;
	    --ans;
	  }
	  else
	  {
	  	ans+=jg(b[l],a[i]);
	  	++i;
	  	--l;
	  }
	}
  }
  cout<<ans*200<<endl;
  return 0;
}
inline char cmp(const int &a,const int &b)
{
  return a>b;
}
