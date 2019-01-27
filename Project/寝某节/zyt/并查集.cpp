#include<iostream>
using namespace std;
int n,m,z,x,y,f[10001];
int find(int a) {
	return f[a]==a?a:f[a]=find(f[a]);
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)f[i]=i;
	while(m--) {
		cin>>z>>x>>y;
		if(z==1) {
			if(find(x)!=find(y))f[find(x)]=find(y);
		} else {
			if(find(x)==find(y))cout<<'Y'<<endl;
			else cout<<'N'<<endl;
		}
	}
	return 0;
}
