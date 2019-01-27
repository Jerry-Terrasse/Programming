#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define For(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
int wpcnt,wgcnt,t1,t2;
unsigned short int mapp[4][4],apr[27];
bool winp[27],wing[27][27];
//先看两条对角线，然后看列、行 
void clr()
{
	memset(apr,0,sizeof apr);
}
void judge1(int x,int y)//个人获胜 
{
	//cout<<x<<' '<<y<<' '<<mapp[x][y]<<' '<<winp[mapp[x][y]]<<'\n';
	if(!winp[mapp[x][y]])
	{
			winp[mapp[x][y]]=1;
			++wpcnt;
	}
}
void judge2()//团队获胜 
{
	if(!wing[t1][t2])
	{
			wing[t1][t2]=1;
			wing[t2][t1]=1;
			++wgcnt;
	}
}
short int judge(short int x,short int y)
{
	if(apr[mapp[x][y]]==3)
	 return 1;
	if(apr[mapp[x][y]]==2)
	 return 2;
	return 0;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int temp;
	char c;
	For(i,1,3)
	 For(j,1,3)
	 {
	 	while((c=getchar())==' '||c=='\n'||c=='\r');
	 	mapp[i][j]=c-'A'+1;
	 }
	//右斜对角线
	For(i,1,3)
	{
		apr[mapp[i][i]]++;
	}
	temp=judge(1,1);
	if(temp==1)
	{
		judge1(1,1);
	}
	else if(!temp)
	 temp=judge(2,2);
	if(temp==2)
	{
		For(i,1,3)
		{
			if(apr[mapp[i][i]]==1)
			 t2=mapp[i][i];
			else
			 t1=mapp[i][i];
		}
		judge2();
	}
	//cout<<temp<<'\n';
	clr();
	//左斜对角线 
	for(int i=1;i<=3;++i)
		apr[mapp[i][4-i]]++;
	temp=judge(1,3);
	if(temp==1)
	{
		judge1(1,3);
	}
	else if(!temp)
		temp=judge(2,2);
	if(temp==2)
	{
		For(i,1,3)
		{
			if(apr[mapp[i][4-i]]==1)
			 t2=mapp[i][4-i];
			else
			 t1=mapp[i][4-i];
		}
		judge2();
	}
	//行 
	For(i,1,3)
	{
		clr();
		For(j,1,3)
		{
			apr[mapp[i][j]]++;
		}
		temp=judge(i,1);
		if(temp==1)
		{
			judge1(i,1);
		}
		else if(!temp)
		 temp=judge(i,2);
		if(temp==2)
		{
			For(j,1,3)
			{
				if(apr[mapp[i][j]]==1)
				 t2=mapp[i][j];
				else
				 t1=mapp[i][j];
			}
			judge2();
		}
	}
	//列 
	For(i,1,3)
	{
		clr();
		For(j,1,3)
		 apr[mapp[j][i]]++;
		temp=judge(1,i);
		if(temp==1)
		{
			judge1(1,i); 
		}
		else if(!temp)
		 temp=judge(2,i);
		if(temp==2)
		{
			For(j,1,3)
			{
				if(apr[mapp[j][i]]==1)
				 t2=mapp[j][i];
				else
				 t1=mapp[j][i];
			}
			judge2();
		}
	}
	cout<<wpcnt<<'\n'<<wgcnt;
	return 0;
}
