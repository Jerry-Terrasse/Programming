#include<cstdio>
#include<vector>
#define ll long long
#define MAXN 100010
//#define dsfsdfdsfd fdssssssssssssssss333333333444434444444444444444444444444444444444444444444444444444444444
using namespace std;
struct edge
{
  int to,next;
}e[MAXN<<1];
int head[MAXN],cnt[MAXN],st[MAXN],vis[MAXN],tops=0,n=0,x=0,y=0,anx=0,any=0,mx=0,my=0;
int rec[MAXN*MAXN];
//vector<int>rec[MAXN];
ll a[MAXN];
inline void addedge(ll,ll);
void dfs(ll);
inline void read(ll&);
inline void read(int&);
int main()
{
  int i=1,u=0,v=0;
  freopen("gift.in","r",stdin);//freopen("gift.out","w",stdout);
  //printf("emmmmmm");
  for(read(n),read(x),read(y);i<=n;i++)
  {
  	read(a[i]);
  }
  for(i=1;i<n;i++)
  {
  	read(u);read(v);
  	addedge(u,v);
  }
  dfs(1);
  for(read(u);u--;)
  {
  	read(v);
  	anx=any=mx=my=0;
	if(y)
  	{
  	  for(i=0;i<cnt[v];i++)
  	  {
  	    if(my<a[rec[v*MAXN+i]])
  	    {
  	      any++;
  	      my=a[rec[v*MAXN+i]];
		}
	  }
	}
	if(x)
	{
	  for(i=cnt[v]-1;i>=0;i--)
  	  {
  	    if(mx<a[rec[v*MAXN+i]])
  	    {
  	      anx++;
  	      mx=a[rec[v*MAXN+i]];
		}
	  }
	}
	printf("%d %d\n",anx,any);
  }
  fclose(stdin);fclose(stdout);
  return 0;
}
inline void read(ll &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());//no "-"
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+c-'0';
  }
  return;
}
inline void read(int &x)
{
  char c=getchar();
  for(x=0;c<'0'||c>'9';c=getchar());//no "-"
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+c-'0';
  }
  return;
}
void dfs(ll x)
{
  ll i=0;
  vis[x]=1;
  st[tops++]=x;
  //printf("%d\n",tops);
  for(i=head[x];i;i=e[i].next)
  {
  	if(!vis[e[i].to])
  	{
  	  //printf("lld")
	  dfs(e[i].to);
	}
  }
  for(cnt[x]=0;cnt[x]<tops;cnt[x]++)
  {
  	rec[x*MAXN+cnt[x]]=st[cnt[x]];
  	//rec[x].push_back(st[cnt[x]]);
  }
  tops--;
  return;
}
inline void addedge(ll u,ll v)
{
  e[++cnt[0]].to=v;
  e[cnt[0]].next=head[u];
  head[u]=cnt[0];
  e[++cnt[0]].to=u;
  e[cnt[0]].next=head[v];
  head[v]=cnt[0];
  return;
}
