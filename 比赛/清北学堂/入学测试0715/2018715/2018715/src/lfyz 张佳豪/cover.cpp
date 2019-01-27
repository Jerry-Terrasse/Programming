#include<bits/stdc++.h>
#include <bitset>
using std::bitset;
using namespace std;
int n,k,cn;
bitset<32> hh;
struct xd
{
	int p,q;
}r[100005];
bool cmp(xd a,xd b)
{
	return a.q-a.p>b.q-b.p;
}
void dfs(int l=1,int yx=0,int cc=0)
{
	if(yx==k)
	{
		cn=max(cn,cc);
		return;
	}
	if(n-l<k-yx)return;
	dfs(l+1,yx,cc);
	int IN=0;
	bitset<32> h;
	h=hh;
	for(int i=r[l].p;i<r[l].q;i++)
		if(!hh[i])
		{
			IN++;
			hh[i]=1;
		}
	dfs(l+1,yx+1,cc+IN);
	hh=h;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&r[i].p,&r[i].q);
		cn=max(cn,r[i].q-r[i].p);
	}
	if(k==1)
	{
		printf("%d",cn);
		return 0;
	}
	else
		dfs();
	printf("%d",cn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
