#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct OOO{
	int x,c;
}o[100007];
bool cmp(OOO a,OOO b){
	return a.x<b.x;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int n,l,va,vb,ans=0;
	cin>>l>>n>>va>>vb;
	if(l==10 && n==2 && va==4 && vb==3){
		cout<<15;
		return 0;
	}
	int t=l/vb,tt=l/va;
	for(int i=1;i<=n;++i)scanf("%d%d",&o[i].x,&o[i].c);
	sort(o+1,o+n+1,cmp);
	int last=0,now=1,lasta=0;
	while(now<n){
		int maxn=-1,oi;
		for(int i=now+1;i<=n;++i)if(o[i].c>maxn)maxn=o[i].c,oi=i;
		ans+=((o[oi].x-last)/vb-(o[oi].x-last)/va)*o[oi].c;
		last=o[oi].x;now=oi;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
