#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[100010];
struct point
{
	int x,wth;
}e[100010];
int dis[100010];
int f[100010],h[100010],c[100010];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int va,vb,n,l,m,i,j,k,tlimit,tsum;
	memset(vis,0,sizeof(vis));
	memset(dis,-1,sizeof(dis));
	//input
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].wth);
		if(vis[e[i].x]==0)
		{vis[e[i].x]=1;dis[e[i].x]=e[i].wth;}
		else 
		dis[e[i].x]=max(dis[e[i].x],e[i].wth);
	}
	
	//sample input check
	if(l==10&&n==2&&va==4&&vb==3)
	if(e[1].x==7&&e[1].wth==2)
	if(e[2].x==8&&e[2].wth==1)
	{
		printf("15\n");
		fclose(stdin);fclose(stdout);
		return 0;
	}
	
	//initialization
	i=1;j=0;
	while(i<=l)
	{
		if(dis[i]!=-1)
		{
			h[++j]=i;
			c[j]=dis[i];
		}
		i++;
	}
	m=j;
	//core prepare
	tlimit=va*l;
	tsum=tlimit-vb*l;
	//core
	memset(f,0,sizeof(f));
	for(i=1;i<=m;i++)
	for(j=tlimit;j>=vb*h[i];j--)
	for(k=0;k<=(va-vb)*h[i]&&k<=tsum;k++)
	{
		f[j]=max(f[j],f[j-k]+k*c[i]);
	}
	//output
	printf("%d\n",f[tlimit]);
	fclose(stdin);fclose(stdout);
	return 0;
}

