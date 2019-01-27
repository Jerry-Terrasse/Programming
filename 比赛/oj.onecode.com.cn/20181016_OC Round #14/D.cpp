#include<iostream>
#include<vector>
#define MAXN 200020
using namespace std;
struct edge
{
  int to,next;
}e[MAXN<<2];
vector<int>f[MAXN];
char c='\0';
int add[MAXN][MAXN],num[MAXN],head[MAXN],n=0,cnt=0;
inline void add1edge(const int&,const int&);
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,u=0,v=0;
  cin>>n;
  for(i=1;i<n;++i)
  {
  	cin>>u>>v;
  	add1edge(u,v);
  }
  for(i=1;i<=n;++i)
  {
  	for(u=head[i];u;u=e[u].next)
  	{
  	  add2edge(i,e[u].to);
  	  for(v=head[e[u].to];v;v=e[v].next)
  	  {
  	    add2edge(i,e[v].to);
	  }
	}
  }
  
  return 0;
}
inline void add2edge(const int &u,const int &v)
{
  if(u==v||add[u][v])
  {
  	return;
  }
  f[u].push_back(v);
  f[v].push_back(u);
  ++num[u];
  ++num[v];
  add[u][v]=add[v][u]=1;
}
inline void add1edge(const int &u,const int &v)
{
  e[++cnt].next=head[u];
  e[cnt].to=v;
  head[u]=cnt;
  e[++cnt].next=head[v];
  e[cnt].to=u;
  head[v]=cnt;
  return;
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
  return;
}
inline void read(int &x)
{
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
