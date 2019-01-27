#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#define MAXN 1010
#define rr(x) (rand()%(x))
using namespace std;
int n=0;
string s[MAXN],a;
ofstream fout;
int main()
{
  int i=0,j=0;
  srand(time(NULL));
  n=rr(MAXN)+1;
  //n=2;
  for(i=0;i<n;++i)
  {
  	a.push_back(rr(26)+'A');
  }
  fout.open("hidden.ans");
  fout<<a<<'.'<<endl;
  fout.close();
  s[0]=a+'.';
  ++n;
  for(i=1;i<n;++i)
  {
  	s[i]=s[i-1].substr(1,n-1)+s[i-1][0];
  }
  sort(s,s+n);
  fout.open("hidden.in");
  for(i=0;i<n;++i)
  {
  	fout<<s[i][n-1];
  }
  fout<<endl;
  fout.close();
  return 0;
}
