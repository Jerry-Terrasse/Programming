#include<iostream>

using namespace std;

long long n,m,a[100010],t[400010],ans[400010];

inline long long ls(long long x)
{
	return x<<1;
}//左儿子 

inline long long rs(int x)
{
	return x<<1|1;
}//右儿子 

void push_up_sum(int x)
{
	t[x]=t[ls(x)]+t[rs(x)];
}

void push_up_min(int x)
{
	t[x]=min(t[ls(x)],t[rs(x)]);
}
inline void push_up(int x)
{
	ans[x]=ans[ls(x)]+ans[rs(x)];
}

void build(long long x,long long l,long long r)
{
	t[x]=0;
	if(l==r)
	{
		ans[x]=a[l];
		return ;
	}
	long long mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	push_up(x);
}

//懒标记如下；
void f(long long l,long long r,long long x,long long k)
{
	t[x]=t[x]+k;
	ans[x]=ans[x]+k*(r-l+1);
 } //记录当前的代表区间
 
 void push_down(long long x,long long l,long long r)
 {
 	long long mid=(l+r)>>1;
 	f(ls(x),l,mid,t[x]);
 	f(rs(x),mid+1,r,t[x]);
 	t[x]=0;
}

void update(long long nl,long long nr,long long l,long long r,long long x,long long k)
{
	if(nl<=l&&nr>=r)
	{
		ans[x]+=k*(r-l+1);
		t[x]+=k;
		return ;
	}
	if (t[x]) push_down(x,l,r);
	long long mid=(l+r)>>1;
	if(nl<=mid)
	{
		update(nl,nr,l,mid,ls(x),k);
		
	}
	if(nr>mid)
	{
		update(nl,nr,mid+1,r,rs(x),k);
	}
	push_up(x);
 } 
 
 long long query(long long a,long long b,long long l,long long r,long long x)
 {
 	long long res=0;
 	if(a<=l&&r<=b)
 	{
 		return ans[x];
	}
	long long mid=(l+r)>>1;
	if (t[x])push_down(x,l,r);
	if(a<=mid)
	{
		res+=query(a,b,l,mid,ls(x));
	}
	if(b>mid)
	{
		res+=query(a,b,mid+1,r,rs(x));
	}
	return res;
 }
int main()
{
	long long b,c,d,e,ff,g;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);
	while(m--)
	{
		cin>>g;
		switch(g)
		{
			case 1:
			{
				cin>>b>>c>>d;
				update(b,c,1,n,1,d);
				break;
			 }
			 case 2:
			 {
			 	cin>>e>>ff;
			 	cout<<query(e,ff,1,n,1)<<endl;
			 	break;
			 }
		}
	}
	return 0;
 } 
