#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e6 + 5;

struct Data
{
	int l,r;
}data[maxn];

int n,k,ans;

bool cmp(const Data &a,const Data &b)
{
	return a.l<b.l;
}
void dfs(int ll,int lr,int num,int now,int sum)
{
	
	if(sum==k)
	{
		if(now>ans)
		{
			ans=now;
			return;
		}
		else return;
	}
	if(num==n+1&&sum<k)
		return;
	int l=data[num].l,r=data[num].r;
	dfs(ll,lr,num+1,now,sum);
	if(l<=lr) dfs(lr,r,num+1,now+r-lr,sum+1);
	if(l>lr) dfs(l,r,num+1,now+r-l,sum+1);
	
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&data[i].l,&data[i].r);
	sort(data+1,data+1+n,cmp);
	dfs(0,0,0,0,0);
	cout<<ans;
	return 0;
}
