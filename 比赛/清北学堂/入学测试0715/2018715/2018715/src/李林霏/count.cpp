#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

char s[3][3];
bool teamwin[26][26],win[26];
int dif,n,m,ans,tans;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	memset(teamwin,0,sizeof(teamwin));
	memset(win,0,sizeof(win));
	for (int i=0;i<3;i++) scanf("%s",s[i]);
	for (int i=0;i<3;i++)
	{
		if (s[i][0]==s[i][1] && s[i][1]==s[i][2])
		{
			if (!win[s[i][0]-'A']) ans++;
			win[s[i][0]-'A']=1;
		}
		if (s[0][i]==s[1][i] && s[1][i]==s[2][i])
		{
			if (!win[s[0][i]-'A']) ans++;
			win[s[0][i]-'A']=1;
		}
	}
	if (s[0][0]==s[1][1] && s[1][1]==s[2][2])
	{
		if (!win[s[0][0]-'A']) ans++;
		win[s[0][0]-'A']=1;
	}
	if (s[0][2]==s[1][1] && s[1][1]==s[2][0])
	{
		if (!win[s[1][1]-'A']) ans++;
		win[s[1][1]-'A']=1;
	}
	printf("%d\n",ans);
	for (int i=0;i<3;i++)
	{
		dif=1;
		if (s[i][0]!=s[i][1] || s[i][0]!=s[i][2] || s[i][1]!=s[i][2]) dif=2;
		if (s[i][2]!=s[i][1] && s[i][2]!=s[i][0] && s[i][0]!=s[i][1]) dif=3;
		if (dif==2) 
		{
			if (s[i][0]==s[i][1])
			{
				if (!teamwin[s[i][0]-'A'][s[i][2]-'A'] && !teamwin[s[i][2]-'A'][s[i][0]-'A']) 
				{
					teamwin[s[i][0]-'A'][s[i][2]-'A']=teamwin[s[i][2]-'A'][s[i][0]-'A']=1;
					tans++; 
				}
			}
			else if (s[i][0]==s[i][2])
			{
				if (!teamwin[s[i][0]-'A'][s[i][1]-'A'] && !teamwin[s[i][1]-'A'][s[i][0]-'A']) 
				{
					teamwin[s[i][0]-'A'][s[i][1]-'A']=teamwin[s[i][1]-'A'][s[i][0]-'A']=1;
					tans++; 
				}
			}
			else
			{
				if (!teamwin[s[i][0]-'A'][s[i][1]-'A'] && !teamwin[s[i][1]-'A'][s[i][0]-'A']) 
				{
					teamwin[s[i][0]-'A'][s[i][1]-'A']=teamwin[s[i][1]-'A'][s[i][0]-'A']=1;
					tans++; 
				}
			}
		}
		dif=1;
		if (s[0][i]!=s[1][i] || s[0][i]!=s[2][i] || s[1][i]!=s[2][i]) dif=2;
		if (s[1][i]!=s[2][i] && s[2][i]!=s[0][i] && s[0][i]!=s[1][i]) dif=3;
		if (dif==2) 
		{
			if (s[0][i]==s[1][i])
			{
				if (!teamwin[s[0][i]-'A'][s[2][i]-'A'] && !teamwin[s[2][i]-'A'][s[0][i]-'A']) 
				{
					teamwin[s[0][i]-'A'][s[2][i]-'A']=teamwin[s[2][i]-'A'][s[0][i]-'A']=1;
					tans++; 
				}
			}
			else if (s[0][i]==s[2][i])
			{
				if (!teamwin[s[0][i]-'A'][s[1][i]-'A'] && !teamwin[s[1][i]-'A'][s[0][i]-'A']) 
				{
					teamwin[s[0][i]-'A'][s[1][i]-'A']=teamwin[s[1][i]-'A'][s[0][i]-'A']=1;
					tans++; 
				}
			}
			else
			{
				if (!teamwin[s[0][i]-'A'][s[2][i]-'A'] && !teamwin[s[2][i]-'A'][s[0][i]-'A']) 
				{
					teamwin[s[0][i]-'A'][s[2][i]-'A']=teamwin[s[2][i]-'A'][s[0][i]-'A']=1;
					tans++; 
				}
			}
		}
	}
	dif=1;
	if (s[0][0]!=s[1][1] || s[1][1]!=s[2][2] || s[0][0]!=s[2][2]) dif=2;
	if (s[0][0]!=s[1][1] && s[1][1]!=s[2][2] && s[0][0]!=s[2][2]) dif=3;
	if (dif==2)
	{
		if (s[0][0]==s[1][1])
		{
			if (!teamwin[s[0][0]-'A'][s[2][2]-'A'] && !teamwin[s[2][2]-'A'][s[0][0]-'A'])
			{
				teamwin[s[0][0]-'A'][s[2][2]-'A']=teamwin[s[2][2]-'A'][s[0][0]-'A']=1;
				tans++;
			}
		}
		else if (s[0][0]==s[2][2])
		{
			if (!teamwin[s[0][0]-'A'][s[1][1]-'A'] && !teamwin[s[1][1]-'A'][s[0][0]-'A'])
			{
				teamwin[s[0][0]-'A'][s[1][1]-'A']=teamwin[s[1][1]-'A'][s[0][0]-'A']=1;
				tans++;
			}
		}
		else
		{
			if (!teamwin[s[0][0]-'A'][s[2][2]-'A'] && !teamwin[s[2][2]-'A'][s[0][0]-'A'])
			{
				teamwin[s[0][0]-'A'][s[2][2]-'A']=teamwin[s[2][2]-'A'][s[0][0]-'A']=1;
				tans++;
			}
		}
	}
	dif=1;
	if (s[0][2]!=s[1][1] || s[1][1]!=s[2][0] || s[0][2]!=s[2][0]) dif=2;
	if (s[0][2]!=s[1][1] && s[1][1]!=s[2][0] && s[0][2]!=s[2][0]) dif=3;
	if (dif==2)
	{
		if (s[0][2]==s[1][1])
		{
			if (!teamwin[s[0][2]-'A'][s[2][0]-'A'] && !teamwin[s[2][0]-'A'][s[0][2]-'A'])
			{
				teamwin[s[0][2]-'A'][s[2][0]-'A']=teamwin[s[2][0]-'A'][s[0][2]-'A']=1;
				tans++;
			}
		}
		else if (s[0][2]==s[2][0])
		{
			if (!teamwin[s[0][2]-'A'][s[1][1]-'A'] && !teamwin[s[1][1]-'A'][s[0][2]-'A'])
			{
				teamwin[s[0][2]-'A'][s[1][1]-'A']=teamwin[s[1][1]-'A'][s[0][2]-'A']=1;
				tans++;
			}
		}
		else
		{
			if (!teamwin[s[0][2]-'A'][s[2][0]-'A'] && !teamwin[s[2][0]-'A'][s[0][2]-'A'])
			{
				teamwin[s[0][2]-'A'][s[2][0]-'A']=teamwin[s[2][0]-'A'][s[0][2]-'A']=1;
				tans++;
			}
		}
	}
	printf("%d\n",tans);
	return 0;
}
