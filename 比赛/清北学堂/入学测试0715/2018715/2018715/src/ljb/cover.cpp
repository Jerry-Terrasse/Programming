#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int n,k,last,p,longest=-1,len[100005],q,ans;
struct line
{
	int l,r;
};
line s[100005];
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].l,&s[i].r);
		len[i]=s[i].r-s[i].l+1;
		if(len[i]>longest)
		{
			longest=len[i];
			q=i;
		}
	}
	p=0;
	while(p<k)
	{
		ans=ans+longest;
		p++;
		for(i=1;i<=n;i++)
		{
			if(s[i].l<s[q].l&&s[i].r>s[q].l)
			{
				len[i]=len[i]-(s[i].r-s[q].l+1);
				s[i].r=s[q].l;
			}
			else if(s[i].l>s[q].l&&s[i].r<s[q].r)
			{
				len[i]=0;
				s[i].l=s[q].l;
				s[i].r=s[q].r;
			}
			else if(s[i].l<s[q].r&&s[q].r<s[i].r)
			{
				len[i]=len[i]-(s[q].r-s[i].l+1);
				s[i].l=s[q].r;
			}
		}
		len[q]=0;
		s[q].r=s[q].l;
		longest=-1;
		for(i=1;i<=n;i++)
		{
			if(len[i]>longest)
			{
				longest=len[i];
				q=i;
			}
		}
		if(longest==0)break;
	}
	printf("%d",ans);
	return 0;
}
