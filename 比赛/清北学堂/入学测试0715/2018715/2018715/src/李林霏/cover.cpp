#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int n,k,ans[100005],c[100005],mx;
struct line{
	int stat,end,len;
} l[100005];

inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while (ch<'0' || ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}

inline bool cmp(line x,line y)
{
	return (x.stat==y.stat) ? x.len<y.len : x.stat<y.stat;
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n=read(); k=read();
	for (int i=1;i<=n;i++)
	{
		l[i].stat=read(); l[i].end=read();
		l[i].len=l[i].end-l[i].stat;
	}
	sort(l+1,l+n+1,cmp);
	for (int i=1;i<=n;i++)//start
	{
		queue<int> q;
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		q.push(i);
		ans[i]=l[i].len;
		c[i]=1;
		while (!q.empty())
		{
			int x=q.front(),mx=0,mxl=0; q.pop();
			if (c[x]==k) break;
			for (int j=x+1;j<=n;j++)
			{
				if (l[j].stat<l[x].end)
				{
					if (l[j].end-l[x].end>mx) mx=l[j].end-l[x].end,mxl=j;
				}
				else 
				{
					q.push(j);
					ans[j]=max(ans[j],ans[x]+l[j].len);
					c[j]=c[x]+1;
				}
			}
			if (mx) 
			{
				q.push(mxl);
				ans[mxl]=max(ans[mxl],ans[x]+mx);
				c[mxl]=c[x]+1;
			}
		}
		for (int j=1;j<=n;j++) mx=max(mx,ans[j]);
	}
	printf("%d",mx);
	return 0;
}
