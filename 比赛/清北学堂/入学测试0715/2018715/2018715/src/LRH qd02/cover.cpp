#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],b[100010];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int n,m,i,j,k,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	sort(a+1,a+1+n);
	x=a[1];
	sort(b+1,b+1+n);
	y=b[n];
	printf("%d\n",y-x);
	fclose(stdin);fclose(stdout);
	return 0;
}

