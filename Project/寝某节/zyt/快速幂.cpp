#include<iostream>
using namespace std;
long long b,p,k,r=1;
int main() {
	cin>>b>>p>>k;
	cout<<b<<'^'<<p<<" mod "<<k<<'=';
	while(p>0) {
		if(p%2==1)r=(r*b)%k;
		b=(b*b)%k;
		p/=2;
	}
	cout<<r;
	return 0;
}
