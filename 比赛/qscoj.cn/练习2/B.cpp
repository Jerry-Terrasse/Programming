#include<iostream>
#include<vector>
#include<queue>
#define MAXN 100010
#define ok(x) (x>=0)&&(x<=MAXN)
#define pr pair<int,int>
using namespace std;
vector<pr >v[MAXN];
priority_queue<pr,vector<pr >,greater<pr > >q;
int n=0,m=0;
int main()
{
  int i=0,j=0;
  for(;i<MAXN;i++)
  {
  	if(ok(i+2))
  	{
  	  v[i].push_back(make_pair(i+2,1));
	}
	if(ok(i-3))
	{
  	  v[i].push_back(make_pair(i-3,2));
	}
	if(ok(i*4))
	{
  	  v[i].push_back(make_pair(i*4,3));
	}
	if(i%5==0 && ok(i/5))
	{
  	  v[i].push_back(make_pair(i/5,4));
	}
  }
  cin>>n>>m;
  
  return 0;
}
