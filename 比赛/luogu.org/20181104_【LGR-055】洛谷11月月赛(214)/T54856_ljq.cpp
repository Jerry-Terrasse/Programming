#include <bits/stdc++.h>
#define long long long
#define MAX (300+20)
#define sqr(x) ((x)*(x))
using namespace std;

int N,d[MAX];
long ans;

inline bool cmp(const int &a,const int &b)
{
	return a>b;
}

int main()
{
	scanf("%d",&N);
	for (register int i=1; i<=N; i++)
		scanf("%d",d+i);
	sort(d+1,d+N+1,cmp);
	for (register int i=1,j=N; i<=j; i++,j--)
		ans+=sqr(d[i]-d[j+1])+sqr(d[j]-d[i]);
	printf("%d",ans);
}
