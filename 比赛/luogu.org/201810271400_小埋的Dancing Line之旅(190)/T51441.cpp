#include<iostream>
#define MAXN 1000010
using namespace std;
char a[MAXN];
int n=0,l=0,ans=0;
inline char gt(const int&);
int main()
{
	register int i=0,j=0;
	register bool bo=false;
	cin>>n>>l>>a;
	l=l>>1;
	for(i=0;i<n;++i)
	{
		bo=true;
		for(j=1;j<=l;++j)
		{
			if(gt(i-j)!=gt(i+j))
			{
				bo=false;
				break;
			}
		}
		ans+=bo;
	}
	cout<<ans<<endl;
	return 0;
}
inline char gt(const int &x)
{
	if(x<0)
	{
	  return a[x+n];
  }
  else if(x>=n)
  {
  	return a[x-n];
	}
	return a[x];
}
