#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm> 
#include<cmath>
#include<cstring>
const int MAXN=1e6;
struct Seg
{
	int l,r;
}seg[MAXN];
int n,k,dp[MAXN],vis[MAXN],now,ans;
using namespace std;
bool cmp(Seg A,Seg B)
{
	if(A.l!=B.l) return A.l<B.l;
	else return A.r<B.r;
}
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x; 
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) 
		seg[i].l=read(),seg[i].r=read();
	sort(seg+1,seg+n+1,cmp);
	for(int b=1;b<=min(n,300);b++){
	now=b;
	dp[1]=seg[b].r-seg[b].l;
	vis[now]=1;
	for(int i=2;i<=k;i++)
	{
		int Last;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue ;
			if(seg[j].l>=seg[now].l && seg[j].r<=seg[now].r)
				continue ;
			else
			if(seg[j].l>=seg[now].l && seg[j].l<=seg[j].r && seg[j].r>seg[now].r)
			{
				if(dp[i]<dp[i-1]+seg[j].r-seg[now].r)
				{
					dp[i]=dp[i-1]+seg[j].r-seg[now].r;
					Last=j;
				}
			}	
			else
			if(seg[j].l>seg[now].r)
			{
				if(dp[i]<dp[i-1]+seg[j].r-seg[j].l)
				{
					dp[i]=dp[i-1]+seg[j].r-seg[j].l;
					Last=j;
				}
			}	//dp[i]=max(dp[i],dp[i-1]+seg[j].r-seg[j].l);
			else
			if(seg[j].r>=seg[now].l && seg[j].r<=seg[now].r && seg[j].l<seg[now].l)
			{
				if(dp[i]<dp[i-1]+seg[now].l-seg[j].l)
				{
					dp[i]=dp[i-1]+seg[now].l-seg[j].l;
					Last=j;
				}	
			}//	dp[i]=max(dp[i],dp[i-1]+seg[now].l-seg[j].l);
			else
			if(seg[j].r<seg[now].l)
			{
				if(dp[i]<dp[i-1]+seg[j].r-seg[j].l)
				{
					dp[i]=dp[i-1]+seg[j].r-seg[j].l;
					Last=j;
				}	
			}	//dp[i]=max(dp[i],dp[i-1]+seg[j].r-seg[j].l);
		}
		now=Last;
		vis[now]=1;
		} 
		ans=max(ans,dp[k]);
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
	}	
	printf("%d",ans);
	return 0;
}
