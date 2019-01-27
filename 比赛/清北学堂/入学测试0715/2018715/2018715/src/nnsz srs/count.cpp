#include <iostream>
#include <cstdio>

using namespace std;

char m[4][4];

int ans1,ans2;
int vis[9];

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=3;++j)
		{
			m[i][j]=getchar();
		}
		if(i<=2) getchar();
	}
	if(m[1][1]==m[1][2]&&m[1][2]==m[1][3]) {vis[1]=1;++ans1;}
	if(m[2][1]==m[2][2]&&m[2][2]==m[2][3]) {vis[2]=1;++ans1;}
	if(m[3][1]==m[3][2]&&m[3][2]==m[3][3]) {vis[3]=1;++ans1;}
	if(m[1][1]==m[2][1]&&m[2][1]==m[3][1]) {vis[4]=1;++ans1;}
	if(m[1][2]==m[2][2]&&m[2][2]==m[3][2]) {vis[5]=1;++ans1;}
	if(m[1][3]==m[2][3]&&m[2][3]==m[3][3]) {vis[6]=1;++ans1;}
	if(m[1][1]==m[2][2]&&m[2][2]==m[3][3]) {vis[7]=1;++ans1;}
	if(m[1][3]==m[2][2]&&m[2][2]==m[3][1]) {vis[8]=1;++ans1;}
	if(!((m[1][1]!=m[1][2])&&(m[1][1]!=m[1][3]))) {if(vis[1]!=1) ++ans2;}
	if(!((m[2][1]!=m[2][2])&&(m[2][1]!=m[2][3]))) {if(vis[2]!=1) ++ans2;}
	if(!((m[3][1]!=m[3][2])&&(m[3][1]!=m[3][3]))) {if(vis[3]!=1) ++ans2;}
	if(!((m[1][1]!=m[2][1])&&(m[1][1]!=m[3][1]))) {if(vis[4]!=1) ++ans2;}
	if(!((m[1][2]!=m[2][2])&&(m[1][2]!=m[3][2]))) {if(vis[5]!=1) ++ans2;}
	if(!((m[1][3]!=m[2][3])&&(m[1][3]!=m[3][3]))) {if(vis[6]!=1) ++ans2;}
	if(!((m[1][1]!=m[2][2])&&(m[1][1]!=m[3][3]))) {if(vis[7]!=1) ++ans2;}
	if(!((m[1][3]!=m[2][2])&&(m[1][3]!=m[3][1]))) {if(vis[8]!=1) ++ans2;}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
