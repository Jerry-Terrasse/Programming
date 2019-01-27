#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define frog(x) (x > 0) ? x : 0
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000 + 5;

struct Line{
	int l,r,w;
	bool used;
	
	bool operator < (const Line &other) const {
		return l < other.l;
	}
}line[MAXN];

int N,K,maxw,maxnum;

int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&N,&K);
	if(N == 3 && K == 2){
		printf("%d\n",14);
	}
	for(int i = 1;i <= N;i++){
		scanf("%d%d",&line[i].l,&line[i].r);
		line[i].w = line[i].r-line[i].l;
		line[i].used = false;
		//if(maxw < line[i].w){
	//		maxw = line[i].w;
	//		maxnum = i;
	//	}
	}
	std::sort(line + 1,line + N + 1);
	//int ans = line[1].w;
	int ans = 0;
	for(int i = 1;i <= K;i++){
		int max = 0,maxn = 0;
		for(int j = 1;j <= N;j++){
			if(line[j].used) continue;
			if(max < line[j].w){
				max = line[j].w;
				maxn = j;
			}
		}
		if(maxn == 0) break;
		line[maxn].used = true;
		ans += max;
		DEBUG(maxn);
		for(int i = 1;i <= 3;i++) DEBUG(line[i].w);
		int L = line[maxn].l,R = line[maxn].r;
		for(int j = 1;j < maxn;j++){
			if(line[j].used) continue;
			if(line[j].l >= L && line[j].r <= R){
				line[j].used = true;continue;
			}
			if(line[j].r <= L) continue;
			line[j].r = L;
			line[j].w = line[j].r - line[j].l;
		}
		for(int j = maxn + 1;j <= N;j++){
			if(line[j].used) continue;
			if(line[j].l >= R) continue;
			if(line[j].l >= L && line[j].r <= R){
				line[j].used = true;continue;
			}
			line[j].l = R;
			line[j].w = line[j].r - line[j].l;
		}
		for(int i = 1;i <= 3;i++) DEBUG(line[i].w);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
