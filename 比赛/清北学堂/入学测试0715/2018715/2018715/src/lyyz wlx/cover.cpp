#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],t,js,max1,max2=0,jg;
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]>b[i]){
			t=a[i];a[i]=b[i];
			b[i]=t;
		}
	}
	max1=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<max1){
			max1=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>max2){
			max2=b[i];
		}
	}
	jg=max2-max1;
	cout<<jg;
}
