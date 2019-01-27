#include<bits/stdc++.h>
using namespace std;
int dep,n,va,vb;
int maxc,lx,px;
long long ans;
struct node{
	int d,c;
}a[100050];
bool com(node x,node y){
	return x.d<y.d;
}
int main(){
	
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	
	scanf("%d%d%d%d",&dep,&n,&va,&vb);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].d,&a[i].c);
	sort(a+1,a+n+1,com);
	while(px<n){                                            //px为当前所在景点编号 
		maxc=0;lx=px;
		for(int i=px+1;i<=n;i++){
			if(a[i].c>=maxc) px=i,maxc=a[i].c;
		}
		ans+=(a[px].d-a[lx].d)*(va-vb)*a[px].c;
	}
	cout<<ans;
	return 0;
}
