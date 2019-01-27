#include <iostream>
#include <cstdio>


using namespace std;

int n,k;
int l[100005],r[100005];
int len[100005];
int Max,ml,mr;
int ans;

void re()
{
	for(int i=1;i<=n;++i)
	{
		if(ml>=r[i]) continue;
		if(mr<=l[i]) continue;
		if(ml>l[i]&&r[i]>ml)
		{
			len[i]=len[i]-(r[i]-ml);
			r[i]=ml;
			continue;
		}
		if(ml<l[i]&&mr>r[i])
		{
			l[i]=r[i]=0;
			len[i]=0;
			continue;
		}
		if(l[i]>ml&&mr<r[i])
		{
			len[i]=len[i]-(mr-l[i]);
			l[i]=mr;
			continue;
		}
	}
	return ;
}

void search()
{
	for(int i=2;i<=n;++i)
	{
		Max=max(len[i-1],len[i]);
		if(Max==len[i]) {ml=l[i];mr=r[i];}
		else {ml=l[i-1];mr=r[i-1];}
	}
	return ;
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&l[i],&r[i]);
		len[i]=r[i]-l[i];
	}
	
	for(int i=1;i<=k;i++)
	{
		search();
		ans+=Max;
		for(int i=1;i<=n;i++)
		{
			if(Max==len[i])
			{
				l[i]=r[i]=len[i]=0;
			}
		}
		re();
	}
	printf("%d",ans);
	return 0;
}
