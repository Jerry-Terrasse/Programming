#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100005
#define M 310

using namespace std;

int n,k,ans=-2147483647;
int f[M][M];
struct Line{
	int l;
	int r;	
}l[N];

int ask_len(int x,int y){
	return l[y].r-l[x].r;
}
inline bool cmp(Line x,Line y){
	if(x.l!=y.l)
		return x.l<y.l;
	return x.r>y.r;
}
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while (ch>'9'||ch<'0') {if (ch=='-') w=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		l[i].l=read();
		l[i].r=read();
	}
	sort(l+1,l+n+1,cmp);
	for(int i=1;i<=n;i++)
        f[i][1]=l[i].r-l[i].l;
	for(int i=1;i<=n;++i){
	 int sign=min(i,k);
	 for(int j=1;j<=sign;j++){
		for(int k=i-1;k>=1;k--){
			if(l[i].l<=l[k].r)
			  f[i][j]=max(f[i][j],f[k][j-1]+ask_len(k,i));
			else
			  f[i][j]=max(f[i][j],f[k][j-1]+l[i].r-l[i].l);
			ans=max(ans,f[i][j]);
		}
	 }
	}
	printf ("%d\n",ans);
	return 0;	
}
