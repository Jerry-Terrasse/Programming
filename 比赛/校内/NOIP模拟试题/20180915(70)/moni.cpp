#include<iostream>
#include<algorithm>
#include<map>
#define ll long long
#define MAXN 100010
using namespace std;
struct rec
{
  ll f,xm;
}r[MAXN];
ll o[MAXN][2],xt[MAXN],g[MAXN],cnt=0,n=0,q=0;
map<ll,int>id;
inline ll record(ll);
inline bool cmp(const rec&,const rec&);
inline int search(ll);
inline void read(ll&);
int main()
{
  ll i=1,t=0,m=0,s=0;
  char e='\0';
  //freopen("moni.in","r",stdin);freopen("moni.out","w",stdout);
  for(read(n),read(q);i<=n;i++)
  {
  	cin>>e;read(xt[i]);read(o[i][1]);
  	o[i][0]=(e=='-');
  }
  for(i=1;i<n;i++)
  {
  	xt[i]=xt[i+1]-xt[i];
  }
  xt[n]=0;
  for(i=1;i<=n;i++)
  {
  	if(o[i][0])
  	{
  	  m-=o[i][1];
	}
	else
	{
	  m+=o[i][1];
	}
	t=record(m);
	r[t].xm=m;
	r[t].f+=xt[i];
	if(i==n)
	{
	  s=m;
	}
  }
  sort(r+1,r+cnt+1,cmp);
  for(i=2;i<=cnt;i++)
  {
  	r[i].f+=r[i-1].f;
  }
  for(i=2;i<=cnt;i++)
  {
  	g[i]=r[i-1].f*(r[i].xm-r[i-1].xm);
  }
  for(i=2;i<=cnt;i++)
  {
  	g[i]+=g[i-1];
  }
  for(i=1;i<=q;i++)
  {
  	read(m);
  	m=-m;
  	if(m>s)
  	{
  	  cout<<"INFINITY"<<endl;
  	  continue;
	}
  	t=search(m);
  	if(t>0)
  	{
	  cout<<g[t]<<endl;
	}
	else if(t==0)
	{
	  cout<<0<<endl;
	}
	else
	{
	  t=-t;
	  if(r[t].xm>m)
	  {
	  	t--;
	  }
	  cout<<g[t]+(m-r[t].xm)*r[t].f<<endl;
	}
  }
  //fclose(stdin);fclose(stdout);
  return 0;
}
inline void read(ll &x)
{
  char w=1,c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar())
  {
  	if(c=='-')
  	{
  	  w=-w;
	}
  }
  for(;'0'<=c&&c<='9';c=getchar())
  {
  	x=(x<<3)+(x<<1)+c-'0';
  }
  x*=w;
  return;
}
inline int search(ll x)
{
  int left=1,right=cnt+1,mid=(left+right)>>1;
  for(;left<right;mid=(left+right)>>1)
  {
  	if(r[mid].xm==x)
  	{
  	  return mid;
	}
	if(r[mid].xm>x)
	{
	  right=mid;
	}
	else
	{
	  left=mid+1;
	}
  }
  return -mid;
}
inline bool cmp(const rec& a,const rec& b)
{
  return a.xm<b.xm;
}
inline ll record(ll x)
{
  if(id.count(x))
  {
  	return id[x];
  }
  else
  {
	cnt++;
	id.insert(make_pair(x,cnt));
  	return cnt;
  }
}
