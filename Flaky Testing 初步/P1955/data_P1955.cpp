#include<iostream>
#include<ctime>
#include<cstdlib>
#define ll long long
#define MAXN 110
#define MAXA 1000
using namespace std;
ll a[MAXN<<1],n=0,m=0;
inline ll rr(ll);
int main()
{
  ll i=0;
  srand(time(NULL));
  n=rr((MAXN<<1)-11)+11;
  m=rr(MAXN-5)+5;
  for(;i<n;i++)
  {
  	a[i]=rr(MAXA)+1;
  }
  cout<<1<<endl;
  cout<<m<<endl;
  for(i=0;i<m;i++)
  {
  	cout<<a[rr(n)]<<' '<<a[rr(n)]<<' '<<rr(2)<<endl;
  }
  return 0;
}
inline ll rr(ll x)
{
  return rand()*rand()%x;
}
