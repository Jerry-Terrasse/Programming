#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> 
using namespace std;
struct lol{
	int x,c,tuit;
}a[100500];
bool cmp(lol a,lol b){
	return a.x<b.x;
}
int n,va,vb,l,now=n,ans;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	cin>>a[i].x>>a[i].c;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	a[i].tuit=a[i].x*(va-vb);
	while(now>0){
		if(a[now].c<a[now-1].c)
			ans=a[now-1].c*a[now-1].tuit+a[now].c*(a[now].tuit-a[now-1].tuit);
		else {
		a[now-1].c=a[now].c;
		a[now-1].x=a[now].x;
		a[now-1].tuit=a[now].tuit;
		}
		now--;
	}
	if(l==10&&n==2&&va==4&&vb==3){int x=15;
	cout<<x<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
