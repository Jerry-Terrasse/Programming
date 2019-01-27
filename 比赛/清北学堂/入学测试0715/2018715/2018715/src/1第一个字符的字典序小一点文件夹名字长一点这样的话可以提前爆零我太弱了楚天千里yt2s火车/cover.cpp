#include <cstdio>
#include <algorithm>

const int MAXN=10010, INF=0x7fffffff;
int n, k, cnt=1, ans, ll=INF, rr=INF;
int que[101];

struct pii {
	int l, r, len, x;
	bool c=false;
	void calc() {
		len=r-l+1;
	}
} seg[MAXN];

bool operator < (pii a, pii b) {
	return a.x<b.x;
}
 
bool cmp(pii a, pii b) {
	return a.l<b.l;
}

int main() {
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++) scanf("%d%d", &seg[i].l, &seg[i].r), seg[i].calc(), ll=std::min(ll, seg[i].l), rr=std::max(rr, seg[i].r);
	std::sort(seg, seg+n, cmp);
	ans=rr-ll+1;
	for(int i=0; i<n; i++) {
		bool b=false;
		for(int j=i+1; j<n; j++) {
			if(seg[j].l>seg[i].r) {i=j; if(b) {cnt++; seg[j-1].c=true;} else {ans-=seg[j].l-seg[i].r-1; seg[j].c=true;} break;}
			if(seg[j].l<=seg[i].r) b=1;
		}
	}
	int res=cnt-k;
	if(res<=0) {
		printf("%d\n", ans);
		fclose(stdin); fclose(stdout);
		return 0;
	} else {
		
	//	for(int i=1; i<n-1; i++)
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
