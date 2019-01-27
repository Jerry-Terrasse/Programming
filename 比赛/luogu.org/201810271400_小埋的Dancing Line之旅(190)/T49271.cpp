#include<cstdio>
#define MAXN 1010
using namespace std;
const char dx[2]={0,1};
const char dy[2]={1,0};
char a[MAXN][MAXN];
int n=0,m=0,ans=-1;
int main()
{
	int i=0,j=0,u=0,v=0,pre=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)
	{
		scanf("%s",a[i]);
	}
	for(u=0,v=0,pre=-1;u!=n-1||v!=m-1;)
	{
		if(a[u+dx[0]][v+dy[0]]=='1')
		{
			u+=dx[0];v+=dy[0];
			ans+=pre!=0;
			pre=0;
		}
		else
		{
			u+=dx[1];v+=dy[1];
			ans+=pre!=1;
			pre=1;
		}
	}
	if(ans==-1)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n",ans);
	}
	return 0;
}
