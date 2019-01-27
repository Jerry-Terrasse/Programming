#include<bits/stdc++.h>
using namespace std;
int l,n,a,b,cn,h;
struct jd
{
	int x,c;
}r[100005];
bool cmp(jd a,jd b)
{
	if(a.c!=b.c)return a.c>b.c;
	return a.x<b.x;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&a,&b);
	a-=b;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&r[i].x,&r[i].c);
	sort(r+1,r+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(r[i].x>h)
		{
			cn+=r[i].c*(r[i].x-h)*a;
			h=r[i].x;
		}
	}
	printf("%d",cn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

