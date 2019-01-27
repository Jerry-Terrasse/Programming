#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define N 5000

using namespace std;

struct group{
	int fir,sec;
}g[N];

char e[4][4];
int ans1,ans2,tot,temp,t;//1 group,2 person
int in[130];
bool mark[130];

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	F(i,1,3){F(j,1,3)scanf("%c",&e[i][j]);getchar();}
	F(i,1,3){
		tot=0;memset(in,false,sizeof(in));
		F(j,1,3) ++in[(int)e[i][j]];
		for(int i=1;i<=130;++i) tot=max(tot,in[i]);
		if(tot==2){
			++ans1;++t;
			for(int i=1;i<=130;++i){
				if(in[i]==1) g[t].fir=i;
				if(in[i]==2) g[t].sec=i;
			}
		}
		if(tot==3) ++ans2;
	}	
	F(i,1,3){
		tot=0;memset(in,false,sizeof(in));
		F(j,1,3) ++in[(int)e[j][i]];
		for(int i=1;i<=130;++i) tot=max(tot,in[i]);
		if(tot==2){
			++ans1;++t;
			for(int i=1;i<=130;++i){
				if(in[i]==1) g[t].fir=i;
				if(in[i]==2) g[t].sec=i;
			}
		}
		if(tot==3) ++ans2;
	}
	if(e[1][1]==e[2][2]&&e[1][1]==e[3][3]) ++ans2;
	if(e[1][3]==e[2][2]&&e[1][3]==e[3][1]) ++ans2;
	
	if(e[1][1]==e[2][2]||e[1][1]==e[3][3]||e[2][2]==e[3][3]){
		++ans1;++t;
		if(e[1][1]==e[2][2]) g[t].fir=e[1][1],g[t].sec=e[3][3];
		if(e[1][1]==e[3][3]) g[t].fir=e[1][1],g[t].sec=e[2][2];
		if(e[3][3]==e[2][2]) g[t].fir=e[1][1],g[t].sec=e[3][3];
	}
	if(e[1][3]==e[2][2]||e[1][3]==e[3][1]||e[2][2]==e[3][1]){
		++ans1;++t;
		if(e[1][3]==e[2][2]) g[t].fir=e[1][3],g[t].sec=e[3][1];
		if(e[1][3]==e[3][1]) g[t].fir=e[2][2],g[t].sec=e[3][1];
		if(e[2][2]==e[3][1]) g[t].fir=e[3][1],g[t].sec=e[1][3];
	}
	for(int i=1;i<=t;++i){
		if(!mark[g[i].fir]&&!mark[g[i].sec]) mark[g[i].fir]=mark[g[i].sec]=true;
		else ++temp;
	}
	printf("%d\n%d\n",ans2,ans1-temp);
	return 0;
}
