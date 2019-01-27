#include<iostream>
using namespace std;
int f[100001],a[10001],b[10001];
int main() {
	int t,m;
	cin>>t>>m;
	for(int i=1; i<=m; i++)
		cin>>a[i]>>b[i];
	for(int i=1; i<=m; i++)
		for(int j=a[i]; j<=t; j++)
			f[j]=max(f[j],f[j-a[i]]+b[i]);
	cout<<f[t];
	return 0;
}
