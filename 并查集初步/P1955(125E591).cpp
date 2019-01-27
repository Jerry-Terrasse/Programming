#include <bits/stdc++.h>
#include<cstring>
using namespace std;
const int maxn=1000010;
long long t[maxn];
int bcj[maxn];
int n;
struct data
{
    long long l,r; 
    int tag;
}asks[1000010];
int find_f(int x)
{
    return bcj[x]=bcj[x]==x?x:find_f(bcj[x]);
}
void merge_f(int x,int y)
{
    int xx=find_f(x);
    int yy=find_f(y);
    bcj[yy]=xx;
}
int cmp(data a,data b)
{
    return a.tag>b.tag;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    memset(t,0,sizeof(t));int tag=0;
    scanf("%d",&n);int tot=0;
   
    
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%d",&asks[i].l,&asks[i].r,&asks[i].tag);
       t[++tot]=asks[i].l;
       t[++tot]=asks[i].r;
    }
    sort(t+1,t+tot+1);//将t数组排序
    int m=unique(t+1,t+tot+1)-t-1;//去重,m是a数组不重复元素个数
    for(int i=1;i<=n;i++)
    {
    	asks[i].l=lower_bound(t+1,t+1+m,asks[i].l)-t;
    	asks[i].r=lower_bound(t+1,t+1+m,asks[i].r)-t;
    }
    for(int i=1;i<=m;i++)bcj[i]=i;
    sort(asks+1,asks+n+1,cmp);
   	 for(int i=1;i<=n;i++)
    {
    	if(asks[i].tag==0)
    	{
    		if(find_f(asks[i].l)==find_f(asks[i].r))
    		{
    			cout<<"NO"<<endl;tag=1;
    			break;
    		}
    		else continue;
    	}
    	if(asks[i].tag==1)
    	{
    		merge_f(asks[i].l,asks[i].r);
    	}
    }
    
    if(!tag)cout<<"YES"<<endl;
    }
    return 0;
}
