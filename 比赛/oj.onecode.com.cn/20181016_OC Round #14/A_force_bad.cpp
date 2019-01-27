#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXC 64
#define MAXN 1010
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;
char s[MAXN],t[MAXN],exc[MAXC];
int maxc=0;
void dfs(const int&);
int main()
{
  int i=0;
  memset(exc,-1,sizeof(exc));
  scanf("%s%s",s,t);
  for(i=0;i<strlen(s);++i)
  {
  	maxc=max(maxc,s[i]-'a');
  	maxc=max(maxc,t[i]-'a');
  }
  dfs(0);
  printf("-1\n");
  return 0;
}
inline void output()
{
  int i=0,u=0,v=0,cnt=0;
  char ans[MAXC];
  memset(ans,0,sizeof(ans));
  for(i=0;s[i];++i)
  {
  	if(exc[s[i]-'a']!=s[i]-'a')
  	{
  	  u=s[i]-'a';
  	  v=exc[u]+'a';
  	  if(u>v)
  	  {
  	    u^=v^=u^=v;
	  }
	  ans[u]=v;
	}
  }
  for(i=0;i<=maxc;++i)
  {
  	if(ans[i])
  	{
  	  printf("%c %c\n",i+'a',ans[i]);
	}
  }
  return;
}
inline bool judge()
{
  int i=0;
  for(;s[i];++i)
  {
  	if(exc[s[i]-'a']+'a'!=t[i])
  	{
  	  return false;
	}
  }
  return true;
}
void dfs(const int &x)
{
  if(x==maxc+1)
  {
  	if(judge())
  	{
  	  output();
  	  exit(0);
	}
	return;
  }
  for(exc[x]=0;exc[x]<=maxc;++exc[x])
  {
  	if(exc[exc[x]]==-1)
  	{
  	  exc[exc[x]]=x;
  	  dfs(x+1);
  	  exc[exc[x]]=-1;
	}
	if(exc[x]==x)
	{
	  dfs(x+1);
	}
  }
  return;
}
