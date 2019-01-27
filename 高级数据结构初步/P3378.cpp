#include<iostream>
#define ll long long
#define MAXN 1000010
using namespace std;
ll hp[MAXN],n=0,cnt=0;
inline void insert(const ll&);
inline ll top();
inline void pop();
int main()
{
	ll i=0;
	
	return 0;
}
inline void pop()
{
	int i=1,j=0;
	hp[1]^=hp[cnt--]^=hp[1];
	for(j=3;j<=cnt;)
	return;
}
inline ll top()
{
	return hp[1];
}
