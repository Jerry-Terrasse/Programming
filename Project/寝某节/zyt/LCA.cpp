#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 500000+1
struct edge {
	int v,
	    nxt;
} e[MAX<<1];
int n,m,s,a,b,cnt,d[MAX],fa[MAX][22],lg[MAX],head[MAX];
void add(int u,int v) {
	e[++cnt].nxt=head[u];
	e[cnt].v=v;
	head[u]=cnt;
}
void dfs(int u,int f) {
	d[u]=d[f]+1;
	fa[u][0]=f;
	for(int i=1; (1<<i)<=d[u]; i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u]; i; i=e[i].nxt)
		if(e[i].v!=f)
			dfs(e[i].v,u);
}
int LCA(int x,int y) {
	if(d[x]<d[y])
		swap(x,y);
	while(d[x]>d[y])
		x=fa[x][lg[d[x]-d[y]]-1];
	if(x==y)
		return x;
	for(int i=lg[d[x]]; i>=0; i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i], y=fa[y][i];
	return fa[x][0];
}
int main() {
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1; i<=n-1; i++) {
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(s,0);
	for(int i=1; i<=n; i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(b,a));
	}
	return 0;
}
