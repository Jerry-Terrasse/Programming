#include<iostream>
using namespace std;
int f[1001],a[101],b[101];
int main() {
	int t,m;
	cin>>t>>m;
	for(int i=1; i<=m; i++)
		cin>>a[i]>>b[i];
	for(int i=1; i<=m; i++)
		for(int j=t; j>=a[i]; j--)
			f[j]=max(f[j],f[j-a[i]]+b[i]);
	cout<<f[t];
	return 0;
}
