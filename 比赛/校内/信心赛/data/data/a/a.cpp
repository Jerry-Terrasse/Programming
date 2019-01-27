#include <bits/stdc++.h>
using namespace std ;
int n, m ;
const int MAXN = 3010 ;
int dp[MAXN][MAXN], hed[MAXN] ;
struct Edge {
	int r, nxt;
}e[MAXN];
int ecnt = 0;
void addedge(int l, int r)
{
	++ecnt;
	e[ecnt].r=r;
	e[ecnt].nxt=hed[l];
	hed[l]=ecnt;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(hed,0,sizeof(hed));
		ecnt=0;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m) ;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(v,u);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
		  {
				if(i==j)
				{
				  dp[i][j]=1;
				}
				else
				{
					for(int k=hed[i];k&&!dp[i][j];k=e[k].nxt)
					{
						int to=e[k].r;
						dp[i][j]|=dp[to][j];
					}
					for(int k = hed[j];k&&!dp[i][j];k=e[k].nxt)
					{
						int to=e[k].r;
						dp[i][j]|=dp[i][to];
					}
				}
				ans+=dp[i][j];
			}
		}
		printf("%d\n",ans);
	}
}
