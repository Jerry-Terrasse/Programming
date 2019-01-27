#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;		
struct node
{
	long long val;
}segtree[40004000];
int  a[40004000];
int MAXX=1e9+10;
int l,n,va,vb;
long long dis[400040];
void built(int root,int left,int right)
{
	if(left==right)
	{
		segtree[root].val=a[left];
		return ;
	}
	else {
		int mid=(left+right)>>1;
		built(root<<1,left,mid);
		built(root<<1|1,mid+1,right);
		segtree[root].val=max(segtree[root<<1].val,segtree[root<<1|1].val);
	}
}
long long query(int root,int left,int right,int qleft,int qright)
{
	if(left>qright||right<qleft)
	return 0;
	if(left>=qleft&&right<=qright)
	return segtree[root].val;
	int mid=(left+right)>>1;
	return max(query(root*2,left,mid,qleft,qright),query(root*2+1,mid+1,right,qleft,qright));
}
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x; 
}  
int main()
{	

	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	l=read(),n=read(),va=read(),vb=read();
	for(int i=1;i<=n;i++)  dis[i]=read(),a[i]=read();
	built(1,1,n);
	ll Last=0,now=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		now+=1ll*dis[i]-Last;
		Last=dis[i]; 
		if(a[i]==query(1,1,n,i,n)) 
		{
			ans=ans+(ll)a[i]*now*(ll)(va-vb);
			now=0;
		}
	}
	printf("%lld",ans);
    return 0;
}
