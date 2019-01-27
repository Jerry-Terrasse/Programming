#include<cstdio>
#define MAXL 110
using namespace std;
int use[MAXL],f[MAXL],fc=0;
char a[MAXL];
int main()
{
  register int i=0;
  scanf("%s",a);
  for(i=0;a[i];++i)
  {
    switch(a[i])
    {
      case '(':
        f[++fc]=i;
        use[i]=')';
        break;
      case '[':
        f[++fc]=i;
        use[i]=']';
        break;
      case ')':
        if(fc&&a[f[fc]]=='(')
        {
          use[f[fc--]]=0;
        }
        else
        {
          use[i]=-'(';
        }
        break;
      case ']':
        if(fc&&a[f[fc]]=='[')
        {
          use[f[fc--]]=0;
        }
        else
        {
          use[i]=-'[';
        }
        break;
    }
  }
  for(i=0;a[i];++i)
  {
    if(use[i])
    {
      if(use[i]>0)
      {
        putchar(a[i]);
        putchar(use[i]);
      }
      else
      {
        putchar(-use[i]);
        putchar(a[i]);
      }
    }
    else
    {
      putchar(a[i]);
    }
  }
  return 0;
}