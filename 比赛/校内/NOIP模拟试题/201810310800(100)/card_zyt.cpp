#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 0x3f3f3f3f
#define MAXN 100010
//#define LOCAL
struct card{
	int a,b;
	inline card(){
		a=b=0;
	}
	inline bool operator == (const card& x) const{
		return a==x.a && b==x.b;
	}
	inline bool operator < (const card& x) const{
		return a==x.a?b<x.b:a<x.a;
	}
} c[MAXN];
int n,n_,cnt,ans=INF,s[MAXN],t[MAXN];
int main(){
#ifdef LOCAL
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i].a,&c[i].b);
	sort(c+1,c+n+1);
	n_=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++){
		if(c[i].a!=c[i-1].a || i>n_){
			cnt++;
			t[cnt]=1;
		}
		else if(c[i].a==c[i-1].a){
			s[cnt]+=c[i].b-c[i-1].b-1;
			t[cnt]++;
		}
	}
	for(int i=1;i<=cnt;i++)
		ans=min(ans,max(s[i],n-t[i]));
	printf("%d",ans);
	return 0;
}
/*
5
1 1
1 2
1 3
1 4
1 5
*/
/*
5
1 9
1 10
2 11
2 12
2 13
*/
/*
10
1 7
3 8
1 9
2 10
1 11
2 12
3 13
1 14
1 15
2 16
*/
/*
10
1 1
1 1
1 1
1 100
1 100
1 100
1 100
2 3
2 4
2 5
*/
