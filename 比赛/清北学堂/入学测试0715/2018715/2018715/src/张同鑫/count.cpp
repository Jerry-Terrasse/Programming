#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
int num,ans1,ans2;
char s1[10],g[10][10],now[10];
int vis[30],vis2[30][30];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout); 
	cin>>s1;
	for(int i=0;i<3;i++)
		g[1][i+1]=s1[i]; 
	cin>>s1;
	for(int i=0;i<3;i++)
		g[2][i+1]=s1[i];
	cin>>s1;
	for(int i=0;i<3;i++)
		g[3][i+1]=s1[i];
	for(int i=1;i<=3;i++)
		if(g[i][1]==g[i][2] && g[i][2]==g[i][3] && vis[g[i][1]-'A']==0) vis[g[i][1]-'A']=1,ans1++;
	for(int i=1;i<=3;i++)
		if(g[1][i]==g[2][i] && g[2][i]==g[3][i] && vis[g[1][i]-'A']==0) vis[g[1][i]-'A']=1,ans1++;
	if(g[1][1]==g[2][2] && g[2][2]==g[3][3] && vis[g[1][1]-'A']==0) vis[g[1][1]-'A']=1, ans1++;
	if(g[1][3]==g[2][2] && g[2][2]==g[3][1] && vis[g[1][3]-'A']==0) vis[g[1][3]-'A']=1, ans1++; 
	num=0;
	for(int i=1;i<=3;i++)
	{
		num=0;
		if(vis[g[i][1]-'A']==0) vis[g[i][1]-'A']=1,num++,now[num]=g[i][1];
		if(vis[g[i][2]-'A']==0) vis[g[i][2]-'A']=1,num++,now[num]=g[i][2];
		if(vis[g[i][3]-'A']==0) vis[g[i][3]-'A']=1,num++,now[num]=g[i][3];
		if(num==2)
		{
			if(vis2[now[1]-'A'][now[2]-'A']==0 &&now[1]!=now[2])
			{
				vis2[now[1]-'A'][now[2]-'A']=1;
				vis2[now[2]-'A'][now[1]-'A']=1;
				ans2++;
			}
		}
		memset(vis,0,sizeof(vis));
		memset(now,0,sizeof(now));
		num=0;
	}
	for(int i=1;i<=3;i++)
	{
		num=0; 
		if(vis[g[1][i]-'A']==0) vis[g[1][i]-'A']=1,num++,now[num]=g[i][1];
		if(vis[g[2][i]-'A']==0) vis[g[2][i]-'A']=1,num++,now[num]=g[i][1];
		if(vis[g[3][i]-'A']==0) vis[g[3][i]-'A']=1,num++,now[num]=g[i][1];
		if(num==2)
		{
			if(vis2[now[1]-'A'][now[2]-'A']==0&& now[1]!=now[2])
			{
				vis2[now[1]-'A'][now[2]-'A']=1;
				vis2[now[2]-'A'][now[1]-'A']=1;
				ans2++;
			}
		}
		memset(vis,0,sizeof(vis));
		memset(now,0,sizeof(now));
		num=0;
	}
	num=0; 
	if(vis[g[1][1]-'A']==0) vis[g[1][1]-'A']=1,num++,now[num]=g[1][1];
	if(vis[g[2][2]-'A']==0) vis[g[2][2]-'A']=1,num++,now[num]=g[2][2];
	if(vis[g[3][3]-'A']==0) vis[g[3][3]-'A']=1,num++,now[num]=g[3][3];
	if(num==2)
	{
		if(vis2[now[1]-'A'][now[2]-'A']==0 && now[1]!=now[2])
		{
			vis2[now[1]-'A'][now[2]-'A']=1;
			vis2[now[2]-'A'][now[1]-'A']=1;
			ans2++;
		}
	}
	memset(vis,0,sizeof(vis));
	memset(now,0,sizeof(now));
	num=0;
	if(vis[g[1][3]-'A']==0) vis[g[1][3]-'A']=1,num++,now[num]=g[1][3];
	if(vis[g[2][2]-'A']==0) vis[g[2][2]-'A']=1,num++,now[num]=g[2][2];
	if(vis[g[3][1]-'A']==0) vis[g[3][1]-'A']=1,num++,now[num]=g[3][1];
	if(num==2)
	{
		if(vis2[now[1]-'A'][now[2]-'A']==0 && now[1]!=now[2])
		{
			vis2[now[1]-'A'][now[2]-'A']=1;
			vis2[now[2]-'A'][now[1]-'A']=1;
			ans2++;
		}
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
