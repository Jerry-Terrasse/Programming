#include<bits/stdc++.h>
using namespace std;
int ans;
int n,k;
struct line
{
	int l,r;
}li[100020];
int ll,rr;
//int tot;
int s[100020];
int b[100020];
int ma,mi;
int tot;
int maxx,minn=10000000;
void dfs(int step)
{
//	cout<<1;
	if(step>k) 
	{
	//	cout<<maxx-minn<<" "<<maxx<<" "<<minn<<endl;;
		if(maxx-minn>ans) ans=maxx-minn;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1) continue;
		else
		{
			b[i]=1;
			ma=maxx;
			mi=minn;
			if(li[i].r>maxx) maxx=li[i].r;
			if(li[i].l<minn) minn=li[i].l;
			dfs(step+1);
			maxx=ma;
			minn=mi;
			b[i]=0;
		}
	}
	return;
}
int main()
{
	
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ll,&rr);
		li[i].l=ll;
		li[i].r=rr;
	//	s[i]=rr-ll;
	}
	dfs(1);
	
	printf("%d",ans);
}
