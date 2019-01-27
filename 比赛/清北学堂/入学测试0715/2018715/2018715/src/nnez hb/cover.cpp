#include<bits/stdc++.h>
using namespace std;

int l[100010],r[100010];
int n,k;
int ans=0,now=0,now1=0;
int mar[100];

void dfs(int num)
{
	for(int i=1;i<=n;i++)
	{
		mar[num]=i;
		int flag=0;
		for(int j=1;j<num;j++)
		{
			if(l[i]>l[mar[j]]&&l[i]<r[mar[j]])
			{
				
				now1=r[i]-r[mar[j]];
				now+=now1;
				flag=1;
				break;
			}
			if(r[i]>l[mar[j]]&&r[i]<r[mar[j]])
			{
				now1=l[mar[j]]-l[i];
				now+=now1;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			now1=r[i]-l[i];
			now+=now1;
		}
		if(num==k)
		{
			if(now>ans)ans=now;
		}
		else
		{
			dfs(num+1);
		}
		now-=now1;
	}
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&l[i],&r[i]);
	dfs(1);
	cout<<ans;
	return 0;
	//Õæ²»»á 
}
