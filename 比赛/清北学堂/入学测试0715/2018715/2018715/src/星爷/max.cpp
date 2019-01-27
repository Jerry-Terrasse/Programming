#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm> 
#define INF -0x7f7f7f7f
#define lson root<<1,left,mid
#define rson root<<1|1,mid+1,right
#define Root int root,int left,int right
#define ll long long 
const int MAXN=1e6;
using namespace std;
struct Tree
{
	int val;
}segTree[MAXN*4];
int l,n,va,vb;
int dis[MAXN],val[MAXN]; 
void Built(Root)
{
	if(left==right)
	{
		segTree[root].val=val[left];
		return ;	
	}	
	int mid=(left+right)>>1; 
	Built(lson),Built(rson);
	segTree[root].val=max(segTree[root<<1].val,segTree[root<<1|1].val); 
}
int query(Root,int qleft,int qright)
{
	if(left>qright || right<qleft) return 0;
	if(left>=qleft && right<=qright) return segTree[root].val;
	int mid=(left+right)>>1;
	int a=query(lson,qleft,qright);
	int b=query(rson,qleft,qright);
	return max(a,b);	
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
	freopen("max.out","W",stdout); 
	l=read(),n=read(),va=read(),vb=read();
	for(int i=1;i<=n;i++)  dis[i]=read(),val[i]=read();
	Built(1,1,n);
	ll Last=0,now=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		now+=1ll*dis[i]-Last;
		Last=1ll*dis[i]; 
		if(val[i]==query(1,1,n,i,n)) 
		{
			ans=ans+(ll)val[i]*now*(ll)(va-vb);
			now=0;
		}
	}
	printf("%lld",ans);
	return 0;
}
