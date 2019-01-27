#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<fstream>
using namespace std;
struct node{
	int a;
	int b;
}x[100010];
int n,k,f[100010],s;
int cmp(node x,node y){
	return x.a<y.a;
}
int dfs(int temp,int s,int q,int n,int k){
	int m=0,t;
	for(int i=q;i<=n;i++){
		if(x[i].a<=temp&&x[i].b>m){
			m=x[i].b;
			t=i;
		}
		else continue;
	}
	if(n+1==k) return s+x[t].b-temp;
	else    dfs(x[t].b,s+x[t].b-temp,t,n+1,k);
}
int main(){
	int i,j,t;
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++) {
	    cin>>x[i].a>>x[i].b;
    } 
	sort(x+1,x+1+n,cmp);
	
	for(i=1;i<=n;i++){
		f[i]=dfs(x[i].b,x[i].b-x[i].a,i,1,k);
	}
	   int maxn=0;
	   for(i=1;i<=n;i++){
	   	if(f[i]>maxn) maxn=f[i];
	   }
	   cout<<maxn;
	   return 0;
}
