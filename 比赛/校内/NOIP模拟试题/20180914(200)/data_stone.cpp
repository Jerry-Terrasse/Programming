#include<bits/stdc++.h>
using namespace std;
int n=0;
inline int rr(int);
int main()
{
  int i=1;
  freopen("stone.in","w",stdout);
  srand(time(NULL));
  n=rr(35)+22;
  for(cout<<n<<endl;i<=n;i++)
  {
  	cout<<rr(1000000001)+1<<' ';
  }
  cout<<endl;
  fclose(stdout);
  return 0;
}
inline int rr(int x)
{
  return rand()%x;
}
