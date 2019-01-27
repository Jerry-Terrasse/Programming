#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<fstream>
using namespace std;
int l,n,va,vb;
int x[100010],c[100010],sum,s;
int main(){
	int i,j;
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(i=1;i<=n;i++) cin>>x[i]>>c[i];
	for(i=1;i<=n;i++){
		if(x[i]>l) break;
		if(c[i]>c[i-1]) sum=(va-vb)*x[i]*c[i];
		else sum+=(va-vb)*(x[i]-x[i-1])*c[i];
	}
	cout<<sum;
	return 0;
}
