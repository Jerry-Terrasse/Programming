#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
	int x;
	int y;
}c[1000010];
bool cmp(Node a,Node b)
{
	return a.y>b.y;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int l,n,va,vb;
	int q=1,i,j;
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(i=1;i<=n;i++)
	{
	   scanf("%d%d",&c[i].x,&c[i].y);	
	}
	int p=1,qdfz=0,ans=0;
	sort(c+1,c+n+1,cmp);
	while(p!=n)
	{
		for(i=p;i<=n;i++)
		{
			if(c[i].x>qdfz)
			{
				p=i;
				break;
			}
		}
		ans=ans+((c[p].x-qdfz)*(va-vb))*c[p].y;
		qdfz=c[p].x;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
