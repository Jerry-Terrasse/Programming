#include<iostream>
#include<cstring>
#define MAXN 40
#define H 1000000007
using namespace std;
struct trie
{
  trie *son[MAXN];
  int hav[MAXN],cnt;
  char s[MAXN];
  inline trie();
  void build(const int&);
  void sam();
  void calc();
}mmp[MAXN*MAXN],*head=NULL,*mtp=NULL;
int t=0,n=0,k=0,ans=0,ret=0;
char str[MAXN];
inline void read(int&);
void write(const int&);
void dfs(const int&);
inline void init();
int main()
{
  register int i=0;
  freopen("sam.in","r",stdin);freopen("sam.out","w",stdout);
  read(t);
  for(;t--;)
  {
    ans=0;
    read(n);read(k);
    dfs(0);
    write(ans);
    putchar('\n');
  }
  return 0;
}
void trie::calc()
{
  ++ret;
  if(ret==H)
  {
    ret=0;
  }
  for(register int i=1;i<=cnt;++i)
  {
    son[i]->calc();
  }
  return;
}
void trie::sam()
{
  if(cnt==1)
  {
    strcat(s,son[1]->s);
    memcpy(hav,son[1]->hav,sizeof(hav));
    cnt=son[1]->cnt;
    memcpy(son,son[1]->son,sizeof(son));
    sam();
  }
  else
  {
    for(register int i=1;i<=cnt;++i)
    {
      son[i]->sam();
    }
  }
  return;
}
void trie::build(const int &x)
{
  if(x==n)
  {
    return;
  }
  if(!hav[str[x]-'0'])
  {
    hav[str[x]-'0']=++cnt;
    son[cnt]=mtp++;
    son[cnt]->s[0]=str[x];
  }
  son[hav[str[x]-'0']]->build(x+1);
  return;
}
inline trie::trie()
{
  memset(son,0,sizeof(son));
  memset(s,0,sizeof(s));
  cnt=0;
  return;
}
inline void init()
{
  memset(mmp,0,sizeof(mmp));
  head=NULL;
  mtp=mmp;
  ret=0;
  return;
}
void dfs(const int &x)
{
  register int i=0;
  if(x==n)
  {
    init();
    //str[0]='0';str[1]='1';str[2]='2';str[3]='1';str[4]='2';str[5]='1';str[6]='3';
    head=mtp++;
    for(i=0;i<n;++i)
    {
      head->build(i);
    }
    for(i=1;i<=head->cnt;++i)
    {
      head->son[i]->sam();
    }
    head->calc();
    ans+=ret;
    if(ans>H)
    {
      ans-=H;
    }
    return;
  }
  for(i=0;i<k;++i)
  {
    str[x]='0'+i;
    dfs(x+1);
  }
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
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
    x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}