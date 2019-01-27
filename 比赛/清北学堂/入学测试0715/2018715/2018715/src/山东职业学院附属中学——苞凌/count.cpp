#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char t[4][4];
int ans,sum,vis[110][110],vi[110][110],s[3][3];
int main()
{
	freopen("count.in","r",stdin);
	freopen("coutn.out","w",stdout);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			cin>>t[i][j];
			s[i][j]=t[i][j]-'0';
		}
	for(int i=0;i<3;i++)
		if(s[i][0]==s[i][1]&&s[i][1]==s[i][2])
				ans++;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			vis[s[i][j]][i]++,vi[j][s[i][j]]++;
	for(int i=0;i<3;i++)
		if(s[0][i]==s[1][i]&&s[1][i]==s[2][i])
			ans++;
	if(s[0][0]==s[1][1]&&s[1][1]==s[2][2])
		ans++;
	if(s[0][2]==s[1][1]&&s[1][1]==s[2][0])
		ans++;
	for(int i=0;i<3;i++)
		if(vis[s[i][0]][i]>=2||vis[s[i][1]][i]>=2)
			sum++;
	for(int i=0;i<3;i++)
		if(vi[i][s[0][i]]>=2||vi[i][s[1][i]]>=2)
			sum++;
	if(s[0][0]==s[1][1]||s[0][0]==s[2][2]||s[1][1]==s[2][2])
		sum++;
	if(s[0][2]==s[1][1]||s[0][2]==s[2][0]||s[1][1]==s[2][0])
		sum++;
	printf("%d\n%d",ans,sum-ans);
	return 0;
}
