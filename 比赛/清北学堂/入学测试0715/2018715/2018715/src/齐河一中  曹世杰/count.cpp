#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#define MAXN 100005
#define LL long long
#define INF 2147483647
#define MOD 1000000007
#define free(s) freopen("s.txt","r",stdin);
#define lowbit(x) ((x&(-x))) 
#define debug(x) cout<<x<<endl;
using namespace std;
const int L=50005;
int w[4][4],cnt[4],ans1=0,ans2=0,t[30],s[30];
int update(char ch)
{
	return ch-64;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			char c;
			cin>>c;
			w[i][j]=update(c);
		}
	for(int i=1;i<=3;i++)
	{
		int tong[30];
		memset(tong,0,sizeof(tong));
		for(int j=1;j<=3;j++)
			tong[w[i][j]]++;
		for(int j=1;j<=26;j++)
		{
			if(tong[j]==2)
				ans2++;
			if(tong[j]==3)
				ans1++;
		}
	}
	for(int i=1;i<=3;i++)
	{
		int tong[30];
		memset(tong,0,sizeof(tong));
		for(int j=1;j<=3;j++)
			tong[w[j][i]]++;
		for(int j=1;j<=26;j++)
		{
			if(tong[j]==2)
				ans2++;
			if(tong[j]==3)
				ans1++;
		}
	}
	for(int i=1;i<=3;i++)
	{
		t[w[i][i]]++;
		s[w[i][4-i]]++;	
	}
	for(int i=1;i<=26;i++)
	{
		if(t[i]==3)
			ans1++;
		if(t[i]==2)
			ans2++;
		if(s[i]==3)
			ans1++;
		if(s[i]==2)
			ans2++;
	}
	printf("%d\n%d",ans1,ans2);	
	return 0;
}
