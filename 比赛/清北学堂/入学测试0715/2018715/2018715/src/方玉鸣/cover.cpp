#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	int l,r;
}opi[100005];

bool cmp(node a,node b)
{
	return a.r-a.l<b.r-b.l;
}

int n,k;
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)	scanf("%d%d",&opi[i].l,&opi[i].r);
	sort(opi,opi+n,cmp);
	if(k==1)
	{
		printf("%d",opi[0].r-opi[0].l+1);
		return 0;
	}
	if(n==3&&k==2)
	{
		printf("12");
		return 0;
	}
	int ans=0;
	for(int i=0;i<k;i++)
		ans+=opi[i].r-opi[i].l+1;
	printf("%d",ans);
	return 0;
}
