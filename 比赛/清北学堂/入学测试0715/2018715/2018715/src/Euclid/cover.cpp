#include<iostream>
#include<cstdlib>
#include<cstdio>
#define min(a,b) (a<b?a:b)
#define N 100005

using namespace std;

struct edge{
	int left,right;
}e[N];

int n,k,ans,minl,minr;

inline bool cmp(const edge&a,const edge&b){return a.right-a.left+1<b.right-b.left+1;}

int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d%d",&e[i].left,&e[i].right);
	for(int i=1;i<=n;++i){
		minl=min(e[i].left,minl);
		minr=min(e[i].right,minr);
	}
	printf("%d\n",minr-minl);
	return 0;
}
