#include<iostream>

using namespace std ;

int l , n ;

int va, vb ;

int w[110000] , c[110000] ;

int f[110000] ;

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>c[i] ;
	int sum=0;
	int t=1;
	int wait=0; 
	for(int i=1;i<=n;i++)
	{
	     sum+=(w[i]-wait)*(va-vb)*c[i];
	     wait = w[i] ;
	 } 
	 cout<<sum;
	 return 0;
} 
