#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<complex>
#include<set>
#define R register
#pragma GCC optimize(2)

using namespace std;
set<char> s1;
//set<string> s2;
char s[4][4];
int xx[100][100],maxx=-100;
//map<char,int> xx;
int ans1,ans2,cnt;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(R int i=1;i<=3;i++)
	  for(R int j=1;j<=3;j++)
	    cin>>s[i][j];
	for(R int i=1;i<=3;i++)
	{
		char now=s[i][1];cnt=0;maxx=-100;
		for(R int j=1;j<=3;j++)
		  if(s[i][j]==now)
			cnt++;
		maxx=max(maxx,cnt);
		
		now=s[i][2];cnt=0;
		for(R int j=1;j<=3;j++)
		  if(s[i][j]==now)
			cnt++;
		maxx=max(maxx,cnt);
		
		now=s[i][3];cnt=0;
		for(R int j=1;j<=3;j++)
		  if(s[i][j]==now)
			cnt++;
		maxx=max(maxx,cnt);
		
		if(maxx==3 and !s1.count(now))
		  ans1++,s1.insert(now);
		if(maxx==2)
		{
			if(s[i][1]==s[i][2])
			{
				if(xx[s[i][1]][s[i][3]]==0 or xx[s[i][3]][s[i][1]]==0)
				  xx[s[i][1]][s[i][3]]=1,xx[s[i][3]][s[i][1]]=1,xx[s[i][2]][s[i][3]]=1,xx[s[i][3]][s[i][2]]=1,ans2++;
			}  
			else if(s[i][1]==s[i][3])
			{
				if(xx[s[i][1]][s[i][2]]==0 or xx[s[i][2]][s[i][1]]==0)
				  xx[s[i][1]][s[i][2]]=1,xx[s[i][2]][s[i][1]]=1,xx[s[i][3]][s[i][2]]=1,xx[s[i][2]][s[i][3]]=1,ans2++;
			}
			else if(s[i][2]==s[i][3])
			{
				if(xx[s[i][2]][s[i][1]]==0 or xx[s[i][1]][s[i][2]]==0)
				  xx[s[i][2]][s[i][1]]=1,xx[s[i][1]][s[i][2]]=1,xx[s[i][3]][s[i][1]]=1,xx[s[i][1]][s[i][3]]=1,ans2++;
			}
		}
//		else if(maxx==2)
//		{
//			if(s[1][i]==s[2][i])
//			  if(xx[s[1][i]][s[3][i]]==0 or xx[s[3][i]][s[1][i]]==0)
//			    xx[s[1][i]][s[3][i]]=1,xx[s[3][i]][s[1][i]]=1,ans2++;
//			else if(s[1][i]==s[3][i])
//			  if(xx[s[1][i]][s[2][i]]==0 or xx[s[2][i]][s[1][i]]==0)
//			    xx[s[1][i]][s[2][i]]=1,xx[s[2][i]][s[1][i]]=1,ans2++;
//			else if(s[2][i]==s[3][i])
//			  if(xx[s[2][i]][s[1][i]]==0 or xx[s[1][i]][s[2][i]]==0)
//			    xx[s[2][i]][s[2][i]]=1,xx[s[1][i]][s[2][i]]=1,ans2++;
//		}
	}
	for(R int i=1;i<=3;i++)
	{
		char now=s[1][i];cnt=0;maxx=-100;
		for(R int j=1;j<=3;j++)
		  if(s[j][i]==now)
			cnt++;
		maxx=max(maxx,cnt);
		
		now=s[2][i];cnt=0;
		for(R int j=1;j<=3;j++)
		  if(s[j][i]==now)
			cnt++;
		maxx=max(maxx,cnt);
		
		now=s[3][i];cnt=0;
		for(R int j=1;j<=3;j++)
		  if(s[j][i]==now)
			cnt++;
		maxx=max(maxx,cnt);
		
		if(maxx==3 and !s1.count(now))
		  ans1++,s1.insert(now);
		else if(maxx==2)
		{
			if(s[1][i]==s[2][i])
			{
				if(xx[s[1][i]][s[3][i]]==0 or xx[s[3][i]][s[1][i]]==0)
				  xx[s[1][i]][s[3][i]]=1,xx[s[3][i]][s[1][i]]=1,xx[s[2][i]][s[3][i]]=1,xx[s[3][i]][s[2][i]]=1,ans2++;
			}
			else if(s[1][i]==s[3][i])
			{
				if(xx[s[1][i]][s[2][i]]==0 or xx[s[2][i]][s[1][i]]==0)
				  xx[s[1][i]][s[2][i]]=1,xx[s[2][i]][s[1][i]]=1,xx[s[3][i]][s[2][i]]=1,xx[s[2][i]][s[3][i]]=1,ans2++;
			}
			else if(s[2][i]==s[3][i])
			{
				if(xx[s[2][i]][s[1][i]]==0 or xx[s[1][i]][s[2][i]]==0)
				  xx[s[2][i]][s[1][i]]=1,xx[s[1][i]][s[2][i]]=1,xx[s[3][i]][s[1][i]]=1,xx[s[1][i]][s[3][i]]=1,ans2++;
			}
		}
	}
	if((s[1][1]==s[2][2] and s[2][2]==s[3][3] and !s1.count(s[1][1])) or (s[3][1]==s[2][2] and s[2][2]==s[1][3] and !s1.count(s[2][2])))
	  ans1++;
	if((s[1][1]==s[2][2] and s[1][1]!=s[3][3] and xx[s[1][1]][s[3][3]]==0 and xx[s[3][3]][s[1][1]]==0) or (s[1][1]==s[3][3] and s[1][1]!=s[2][2] and xx[s[1][1]][s[2][2]]==0 and xx[s[2][2]][s[1][1]]==0) or (s[2][2]==s[3][3] and s[1][1]!=s[3][3] and xx[s[2][2]][s[3][3]]==0 and xx[s[3][3]][s[2][2]]==0) or (s[1][3]==s[2][2] and s[1][3]!=s[3][1] and xx[s[1][3]][s[3][1]]==0 and xx[s[3][1]][s[1][3]]==0) or (s[1][3]==s[3][1] and s[1][3]!=s[2][2] and xx[s[1][3]][s[2][2]]==0 and xx[s[2][2]][s[1][3]]==0) or (s[2][2]==s[3][1] and s[2][2]!=s[1][3] and xx[s[2][2]][s[1][3]]==0 and xx[s[1][3]][s[2][2]]==0))
	  ans2++;
	cout<<ans1;puts("");cout<<ans2;
	fclose(stdin);fclose(stdout);
	return 0;
}
