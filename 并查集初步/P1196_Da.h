#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAXN 30030
#define MAX 30000
#define rr(x) (rand()%(x))
using namespace std;
int us[MAXN],t=0;
int main()
{
  register int u=0,v=0;
  srand(time(NULL));
  t=10;
  n=10;
  for(;t--;)
  {
    if(rr(2))
    {
      cout<<'C'<<rr(n)+1<<' '<<rr(n)+1<<endl;
    }
    else
    {
      for(u=rr(n)+1,v=rr(n)+1;find(u)==find(v);u=rr(n)+1,v=rr(n)+1);
      us[us[u]]=us[v];
      cout<<'M'<<u<<' '<<v<<endl;
    }
  }
  return 0;
}