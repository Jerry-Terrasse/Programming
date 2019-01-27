#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std ;

int l , n ;
int va, vb ;
int w[1100] , c[1100] ;
int f[1000] ;

int main(){
    freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i = 1 ; i <= n ; i ++)
		cin>>w[i]>>c[i];
	int sum = 0 ;
	int t = 1 ;
	int wait = 0 ; 
	for(int i = 1 ; i <= n ; i ++){
	     sum += (w[i] - wait)*(va-vb)*c[i] ;
	     wait = w[i] ;
	 } 
	 printf("%d",sum);
	 return 0;
} 
