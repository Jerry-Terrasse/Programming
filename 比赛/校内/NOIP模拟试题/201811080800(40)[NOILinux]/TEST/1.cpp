#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX (100000+100)
using namespace std;

struct query
{
	int g,d;
}Q[MAX];

int N,M,A[MAX],f[MAX],ans[MAX]={-1};
short vis[MAX];

inline void read(int &a)
{
	register char c=getchar();
	for (a=0; c<'0'||'9'<c; c=getchar());
	for (; '0'<=c&&c<='9'; c=getchar())
		a=(a<<3)+(a<<1)+(c^48);
}

void write(int a)
{
	if (a>9) write(a/10);
	putchar((a%10)^48);
}

inline bool cmp1(query a,query b)
{
	return a.d<b.d;
}

int main()
{
	//freopen("climb.in","r",stdin);
	//freopen("climb.out","w",stdout);
	read(N); read(M);
	for (register int i=1; i<N; i++)
		read(A[i]);
	for (register int i=1; i<=M; i++)
		read(Q[i].g), read(Q[i].d);
	sort(Q+1,Q+M+1,cmp1);
	Q[0]=Q[M+1]=(query){0,-1};
	for (register int i=1; i<=M+1; i++)
	{
		if (Q[i].d!=Q[i-1].d)
		{
			ans[0]++;
			for (int i=1; i<N; i++)
				ans[i]+=vis[i];
			memset(vis,0,sizeof(vis));
		}
		if (i==M+1) break;
		for (register int k=Q[i].g; k; k=A[k])
		{
			if (vis[k]) break;
			vis[k]=1;
		}
	}
	for (register int i=0; i<N; i++)
		write(ans[i]), puts("");
	return 0;
}
