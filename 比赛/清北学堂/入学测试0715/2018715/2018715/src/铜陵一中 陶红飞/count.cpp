#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
char a;
int ansp,anst,s[4][4],c;
bool f=0,t[328][328],p[328];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<4;++i)
	for(int j=1;j<4;++j)
	{
		cin>>a;
		s[i][j]=a-'A';
	}
	for(int i=1;i<4;++i)
	{
	    c=s[i][1];
	    f=1;
		for(int j=2;j<4;++j)
		{
			if(s[i][j]!=c)
			{
			    f=0;
				if(s[i][2]==s[i][3]&&t[s[i][1]][s[i][3]]==0)
				{
					anst++;
					t[s[i][1]][s[i][3]]=1;
					t[s[i][3]][s[i][1]]=1;
				}
			    if(s[i][1]==s[i][3]&&t[s[i][2]][s[i][3]]==0)
				{
					anst++;
					t[s[i][2]][s[i][3]]=1;
					t[s[i][3]][s[i][2]]=1;
				}
				if(s[i][2]==s[i][1]&&t[s[i][3]][s[i][1]]==0)
				{
					anst++;
					t[s[i][3]][s[i][1]]=1;
					t[s[i][1]][s[i][3]]=1;
				}
			}
		}
		if(f&&p[s[i][1]]==0)
		{
			ansp++;
			p[s[i][1]]=1;
		}
		
		c=s[1][i];
	    f=1;
		for(int j=2;j<4;++j)
		{
			if(s[j][i]!=c)
			{
			    f=0;
				if(s[2][i]==s[3][i]&&t[s[1][i]][s[3][i]]==0)
				{
					anst++;
					t[s[1][i]][s[3][i]]=1;
					t[s[3][i]][s[1][i]]=1;
				}	
				if(s[1][i]==s[3][i]&&t[s[2][i]][s[3][i]]==0)
				{
					anst++;
					t[s[2][i]][s[3][i]]=1;
					t[s[3][i]][s[2][i]]=1;
				}	
				if(s[2][i]==s[1][i]&&t[s[3][i]][s[1][i]]==0)
				{
					anst++;
					t[s[3][i]][s[1][i]]=1;
					t[s[1][i]][s[3][i]]=1;
				}
			}
		}
		if(f&&p[s[1][i]]==0)
		{
			ansp++;
			p[s[1][i]]=1;
		}
	}
	c=s[2][2];
	if(s[1][1]==c&&s[3][3]==c&&p[c]==0)
	{
		ansp++;
		p[s[2][2]]=1;
	}
	else if(s[1][1]==s[3][3]&&t[c][s[3][3]]==0)
	{
		anst++;
		t[c][s[3][3]]=1;
		t[s[3][3]][c]=1;
	}
	else if(s[2][2]==s[3][3]&&t[c][s[1][1]]==0)
	{
		anst++;
		t[c][s[1][1]]=1;
		t[s[1][1]][c]=1;
	}
	else if(s[1][1]==s[2][2]&&t[s[1][1]][s[3][3]]==0)
	{
		anst++;
		t[s[1][1]][s[3][3]]=1;
		t[s[3][3]][s[1][1]]=1;
	}
	
	if(s[1][3]==c&&s[3][1]==c&&p[c]==0)
	{
		ansp++;
		p[s[2][2]]=1;
	}
	else if(s[1][3]==s[2][2]&&t[s[3][1]][s[2][2]]==0)
	{
		anst++;
		t[s[3][1]][s[2][2]]=1;
		t[s[2][2]][s[3][1]]=1;
	}
	else if(s[1][3]==s[3][1]&&t[c][s[3][1]]==0)
	{
		anst++;
		t[c][s[3][1]]=1;
		t[s[3][1]][c]=1;
	}
	else if(s[2][2]==s[3][1]&&t[s[2][2]][s[1][3]]==0)
	{
		anst++;
		t[s[2][2]][s[1][3]]=1;
		t[s[1][3]][s[2][2]]=1;
	}
	cout<<ansp<<endl<<anst;
	return 0;
}
