#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int L,n,Va,Vb;
int v;
int t1;
int t;
int w[100005];
int h[100005];
int id[100005];
int vis[100005];
int p=1;
int ans;
bool cmp(int i,int j)
{
	return w[id[i]]>w[id[j]];
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d %d %d %d",&L,&n,&Va,&Vb);
	v=Va-Vb;
	for(int i=1;i<=n;++i)
	{
		id[i]=i;
		scanf("%d %d",&h[i],&w[i]);
	}
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i==1) t=h[i]*v;
		else t=h[i]*v-t;
		for(int j=1;j<=n;j++)
		{
			if(i==id[p]) break;
			if(id[j]==i) {id[j]=0;break;}
		}
		if(i==id[p])
		{
			ans=ans+w[id[p]]*t;
			for(int j=p+1;j<=n;j++)
			{
				if(id[j]!=0) {p=j;break;}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
