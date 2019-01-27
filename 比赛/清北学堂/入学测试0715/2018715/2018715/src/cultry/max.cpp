#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin("max.in");
ofstream fout("max.out");
int l,n,va,vb,ans=0;
struct node
{
	int c,x;
}p[100010];
bool cmp(node x,node y)
{
	if(x.c==y.c) return x.x>y.x;
	return x.c>y.c;
}
int main()
{
	ios::sync_with_stdio(false);
	fin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
		fin>>p[i].x>>p[i].c;
	sort(p+1,p+n+1,cmp);
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].x>last)
		{
			ans=ans+(va-vb)*(p[i].x-last)*p[i].c;
			last=p[i].x;
		}
	}
	fout<<ans;
	return 0;
}
