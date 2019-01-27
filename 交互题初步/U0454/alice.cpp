#include<iostream>
#include<fstream>
#define MAXN 1010
using namespace std;
int n=0,m=0;
char a[MAXN<<1];
ifstream fin("alice.in");
int main()
{
  register int i=0;
  register char c='\0';
  //ios::sync_with_stdio(false);cin.tie(0);fin.tie(0);
  fin>>n>>m;
  fin>>a;
  for(i=0;i<2*n;)
  {
    cin>>c;
    if(c=='0')
    {
      ++i;
    }
    else
    {
      i+=2;
    }
    cout<<a[i-1];
    cout.flush();
  }
  return 0;
}