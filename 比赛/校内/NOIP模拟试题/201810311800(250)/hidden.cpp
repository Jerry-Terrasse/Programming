#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 30030
using namespace std;
int n=0;
string f[MAXN],a="";
//inline void out();
int main()
{
  register int i=0,j=0;
  freopen("hidden.in","r",stdin);freopen("hidden.out","w",stdout);
  cin>>a;
  n=a.length();
  for(i=0;i<n;++i)
  {
  	f[0].push_back('\0');
  }
  for(i=1;i<n;++i)
  {
  	f[i]=f[0];
  }
  for(i=0;i<n;++i)
  {
  	f[i][n-1]=a[i];
  }
  //out();
  for(i=1;i<n;++i)
  {
  	sort(f,f+n);
  	//out();
  	for(j=0;j<n;++j)
  	{
  	  f[j][n-i-1]=a[j];
	}
	//out();
  }
  for(i=0;i<n;++i)
  {
  	if(f[i][n-1]=='.')
  	{
  	  cout<<f[i]<<endl;
  	  return 0;
	}
  }
  return 0;
}
/*inline void out()
{
  register int i=0;
  for(;i<n;++i)
  {
  	cout<<f[i]<<endl;
  }
  cout<<"********************"<<endl;
  return;
}*/
/*inline bool cmp(const char *a,const char *b)
{
  for(register int i=0;i<n;++i)
  {
  	if(a[i]!=b[i])
  	{
  	  return a[i]<b[i];
	}
  }
  return false;
}*/
