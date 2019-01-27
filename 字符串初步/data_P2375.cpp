#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,l=0;
inline ll rr(ll);
int main()
{
  ll i=0;
  cout<<1<<endl;
  l=1000000;
  for(;l--;)
  {
  	cout<<(char)('a'+rr(26));
  }
  cout<<endl;
  return 0;
}
inline ll rr(ll x)
{
  return 0;//rand()*rand()%x;
}
