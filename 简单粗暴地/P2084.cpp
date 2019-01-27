#include<cstdio>
#include<cstring>
#include<queue>
#define MAXL 100010
using namespace std;
int n=0,m=0;
char s[MAXL];
queue<int>sk;
int main()
{
  register int i=0;
  scanf("%d",&m);
  scanf("%s",&s);
  n=strlen(s);
  for(i=0;i<n;++i)
  {
    if(s[i]!='0')
    {
      sk.push(i);
    }
  }
  for(;sk.size()>1;)
  {
    printf("%c*%d^%d+",s[sk.front()],m,n-sk.front()-1);
    sk.pop();
  }
  if(sk.size())printf("%c*%d^%d",s[sk.front()],m,n-sk.front()-1);
  return 0;
}