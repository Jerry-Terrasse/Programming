#include<iostream>
#define MAXM 5010
using namespace std;
int p[MAXM],a[MAXM],h[MAXM],cnt=0,n=0,m=0,cost=0;
inline void insert(int);
inline int top();
inline void pop();
inline void del(int);
int main()
{
  int i=0;
  ios::sync_with_stdio(0);
  cin>>n>>m;
  p[m+1]=-2002;
  h[0]=m+1;
  for(i=1;i<=m;i++)
  {
  	cin>>p[i]>>a[i];
    insert(i);
  }
  for(;n;)
  {
  	i=top();
  	pop();
  	if(a[i]>=n)
  	{
  	  cost+=p[i]*n;
  	  break;
    }
    else
    {
      n-=a[i];
      cost+=p[i]*a[i];
    }
  }
  cout<<cost<<endl;
  return 0;
}
inline void insert(int x)
{
  int i=++cnt;
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
inline int top()
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
