#include<iostream>
#include<algorithm>
#define ld long double
#define ll long long
#define MAXN 10010
using namespace std;
/*struct edge
{
  int to,next;
  ld w;
}e[MAXN];*/
struct eg
{
  int u,v,w;
}gg[MAXN<<4];
ll us[MAXN],head[MAXN],ext[MAXN],c[MAXN],n=0,m=0,cnt=0,emm=0,ans=0,Min=0x7fffffff;
//ld ans=0;
//inline void addedge(int,int,int);
inline bool cmp(eg,eg);
int find(int);
int main()
{
  int i=1,u=0,v=0,w=0;
  freopen("cheer.in","r",stdin);freopen("cheer.out","w",stdout);
  for(cin>>n>>m;i<=n;i++)
  {
  	cin>>c[i];
  	if(c[i]<Min)
  	{
  	  Min=c[i];
	}
  }
  for(i=1;i<=m;i++)
  {
  	cin>>gg[i].u>>gg[i].v>>gg[i].w;
  	gg[i].w<<=1;
  	gg[i].w+=c[gg[i].u]+c[gg[i].v];
  	//cout<<gg[i].u<<','<<gg[i].v<<','<<gg[i].w<<endl;
  }
  sort(gg+1,gg+m+1,cmp);
  for(i=1;i<=n;i++)
  {
  	us[i]=i;
  }
  for(i=1;emm<n-1;i++)
  {
  	if(find(gg[i].u)==find(gg[i].v))
  	{
  	  continue;
	}
	//ext[gg[i].u]=1;
	//ext[gg[i].v]=1;
	emm++;
  	//cout<<gg[i].u<<','<<gg[i].v<<','<<gg[i].w<<endl;
	//addedge(gg[i].u,gg[i].v,gg[i].w);
	ans+=gg[i].w;
	us[us[gg[i].u]]=us[gg[i].v];
  }
  /*for(i=1;i<n;i++)
  {
  	ans+=e[i].w*2;
  }*/
  cout<<ans+Min<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
int find(int x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline bool cmp(eg a,eg b)
{
  return a.w<b.w;
}
/*inline void addedge(int u,int v,int w)
{
  e[++cnt].to=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
  e[++cnt].to=u;
  e[cnt].w=w;
  e[cnt].next=head[v];
  head[v]=cnt;
  return;
}*/
