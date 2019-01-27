#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l,n,va,vb;
struct xx
{
	int x;
	int c;
}xc[100010];
bool cmp(xx x1,xx x2)
{
	return x1.c>x2.c;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int hbb;
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	{
		cin>>xc[i].x>>xc[i].c;
	}
	int m=1,dqhb=0,answer=0;
	sort(xc+1,xc+n+1,cmp);
	while(m!=n)
	{
		for(int i=m;i<=n;i++)
		{
			if(xc[i].x>dqhb)
			{
				m=i;
				break;
			}
		}
		answer=answer+((xc[m].x-dqhb)*va-(xc[m].x-dqhb)*vb)*xc[m].c;
		dqhb=xc[m].x;
	}
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
