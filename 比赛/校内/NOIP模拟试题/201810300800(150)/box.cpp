#include<iostream>
#include<queue>
#include<algorithm>
#define MAXN 5050
using namespace std;
int a[MAXN],w[MAXN],x[MAXN],y[MAXN],n=0;
//priority_queue<pair<int,int> >q;
inline bool cmp1(const int&,const int&);
inline bool cmp2(const int&,const int&);
int main()
{
  int i=0,j=0;
  freopen("box.in","r",stdin);freopen("box.out","w",stdout);
  //register pair<int,int> x,y;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>a[i];
  	w[i]=1;
  	x[i]=y[i]=i;
  }
  for(;;)
  {
  	sort(x+1,x+n+1,cmp1);
  	sort(y+1,y+n+1,cmp2);
  	for(i=1;i<=n&&(w[y[i]]>a[x[1]]||y[i]==x[1]);++i);
  	if(i>n)
  	{
  	  break;
	}
	cout<<y[i]<<"->"<<x[1]<<endl;
	a[x[1]]-=w[y[i]];
	w[x[1]]+=w[y[i]];
	a[x[1]]=min(a[x[1]],a[y[i]]);
	for(j=1;x[j]!=y[i];++j);
	if(j!=n)
	{
	  x[j]^=x[n]^=x[j]^=x[n];
	}
	if(i!=n)
	{
	  y[i]^=y[n]^=y[i]^=y[n];
	}
	--n;
  }
  cout<<n<<endl;
  return 0;
}
inline bool cmp2(const int &x,const int &y)
{
  return w[x]>w[y]||(w[x]==w[y]&&a[x]<a[y]);
}
inline bool cmp1(const int &x,const int &y)
{
  return a[x]>a[y]||(a[x]==a[y]&&w[x]>w[y]);
}
