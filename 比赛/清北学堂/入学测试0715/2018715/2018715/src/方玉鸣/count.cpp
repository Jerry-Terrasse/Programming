#include<cstdio>
#include<cstring>
#include<iostream>

char s[5][5];
int people,team,dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1};
bool vi[30],vi2[30][30],vi3[30];

void dfs(int x,int y)
{
	int mark=0,cnt=0;
	memset(vi,0,sizeof(vi));
	for(int i=0;i<3;i++)
	{
		if(x+i>3)	break;
		if(!vi[s[x+i][y]])	mark++,vi[s[x+i][y]]=true;
		cnt++;
	}
	if(cnt==3)
	{
		int tmp_a,tmp_b;
		if(mark==1)
		{
			for(int op=0;op<29;op++)	if(vi[op]){tmp_a=op; break;}
			if(!vi2[tmp_a][tmp_a])
			{
				people++;
				vi2[tmp_a][tmp_a]=true;
			}
		}
		if(mark==2)
		{
			bool uio=false;
			for(int op=0;op<29;op++)
			{
				if(vi[op])
				{
					if(uio)
					{
						tmp_b=op;
						break;
					}
					else
					{
						tmp_a=op;
						uio=true;
					}
				}
			}
			if(!vi2[tmp_a][tmp_b])
			{
				team++;
				vi2[tmp_a][tmp_b]=vi2[tmp_b][tmp_a]=true;
			}
		}
	}
	mark=0,cnt=0;
	memset(vi,0,sizeof(vi));
	for(int i=0;i<3;i++)
	{
		if(y+i>3)	break;
		if(!vi[s[x][y+i]])	mark++,vi[s[x][y+i]]=true;
		cnt++;
	}
	if(cnt==3)
	{
		int tmp_a,tmp_b;
		if(mark==1)
		{
			for(int op=0;op<29;op++)	if(vi[op]){tmp_a=op; break;}
			if(!vi2[tmp_a][tmp_a])
			{
				people++;
				vi2[tmp_a][tmp_a]=true;
			}
		}
		if(mark==2)
		{
			bool uio=false;
			for(int op=0;op<29;op++)
			{
				if(vi[op])
				{
					if(uio)
					{
						tmp_b=op;
						break;
					}
					else
					{
						tmp_a=op;
						uio=true;
					}
				}
			}
			if(!vi2[tmp_a][tmp_b])
			{
				team++;
				vi2[tmp_a][tmp_b]=vi2[tmp_b][tmp_a]=true;
			}
		}
	}
	mark=0,cnt=0;
	memset(vi,0,sizeof(vi));
	for(int i=0;i<3;i++)
	{
		if(y+i>3||x+i>3)	break;
		if(!vi[s[x+i][y+i]])	mark++,vi[s[x+i][y+i]]=true;
		cnt++;
	}
	if(cnt==3)
	{
		int tmp_a,tmp_b;
		if(mark==1)
		{
			for(int op=0;op<29;op++)	if(vi[op]){tmp_a=op; break;}
			if(!vi2[tmp_a][tmp_a])
			{
				people++;
				vi2[tmp_a][tmp_a]=true;
			}
		}
		if(mark==2)
		{
			bool uio=false;
			for(int op=0;op<29;op++)
			{
				if(vi[op])
				{
					if(uio)
					{
						tmp_b=op;
						break;
					}
					else
					{
						tmp_a=op;
						uio=true;
					}
				}
			}
			if(!vi2[tmp_a][tmp_b])
			{
				team++;
				vi2[tmp_a][tmp_b]=vi2[tmp_b][tmp_a]=true;
			}
		}
	}
	mark=0,cnt=0;
	memset(vi,0,sizeof(vi));
	for(int i=0;i<3;i++)
	{
		if(y-i<1||x+i>3)	break;
		if(!vi[s[x+i][y-i]])	mark++,vi[s[x+i][y-i]]=true;
		cnt++;
	}
	if(cnt==3)
	{
		int tmp_a,tmp_b;
		if(mark==1)
		{
			for(int op=0;op<29;op++)	if(vi[op]){tmp_a=op; break;}
			if(!vi2[tmp_a][tmp_a])
			{
				people++;
				vi2[tmp_a][tmp_a]=true;
			}
		}
		if(mark==2)
		{
			bool uio=false;
			for(int op=0;op<29;op++)
			{
				if(vi[op])
				{
					if(uio)
					{
						tmp_b=op;
						break;
					}
					else
					{
						tmp_a=op;
						uio=true;
					}
				}
			}
			if(!vi2[tmp_a][tmp_b])
			{
				team++;
				vi2[tmp_a][tmp_b]=vi2[tmp_b][tmp_a]=true;
			}
		}
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			std::cin>>s[i][j],s[i][j]-='A';
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			dfs(i,j);
	printf("%d\n%d\n",people,team);
	return 0;
}
