#include<bits/stdc++.h>
using namespace std;
char c[4][4];
int ans1,ans2;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	 for(int j=1;j<=3;j++)
	 cin>>c[i][j];
	for(int i=1;i<=3;i++)
	{
		if(c[i][1]==c[i][2]||c[i][1]==c[i][3]||c[i][2]==c[i][3])
		{
			if(c[i][1]==c[i][2]&&c[i][1]==c[i][3])
			ans1++;
			else ans2++;
	    }
		if(c[1][i]==c[2][i]||c[1][i]==c[3][i]||c[2][i]==c[3][i]) 
		{
			if(c[1][i]==c[2][i]&&c[1][i]==c[i][3])
			ans1++;
			else ans2++;
		}
	}
	if(c[1][1]==c[2][2]||c[1][1]==c[3][3]||c[2][2]==c[3][3])
	{
	   if(c[1][1]==c[2][2]&&c[1][1]==c[3][3])
	   ans1++;
	   else ans2++;	
	}
	if(c[3][1]==c[2][2]||c[3][1]==c[1][3]||c[2][2]==c[1][3])
	{
		if(c[3][1]==c[2][2]&&c[3][1]==c[1][3])
		ans1++;
		else ans2++;
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
