#include<iostream>
#define MAXM 20010
using namespace std;
long long p[MAXM],h[MAXM],cnt=0,m=0,cost=0,l=0;
inline void insert(long long);
inline long long top();
inline void pop();
inline void del(long long);
int main()
{
  long long i=0,j=0;
  ios::sync_with_stdio(0);
  cin>>m;
  p[m+1]=0x7fffffffffffffff;
  h[0]=m+1;
  for(i=1;i<=m;i++)
  {
    cin>>p[i];
    insert(i);
  }
  for(;;)
  {
  	i=top();
  	pop();
  	j=top();
  	pop();
  	p[i]+=p[j];
	cost+=p[i];
  	if(cnt)
  	{
  	  insert(i);
	}
	else
	{
	  break;
	}
  }
  cout<<cost<<endl;
  return 0;
}
inline void insert(long long x)
{
  long long i=++cnt;
  h[i]=x;
  for(;i>1;)
  {
    if(p[h[i>>1]]>p[h[i]])
    {
      h[i>>1]^=h[i];
      h[i]^=h[i>>1];
      h[i>>1]^=h[i];
      i>>=1;
    }
    else
    {
      break;
    }
  }
  return;
}
inline long long top()
{
  return h[1];
}
inline void pop()
{
  h[1]=h[cnt--];
  int i=1,j=2;
  for(;j<=cnt;)
  {
    if(j<cnt && p[h[j]]>p[h[j+1]])j++;
    if(p[h[i]]>p[h[j]])
    {
      h[i]^=h[j];
      h[j]^=h[i];
      h[i]^=h[j];
      i=j;
      j<<=1;
    }
    else
    {
      break;
    }
  }
}
inline void del(int x)
{
  h[x]=h[cnt--];
  int i=x>>1,j=x;
  if(p[h[j]]<=p[h[i]])
  {
    for(;j>1;)
    {
      if(p[h[i]]>p[h[j]])
      {
        h[i]^=h[j];
        h[j]^=h[i];
        h[i]^=h[j];
        j=i;
        i>>=1;
      }
      else
      {
        break;
      }
    }
  }
  else
  {
    for(i=x,j=x<<1;j<=cnt;)
    {
      if(j<cnt && p[h[j]]>p[h[j+1]])j++;
      if(p[h[i]]>p[h[j]])
      {
        h[i]^=h[j];
        h[j]^=h[i];
        h[i]^=h[j];
        i=j;
        j<<=1;
      }
      else
      {
        break;
      }
    }
  }
  return;
}
