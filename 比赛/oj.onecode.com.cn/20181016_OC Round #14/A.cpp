#include<cstdio>
#include<cstring>
#define MAXN 1010
#define MAXC 1024
using namespace std;
char ex[MAXC],s[MAXN],t[MAXN];
int len=0,cnt=0;
int main()
{
  int i=0;
  scanf("%s%s",s,t);
  len=strlen(s);
  for(i=0;i<len;++i)
  {
  	if((ex[s[i]]&&ex[s[i]]!=t[i])||(ex[t[i]]&&ex[t[i]]!=s[i]))
  	{
  	  printf("-1\n");
  	  return 0;
	}
	else
	{
	  ex[s[i]]=t[i];
	  ex[t[i]]=s[i];
	}
  }
  for(i=0;i<MAXC;++i)
  {
  	if(ex[i]&&ex[i]!=i)
  	{
  	  cnt++;
	}
  }
  printf("%d\n",cnt>>1);
  for(i=0;i<MAXC;++i)
  {
  	if(ex[i]&&ex[i]!=i)
  	{
  	  printf("%c %c\n",i,ex[i]);
  	  ex[ex[i]]=0;
  	  ex[i]=0;
	}
  }
  return 0;
}
