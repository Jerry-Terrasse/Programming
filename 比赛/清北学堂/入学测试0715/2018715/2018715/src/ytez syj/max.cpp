#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int l,n,va,vb,ans;
struct p{
	int x;int c;
}a[100001]; 
bool cmp(p a1,p b1){
	return a1.x<b1.x;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	sort(a+1,a+n,cmp);
	int k=va-vb;
	a[0].x=0;
	for(int i=1;i<=n;i++)
	{
		ans+=k*(a[i].x-a[i-1].x)*a[i].c;
	}
	cout<<ans; 
	return 0;
}
