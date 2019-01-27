#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e6 + 5;
struct Data{
	int h,v;
}data[maxn];
int L,N,Va,Vb,ans,T;


bool cmp(const Data &a,const Data &b)
{
	return a.v>b.v;
}

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&L,&N,&Va,&Vb);
	int ta=L*Va,tb=L*Vb,MAXT=ta-tb;
	for(int i=1;i<=N;i++)
		scanf("%d%d",&data[i].h,&data[i].v);
	sort(data+1,data+N+1,cmp);
	for(int i=1;i<=N;i++)
	{
		int loc=data[i].h,val=data[i].v;
			int t1=loc*Va,t2=loc*Vb;
			int t=t1-t2;
			if(t-T>=0)
			{
				ans+=(t-T)*val;
				T=t;
			}
			else break;
	}
	printf("%d",ans);
	return 0;
}
