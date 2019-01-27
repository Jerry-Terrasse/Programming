#include <iostream>
#include <cstdio>
#include <algorithm>

#define N_MAX 100005

int len,n,va,vb;

struct A{
	int wz,hap;
}a[N_MAX];

bool cmp(A b,A c){
	return b.hap > c.hap;
}

int dqwz;
int ans;

int main(int argc,char *argv[]){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d %d %d %d",&len,&n,&va,&vb);
	for(int i = 1;i <= n;i++)scanf("%d %d",&a[i].wz,&a[i].hap);
	std::sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i++){
		if(a[i].wz <= dqwz)continue;
		ans += ((a[i].wz - dqwz) * (va - vb)) * a[i].hap;
		dqwz = a[i].wz;
	}
	printf("%d",ans);
	return 0;
}
