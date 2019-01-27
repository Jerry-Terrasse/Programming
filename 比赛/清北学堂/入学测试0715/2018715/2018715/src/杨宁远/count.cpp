#include<cstdio>
#include<algorithm>
#include<cstring>
int c[4][4]={0};
int win[30]={0};
int a,i,j,s;
char t;
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	s=0;
	for(i=1;i<=3;i++)
	{		
	for(j=1;j<=3;j++)
	{
		scanf("%c",&t);
		c[i][j]=int(t-'A')+1;
	}
	scanf("%c",&t);	
	}
	for(i=1;i<=3;i++)
	{
		if (c[i][1]==c[i][2]&&c[i][2]==c[i][3]&&win[c[i][1]]==0)
		{s++;win[c[i][1]]++;}
		if (c[1][i]==c[2][i]&&c[2][i]==c[3][i]&&win[c[1][i]]==0)
		{s++;win[c[1][i]]++;}
	}
	if (c[1][1]==c[2][2]&&c[2][2]==c[3][3]&&win[c[2][2]]==0){s++;win[c[1][1]]++;}
	if (c[3][1]==c[2][2]&&c[2][2]==c[1][3]&&win[c[2][2]]==0){s++;win[c[3][1]]++;}
	printf("%d\n",s);
	s=0;
	memset(win,0,sizeof(win));
	for(i=1;i<=3;i++)
	{
		if(c[i][1]==c[i][2]&&c[i][1]!=c[i][3])
		if(win[c[i][1]]==0&&win[c[i][3]]==0){s++;win[c[i][1]]++;win[c[i][3]]++;}
		if(c[i][1]==c[i][3]&&c[i][1]!=c[i][2])
		if(win[c[i][1]]==0&&win[c[i][2]]==0){s++;win[c[i][1]]++;win[c[i][2]]++;}
		if(c[i][3]==c[i][2]&&c[i][1]!=c[i][3])
		if(win[c[i][2]]==0&&win[c[i][1]]==0){s++;win[c[i][2]]++;win[c[i][1]]++;}
		if(c[1][i]==c[2][i]&&c[1][i]!=c[3][i])
		if(win[c[1][i]]==0&&win[c[3][i]]==0){s++;win[c[1][i]]++;win[c[3][i]]++;}
		if(c[1][i]==c[3][i]&&c[1][i]!=c[2][i])
		if(win[c[1][i]]==0&&win[c[2][i]]==0){s++;win[c[1][i]]++;win[c[2][i]]++;}
		if(c[2][i]==c[3][i]&&c[1][i]!=c[2][i])
		if(win[c[2][i]]==0&&win[c[1][i]]==0){s++;win[c[2][i]]++;win[c[1][i]]++;}
	}
	if (c[1][1]==c[2][2]&&c[2][2]!=c[3][3]&&win[c[1][1]]==0&&win[c[3][3]]==0){s++;win[c[1][1]]++;win[c[3][3]]++;}
    if (c[1][1]==c[3][3]&&c[2][2]!=c[3][3]&&win[c[1][1]]==0&&win[c[2][2]]==0){s++;win[c[1][1]]++;win[c[2][2]]++;}	
    if (c[1][1]!=c[3][3]&&c[2][2]==c[3][3]&&win[c[2][2]]==0&&win[c[1][1]]==0){s++;win[c[2][2]]++;win[c[1][1]]++;}	
	if (c[3][1]==c[2][2]&&c[2][2]!=c[1][3]&&win[c[1][1]]==0&&win[c[1][3]]==0){s++;win[c[2][2]]++;win[c[1][3]]++;}
    if (c[3][1]==c[1][3]&&c[2][2]!=c[1][3]&&win[c[1][1]]==0&&win[c[2][2]]==0){s++;win[c[1][3]]++;win[c[2][2]]++;}	
    if (c[1][3]!=c[3][1]&&c[2][2]==c[1][3]&&win[c[2][2]]==0&&win[c[3][1]]==0){s++;win[c[2][2]]++;win[c[3][1]]++;}	    
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
