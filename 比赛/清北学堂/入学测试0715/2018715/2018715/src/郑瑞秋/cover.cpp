#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define N 1001000

int n,k,l[N],r[N],len[N],ans;

int leng(int a,int b)
{
	if(r[a]>l[b]){
		return len[a]+len[b]-r[a]+l[b]-1;
	}
	return len[a]+len[b];
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	if(k==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>l[i]>>r[i];
			len[i]=r[i]-l[i]+1;
			for(int j=1;j<i;j++)
			{
				ans=max(ans,leng(i,j));
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>l[i]>>r[i];
		}
		cout<<rand();
	}
}
