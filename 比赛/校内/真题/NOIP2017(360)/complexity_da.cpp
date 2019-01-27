#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 100
#define MAXC 26
#define rr(x) (rand()%(x))
using namespace std;
char a[MAXN];
int main()
{
  int i=0,n=6;
  srand(time(NULL));
  cout<<1<<endl;
  cout<<n<<" O(n^10)"<<endl;
  for(i=1;i<=n;++i)
  {
  	a[i]=rr(2)?'F':'E';
  }
  for(i=1;i<=n;++i)
  {
  	cout<<a[i];
  	if(a[i]=='F')
  	{
  	  cout<<' '<<(char)('a'+rr(MAXC))<<' ';
	  (rr(2)?cout<<'n':cout<<rr(MAXC));
	  cout<<' ';
	  (rr(2)?cout<<'n':cout<<rr(MAXC));
	  cout<<endl;
	}
	else
	{
	  cout<<endl;
	}
  }
}
