#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
char a[5][5];
int used[28];
int d[27];
int r[27];
int panren()
{
	int ans=0,tem1,temp1,tem2,temp2,tem3,temp3;
	stack <char> s,b;
	for(int i=1;i<=3;i++)	//ºáÐÐ 
	{
		for(int j=1;j<=3;j++)
		{
			s.push(a[i][j]);
			b.push(a[j][i]);
		}
		tem1=s.top();temp1=b.top();
		s.pop();b.pop();
		tem2=s.top();temp2=b.top();
		s.pop();b.pop();
		tem3=s.top();temp3=b.top();
		if(tem1==tem2&&tem2==tem3)
		{
			r[tem1-'A']++;
			if(r[tem1-'A']==1)
				ans++;
		}
		if(temp1==temp2&&temp2==temp3)
		{
			r[temp1-'A']++;
			if(r[temp1-'A']==1)
				ans++;
		}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])
	{
		r[a[1][1]-'A']++;
		if(r[a[1][1]-'A']==1)
			ans++;
	}
	if(a[1][3]==a[2][2]&&a[2][2]==a[3][1])
	{
		r[a[1][1]-'A']++;
		if(r[a[1][1]-'A']==1)
			ans++;
	}
	return ans;	
}
int pandui()
{
	int ans=0;
	for(int i=1;i<=3;i++)
	{
		int faild=0,maybewin=0;
		memset(used,0,sizeof(used));
		for(int j=1;j<=3;j++)
		{
			used[a[i][j]-'A']++;
		}
		for(int k=1;k<=26;k++)
		{
			if(used[k]==3)
				faild=1;
			if(used[k]==2)
				maybewin=1;
		}
		if(!faild&&maybewin)
			ans++;
	}
	for(int i=1;i<=3;i++)
	{
		int faild=0,maybewin=0;
		memset(used,0,sizeof(used));
		for(int j=1;j<=3;j++)
		{
			used[a[j][i]-'A']++;
		}
		for(int k=1;k<=26;k++)
		{
			if(used[k]==3)
				faild=1;
			if(used[k]==2)
				maybewin=1;
		}
		if(!faild&&maybewin)
			ans++;
	}
	if((a[1][1]==a[2][2]&&a[2][2]!=a[3][3])||(a[1][1]==a[3][3]&&a[1][1]!=a[2][2]))
		ans++;
	if((a[1][3]==a[2][2]&&a[2][2]!=a[3][1])||(a[1][3]==a[3][1]&&a[1][3]!=a[2][2]))
		ans++;
	return ans;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<panren()<<endl;
	cout<<pandui()<<endl;
	return 0;
}
