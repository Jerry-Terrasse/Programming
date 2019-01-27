#include<iostream>
#include<cstring>
#include<cmath>
#define MAXN 16
#define lbt(x) x&-x
using namespace std;
int st[MAXN],a=0,b=0,c=0,n=0,cnt=0;
void dfs(int);
string s="";
int main()
{
  int i=0,j=0;
  char c='\0';
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>s;
		for(j=0;j<n;j++)
    {
      if(s[j]=='.')
	    {
	  	  st[i]|=(1<<(j+1));
	    }
	  }
  }
  dfs(1);
  cout<<cnt<<endl;
  return 0;
}
void dfs(int x)
{
  int i=0,p=0;
  if(x==n+1)
  {
  	cnt++;
    return;
  }
  p=st[x]|a|(b>>x)|(c>>(n-x));
  p=~p;
  p|=1;
  p^=1;
  for(;i=lbt(p),i<=(1<<n);p-=i)
  {
		a+=i;
		b+=i<<x;
		c+=i<<(n-x);
    //cout<<log2(i)<<endl;
    dfs(x+1);
		a-=i;
		b-=i<<x;
		c-=i<<(n-x);
  }
  return;
}
