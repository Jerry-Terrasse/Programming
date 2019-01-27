#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,maxh=0;
int rr(int);
int main()
{
  int i=0,j=0;
  freopen("mountain.in","w",stdout);
  srand(time(NULL));
  //n=200,m=173;
  cin>>n>>m;
  cin>>maxh;
  cout<<n<<' '<<m<<endl;
  cout<<rr(n)+1<<' '<<rr(m)+1<<endl;
  for(i=1;i<=n;i++)
  {
  	for(j=1;j<=m;j++)
  	{
  	  cout<<rr(maxh+1)+1<<' ';
	}
	cout<<endl;
  }
  fclose(stdout);
  return 0;
}
int rr(int p)
{
  return rand()%p;
}
