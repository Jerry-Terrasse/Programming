#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#define MAXN 100005
#define ll long long
#define INF 2147483647
#define MOD 1000000007
#define free(s) freopen("s.txt","r",stdin);
#define lowbit(x) ((x&(-x))) 
#define debug(x) cout<<x<<endl;
using namespace std;
const int maxn=100005;
int n,k,p[maxn],dp[maxn][105],lm=maxn,rm=0,maxx=-1,cnt=0,m,ans=0;
struct node{
  int l,r;
}a[maxn],b[maxn];
struct node2{
  int node,val;
};
deque<node2>q[maxn];
bool cmp(node t1,node t2)
{
	return t1.l==t2.l?t1.r>t2.r:t1.l<t2.l;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
  	scanf("%d%d",&n,&k);
  	m=n;
  	b[0].l=0;b[0].r=0;
 	for(int i=1;i<=n;i++)
 	{
 	 	scanf("%d%d",&a[i].l,&a[i].r);
		lm=min(lm,a[i].l);
		rm=max(rm,a[i].r);	
	}
  	if(k>=n) 
 	{
    	printf("%d",rm-lm+1);
    	return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
      	if(a[i].r>maxx)
	 	 	b[++cnt]=a[i];
      	else 
	  		m--;
    	maxx=max(maxx,a[i].r);
	}//删除被包含区间
	if(m<=k)
	{
    	printf("%d",rm-lm+1);
    	return 0;		
	}
	k=n-k;
	for(int i=1;i<=n;i++)
    	for(int j=0;j<i;j++)
   		{
     		int now=i-j-1;
     		while((!q[now].empty())&&(b[q[now].front().node].r<b[i].l))
     		{
      		    p[now]=max(p[now],q[now].front().val+b[q[now].front().node].r);
      		    q[now].pop_front();
     		}
     	dp[i][j]=max(dp[i][j],p[now]+b[i].r-b[i].l);
     	if(!q[now].empty())
    		dp[i][j]=max(dp[i][j],q[now].front().val+b[i].r);
    	while((!q[i-j].empty())&&(q[i-j].back().val<dp[i][j]-b[i].r))
    		q[i-j].pop_back();
    	q[i-j].push_back({i,dp[i][j]-b[i].r});
   		}
  for(int i=1;i<=n;i++)
 	 for(int j=0;j<i;j++)
  		if(j+n-i==k)
  			ans=max(ans,dp[i][j]);
  printf("%d\n",ans);
  return 0;
}
