#include<algorithm>
#include<cstdio>
using namespace std;
struct OOO{
	int l,r;
}x[1000007];
bool cmp(OOO a,OOO b){return a.r<b.r;}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i].l,&x[i].r);
	sort(x+1,x+n+1,cmp);
	int ans=1,r=x[1].r;
	for(int i=2;i<=n;++i)
	if(x[i].l>=r){
		ans++;
		r=x[i].r;
	}
	printf("%d",ans);
	return 0;
}
