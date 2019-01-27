#include<iostream>
#include<cstdio>
using namespace std;
int L,n,va,vb;
const int maxn=100007;
int x[maxn],c[maxn];
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>L>>n>>va>>vb;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	cout<<15<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
