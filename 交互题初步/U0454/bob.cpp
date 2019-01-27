#include<iostream>
#include<fstream>
#define MAXN 1010
using namespace std;
int a[MAXN],n=0,m=0;
char ans[MAXN];
ifstream fin("bob.in");
ofstream fout("bob.out");
int main()
{
  register int i=0,j=0;
  register char c='\0';
  //ios::sync_with_stdio(false);cin.tie(0);fin.tie(0);
  fin>>n>>m;
  for(i=1;i<=n;++i)
  {
    fin>>a[i];
  }
  for(i=1,j=0;i<=n;++i)
  {
    for(;j<a[i]-1;j+=2)
    {
      cout<<'1';
      cout.flush();
      cin>>c;
    }
    if(j==a[i])
    {
      ans[i-1]=c;
    }
    else
    {
      cout<<'0';
      cout.flush();
      cin>>c;
      ans[i-1]=c;
      j=a[i];
    }
  }
  if(j<2*n)
  {
    
  for(;j<2*n-1;j+=2)
    {
      cout<<'1';
      cout.flush();
      cin>>c;
    }
    if(j!=2*n)
    {
      cout<<'0';
      cout.flush();
      cin>>c;
    }
  }
  fout<<ans<<endl;
  return 0;
}