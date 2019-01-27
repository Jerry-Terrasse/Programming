#include<cstdio>
#include<cstring>
#define MAXL 500050
using namespace std;
int n=0;
char s[MAXL];
int main()
{
  register int i=0,a=MAXL,b=MAXL,c=MAXL,d=MAXL,cnt=0;
  scanf("%s",s);
  n=strlen(s);
  for(i=0;i<n;++i)
  {
    if(s[i]=='[')
    {
      a=i;
      break;
    }
  }
  for(i=n-1;i>=0;--i)
  {
    if(s[i]==']')
    {
      b=i;
      break;
    }
  }
  if(a==MAXL||b==MAXL)
  {
    puts("-1");
    return 0;
  }
  for(i=a;i<=b;++i)
  {
    if(s[i]==':')
    {
      c=i;
      break;
    }
  }
  for(i=b;i>=a;--i)
  {
    if(s[i]==':')
    {
      d=i;
      break;
    }
  }
  if(c==MAXL||d==MAXL||c>=d)
  {
    puts("-1");
    return 0;
  }
  for(i=c;i<=d;++i)
  {
    if(s[i]=='|')
    {
      ++cnt;
    }
  }
  printf("%d\n",cnt+4);
  return 0;
}