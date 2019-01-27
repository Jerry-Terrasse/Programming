#include<iostream>
#include<cstring>
#include<cstdlib>
#define MAXN 100
#define rr(x) (rand()%(x))
using namespace std;
string a[MAXN];
int use[MAXN],n=0,cnt=-0;
int main()
{
  int i=0;
  srand(19260817);
  freopen("null.txt","r",stdin);freopen("result.txt","w",stdout);
  for(;cin>>a[n];++n);
  for(cout<<"wzx:"<<endl;cnt<n/3;)
  {
  	i=rr(n);
  	if(use[i])
  	{
  	  continue;
	}
	use[i]=1;
	++cnt;
	cout<<a[i]<<endl;
  }
  for(cout<<"ljq:"<<endl;cnt<n*2/3;)
  {
  	i=rr(n);
  	if(use[i])
  	{
  	  continue;
	}
	use[i]=1;
	++cnt;
	cout<<a[i]<<endl;
  }
  for(cout<<"zyt:"<<endl;cnt<n;)
  {
  	i=rr(n);
  	if(use[i])
  	{
  	  continue;
	}
	use[i]=1;
	++cnt;
	cout<<a[i]<<endl;
  }
  return 0;
}
