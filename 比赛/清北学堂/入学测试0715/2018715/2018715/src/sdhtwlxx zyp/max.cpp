#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std ;

int l , n ;
int va, vb ;
int w[1100] , c[1100] ;
int f[1000] ;

inline int read(){
    char c=getchar();
    int t=0;
    bool flag=1;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-'){flag=0;c=getchar();}
    while(c>='0'&&c<='9'){t=t*10+c-'0';c=getchar();}
    return flag?t:-t;
}
int main(){
	//n >> l >> n >> va >> vb ;
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	l = read(),n = read(),va= read(),vb = read();
	for(int i = 1 ; i <= n ; i ++)
		w[i] = read(),c[i] = read();
	int sum = 0 ;
	int t = 1 ;
	int wait = 0 ; 
	for(int i = 1 ; i <= n ; i ++){
	//	if(i > w[t])
	//	sum += va 
	     sum += (w[i] - wait)*(va-vb)*c[i] ;\
	     wait = w[i] ;
	 } 
	 printf("%d",sum);
	 return 0;
} 
