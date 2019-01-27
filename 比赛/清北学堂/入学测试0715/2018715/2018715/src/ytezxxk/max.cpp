#include<iostream>
#include<algorithm>
using namespace std;
int l,n,va,vb,sa,sb;
struct ting{
	int x;
	int c;
}j[100010];
int last,now,ans;
bool cmp(ting z,ting y)
{
	return z.c>y.c;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	cin>>j[i].x>>j[i].c;
	sort(j+1,j+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ans+=j[i].c*(j[i].x-last)*(va-vb);
		last=j[i].x;
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
