
#include<cstdio>
#include<iostream>
using namespace std;
int Va,Vb,L,n,ans;
int x[100005],c[100005];
int cmax[100005];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&L,&n,&Va,&Vb);
	for(int i=1;i<=n;i++)
	 scanf("%d%d",&x[i],&c[i]);
	 cmax[n]=c[n];
	for(int i=n-1;i>=1;i--)
	 cmax[i]=max(cmax[i+1],c[i]);
	for(int i=1;i<=n;i++)
	 {
	 	int h=x[i]-x[i-1];
	 	int t=(h*Va)-(h*Vb);
	 	ans+=t*cmax[i];
	 }
	 printf("%d\n",ans);
	 return 0;
}

