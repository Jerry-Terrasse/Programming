//P1245 µç»°ºÅÂë
#include<cstdio>
#include<cstdlib>
#include "memory.h"
#define MAXN 110
using namespace std;
const char st[26]={1,1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6,7,7,7,8,8,8,9,9,9};
struct trie
{
  int end;
  trie *son[17];
  inline trie();
}mmp[MAXN*MAXN],*mtp=mmp,*head=NULL;
char str[MAXN][MAXN],a[MAXN],b[MAXN];
int ans[MAXN],cnt=0,n=0;
inline void read(int&);
void write(const int&);
inline void insert(char*,const int&);
inline void init(char*);
void dfs(int);
inline void out();
int main()
{
  register int i=0;
  head=++mtp;
  read(n);
  scanf("%s",a);
  for(i=0;a[i];a[i++]^=48);
  for(i=1;i<=n;++i)
  {
    scanf("%s",str[i]);
  }
  for(i=1;i<=n;++i)
  {
    init(str[i]);
    if(*b)insert(b,i);
  }
  /*if(head->end)
  {
  	exit(0);
	}*/
  dfs(0);
  printf("No Solutions!");
  return 0;
}
inline trie::trie()
{
  end=0;
  memset(son,0,sizeof(son));
  return;
}
inline void out()
{
  register int i=0;
  for(i=1;i<cnt;++i)
  {
    printf("%s ",str[ans[i]]);
  }
  printf("%s",str[ans[cnt]]);
  exit(0);
}
void dfs(int x)
{
  register trie *p=head;
  for(;a[x];)
  {
    if(p->end)
    {
      ans[++cnt]=p->end;
      dfs(x);
      --cnt;
    }
    if(p->son[a[x]])
    {
      p=p->son[a[x]];
      ++x;
    }
    else
    {
      return;
    }
  }
  if(p->end)
  {
    ans[++cnt]=p->end;
    out();
  }
  return;
}
inline void init(char *a)
{
  register int i=0;
  for(;*a;++i,++a)
  {
    b[i]=st[*a-'a'];
  }
  b[i]='\0';
  return;
}
inline void insert(char *a,const int &id)
{
  register trie *p=head;
  for(;*a;++a)
  {
    if(p->son[*a])
    {
      p=p->son[*a];
    }
    else
    {
      /*if(mtp-mmp==MAXN*MAXN-1)
      {
      	exit(0);
			}*/
      p=p->son[*a]=++mtp;
    }
  }
  p->end=id;
  return;
}
void write(const int &x)
{
  if(x>9)
  {
    write(x/10);
  }
  putchar(x%10^48);
  return;
}
inline void read(int &x)
{
  register char c=getchar();
  for(x=0;c<'0'|c>'9';c=getchar());
  for(;c>='0'&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
