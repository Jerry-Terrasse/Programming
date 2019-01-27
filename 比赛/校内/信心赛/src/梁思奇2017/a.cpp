#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=3010;

struct data{
	int nxt,to;
};

data edge[maxn];

int t,m,n,e_cnt,ans,x,y;
int head[maxn],pd[maxn][maxn];

void addedge(int,int);

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		e_cnt=0;
		memset(head,0,sizeof(head));
		memset(pd,0,sizeof(pd));
		ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			addedge(y,x);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) pd[i][j]=1;
				else{
					for(int k=head[i]; k && !pd[i][j]; k=edge[k].nxt){
						int to=edge[k].to;
						pd[i][j]|=pd[to][j];
					}
					for(int k=head[j]; k && !pd[i][j]; k=edge[k].nxt){
						int to=edge[k].to;
						pd[i][j]|=pd[i][to];
						pd[i][j]|=pd[to][i];
					}
				}
				ans+=pd[i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 

void addedge(int from,int to){
	edge[++e_cnt].nxt=head[from];
	edge[e_cnt].to=to;
	head[from]=e_cnt;
	pd[from][to]=1;
	pd[to][from]=1;
}
