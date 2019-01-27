#include <cstdio>
#include <algorithm>
using namespace std;
struct Segment
{
	int l,r;
} Segs[100005];

int N,K;


bool cmp(const Segment &a,const Segment &b)
{
	return a.l==b.l?a.r<b.r:a.l<b.l;
}

bool contain(int *arr,int len,int a)
{
	for(int i=1;i<len;i++)
	{
		if(arr[i]==a)
		{
			return true;
		}
	}
	return false;
}

int selected[105];
int ans=0;
void dfs(int depth,int k)
{
	if(k>K)
	{
		int last=0,total=0;
		for(int i=1;i<=K;i++)
		{
			Segment &now=Segs[selected[i]];
			int left=max(last,now.l);
			total+=now.r-left;
			last=now.r;
		}
		ans=max(total,ans);
	}
	else
	{
		for(int i=1;i<=N;i++)
		{
			if(Segs[i].r>Segs[selected[k-1]].r && !contain(selected,k,i))
			{
				selected[k]=i;
				dfs(depth+1,k+1);
				selected[k]=0;
			}
		}
	}
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d",&Segs[i].l,&Segs[i].r);
	}
	sort(Segs+1,Segs+N+1,cmp);

	dfs(1,1);
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
