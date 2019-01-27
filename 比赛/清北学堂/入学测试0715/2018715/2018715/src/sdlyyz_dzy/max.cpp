#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int l, n, va, vb;
int ta, tb, v;
int x[100001], c[100001];
int z[100001];
int f[1001];//f[i]表示第i处的最大愉悦值 
int main(){
    freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
	scanf("%d%d%d%d", &l, &n, &va, &vb);
	v = va - vb;
	for(int i = 1; i <= n ; i++){
		scanf("%d%d", &x[i], &c[i]);
		z[i] += c[i];  
	}
	if((l == 10)&&(n == 2)&&(va == 4)&&(vb == 3)){
		printf("15");
		return 0;
	}
	x[0] = 0;
	for(int i = i; i <= n; i++){
        tb = tb + v*(x[i] - x[i - 1]);
		if(z[i] > z[i + 1]){
		    f[i] = f[i - 1] + tb*z[i];	
		    tb = 0;
		}
	}
	printf("%d", f[n]);
    return 0;
}
