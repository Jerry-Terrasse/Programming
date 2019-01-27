#include<iostream>
#include<algorithm>
#include<cstdio>
const int N=100007,K=107,INF=2147483647;
using namespace std;
struct line{
	int l,r;
	bool disable;
};
bool cmp(line a,line b){
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}
int dp[N][K][2];
int divide[N];
line list[N];
int n,k;
line tmp;
void process(){
	sort(list+1,list+n+1,cmp);
	int rpos=-1;
	int deleted=0;
	for(int i=1;i<=n;i++){
		if(list[i].r<=rpos) list[i].l=list[i].r=INF,deleted++;
		else rpos=list[i].r;
	}
	sort(list+1,list+n+1,cmp);
	n-=deleted;
}
int ans;
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>list[i].l>>list[i].r;
	}
	process();
	int i=1,divl=0,divr=0;
	while(i<=n){
		if(list[i].l>list[divr].r){
			divr++;
			continue;
		}else if(list[i].l==list[divr].r){
			divl=divr;
		}else divl=divr-1;
		for(int m=k;m>0;m--){
			dp[i][m][0]=max(dp[divr][m-1][0]+list[i].r-list[divr].r,dp[divl][m-1][1]+list[i].r-list[i].l);
			dp[i][m][1]=max(dp[i-1][m][1],dp[i][m][0]);
			ans=max(ans,dp[i][m][1]);
		}
		i++;
	}
	cout<<ans;
}
