#include<iostream>
using namespace std;
int main(){
	int a[7],b[7],i,s;
	i=0;s=0;
	for(i=0;i<=6;i++){
		a[i]=0;b[i]=0;}
	for(i=0;i<=6;i++){
		cin>>a[i]>>b[i];
		a[i]=a[i]+b[i];
		if((a[i]>8)&&(a[i]>a[s-1])){
			s=i+1;}}
	cout<<s<<endl;
	return 0;}
