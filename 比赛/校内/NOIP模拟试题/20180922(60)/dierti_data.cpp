#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAXN 10010
using namespace std;
int us[MAXN],n=0;
inline int rr(int);
int find(int);
int main()
{
  int i=1,u=0,v=0;
  srand(time(NULL));
  n=MAXN-1;
  for(cout<<n<<' '<<n<<endl;i<=n;i++)
  {
  	us[i]=i;
  }
  for(i=1;i<n;)
  {
  	u=rr(n)+1;
  	v=rr(n)+1;
  	if(find(u)!=find(v))
  	{
  	  cout<<u<<' '<<v<<endl;
  	  us[us[u]]=us[v];
  	  i++;
	}
  }
  cout<<endl;
  for(i=0;i<n;i++)
  {
  	u=rr(n)+1;
  	v=rr(n)+1;
  	if(u<=v)
  	{
  	  cout<<u<<' '<<v<<endl;
	}
	else
	{
	  cout<<v<<' '<<u<<endl;
	}
  }
  return 0;
}
int find(int x)
{
  return us[x]==x?x:us[x]=find(us[x]);
}
inline int rr(int x)
{
  return rand()*rand()%x;
}
