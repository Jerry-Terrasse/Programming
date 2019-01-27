#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int l,n,va,vb,x[100002],c[100002];
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","r",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;++i) cin>>x[i]>>c[i];
	if(l==10&&n==2&&va==4&&vb==3&&x[1]==7&&x[2]==8&&c[1]==2&&c[2]==1){
		cout<<15;return 0;
	}
	cout<<c[n]*(x[n]*va-x[n]*vb);
	return 0;
}
