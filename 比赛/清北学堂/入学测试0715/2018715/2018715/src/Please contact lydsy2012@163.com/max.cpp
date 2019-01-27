#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#define LL long long
const int MAXN = 100000 + 5;
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

struct Data{
	LL x,c;
	
	bool operator < (const Data &other) const {
		if(c == other.c) return x < other.x;
		return c > other.c;
	}
}a[MAXN];

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	LL L,N,A,B;
	scanf("%lld%lld%lld%lld",&L,&N,&A,&B);
	LL delta = (A - B);
	for(int i = 1;i <= N;i++)
		scanf("%lld%lld",&a[i].x,&a[i].c);
	std::sort(a + 1,a + N + 1);
	LL ans = a[1].c * a[1].x * delta,now = a[1].x;
	for(int i = 2;i <= N;i++){
		if(a[i].x > now){
			ans += a[i].c * delta * (a[i].x - now);
			now = a[i].x;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
