#include<bits/stdc++.h>

using namespace std;

int l,n,va,vb,x[100001],c[1000001],d,maxt,lc,js,lb;
long long klz;

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d %d %d %d",&l,&n,&va,&vb);
	for(int i = 1 ; i <= n ; i++){
	scanf("%d %d",&x[i],&c[i]);

		d = maxt;
		maxt = max(c[i],maxt);
		if(d != maxt)lb = x[i];
		js/*记录max所在位置*/ = i;
	}
	
	klz = d * lb * (va - vb);
	
	while(js != n){
		for(int j = js ; j <= n ; j++){
			d = maxt;
			maxt = max(c[j],maxt);
			if(d != maxt)lc = x[j]-lb,lb = x[j],js = j;
		}
		
		klz += d * lc * (va - vb);

	}
	printf("%d",klz + va - vb);
	
	return 0;
}
