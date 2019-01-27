#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin("cover.in");
ofstream fout("cover.out");
int n,k;
struct node
{
	int l,r;
}g[100010];
int f[100010][101][2];
int fj[100010];
bool cmp(node a,node b)
{return a.r<b.r;}
int main()
{
	ios::sync_with_stdio(false);
	fin>>n>>k;
	for(int i=1;i<=n;i++)
		fin>>g[i].l>>g[i].r;
	sort(g+1,g+n+1,cmp);
	int p1=1;
	fj[1]=1;
	for(int i=2;i<=n;i++)
	{
		while(g[p1].r<g[i].l) p1++;
		fj[i]=p1;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			f[j][i][0]=max(f[j-1][i][0],f[j-1][i][1]);
			f[j][i][1]=f[fj[j]][i-1][0]+g[j].r-g[j].l;
			for(int p=fj[j];p<j;p++)
				f[j][i][1]=max(f[j][i][1],f[p][i-1][1]+g[j].r-g[p].r);
		}
	fout<<max(f[n][k][1],f[n][k][0]);
	return 0;
}
