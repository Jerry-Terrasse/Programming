#include<cstdio>
#include<algorithm>
using namespace std;
int zuo[100001],you[100001];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&zuo[i],&you[i]);
	}
	sort(zuo,zuo+n);
	sort(you,you+n);
	printf("%d",you[n-1]-zuo[0]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
