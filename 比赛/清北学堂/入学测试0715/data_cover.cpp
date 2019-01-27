#include<bits/stdc++.h>
#define INF 0x7fffffffffffffff
#define ll long long
using namespace std;
ll n=0,k=0;
int main()
{
  ll i=0,x=0,y=0;
  srand(time(NULL));
  n=99999;
  k=68778;
  cout<<n<<' '<<k<<endl;
  for(i=1;i<=n;i++)
  {
  	x=(ll)rand()*rand()%(INF-100);
  	for(y=-1;y<x;y=(ll)rand()*rand()%(INF-100));
  	cout<<x<<' '<<y<<endl;
  }
  return 0;
}
