#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
struct hyq{
	int l;
	int r;
}li[101000];
int cmp(hyq a,hyq b){
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}
int sum,end;
int dfs(int u,int num,int en){
	if(num==1){return li[u].r-li[u].l;}		
	for(int i=u+1;i<=n;i++){
	    sum+=li[i].r-max(li[i].l,en);
	    sum=max(sum,sum+dfs(i,num-1,li[i].l));
	    return sum;
	}
	
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>li[i].l>>li[i].r;
		//sum+=li[i].r-li[i].l;
	}
	sort(li+1,li+n+1,cmp);
   cout<<dfs(1,k,0)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
