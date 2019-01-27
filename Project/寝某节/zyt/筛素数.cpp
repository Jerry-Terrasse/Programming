#include<iostream>
#include<cmath>
using namespace std;
bool su(int x) {
	if(x==1)return 0;
	if(x==2 || x==3)return 1;
	if(x%6!=1 && x%6!=5)return 0;
	for(int i=5; i<=sqrt(x); i+=6)if(x%i==0 || x%(i+2)==0)return 0;
	return 1;
}
int main() {
	int n,m,x;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>x;
		if(su(x))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
