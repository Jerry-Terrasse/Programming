#include<iostream>
#include "memory.h"
#define MAXN 2333333//145253
using namespace std;
struct Stack
{
  int mem[MAXN][2],p;
  inline void push(int,int);
  inline bool top();
  //Stack();
}st;
int bs[MAXN],n=0,t=0;
int find(int);
inline int hash(char*);
int main()
{
  int i=0,x=0,y=0,e=0;
  char xx[16],yy[16];
  bool bo=false;
  for(cin>>t;t--;)
  {
	memset(st.mem,0,sizeof(st.mem));
  	st.p=0;
  	for(i=0;i<MAXN;i++)
  	{
  	  bs[i]=i;
	}
	for(cin>>n;n--;)
  	{
  	  cin>>xx>>yy>>e;
  	  x=hash(xx);
  	  y=hash(yy);
  	  if(e)
  	  {
  	    if(find(x)!=find(y))
  	    {
  	      bs[bs[x]]=bs[y];
  	      //cout<<"Connect:"<<xx<<'&'<<yy<<endl;
		}
	  }
	  else
	  {
	  	st.push(x,y);
	  }
	}
	for(bo=true;st.p;)
	{
	  if(st.top())
	  {
	  	cout<<"NO"<<endl;
	  	bo=false;
	  	break;
	  }
	}
	if(bo)
	{
	  cout<<"YES"<<endl;
	}
  }
  return 0;
}
int find(int x)
{
  return bs[x]==x?x:bs[x]=find(bs[x]);
}
inline int hash(char *s)
{
  int i=0,ans=s[0];
  for(i=1;s[i]!='\0';i++)
  {
  	ans*=131;
  	ans+=s[i];
  	ans%=MAXN;
  }
  return ans;
}
/*Stack::Stack()
{
  memset(mem,0,sizeof(mem));
  p=0;
}*/
inline bool Stack::top()
{
  if(find(mem[p][0])==find(mem[p][1]))
  {
  	return true;
  }
  else
  {
  	p--;
  	return false;
  }
}
inline void Stack::push(int x,int y)
{
  p++;
  mem[p][0]=x;
  mem[p][1]=y;
  return;
}
