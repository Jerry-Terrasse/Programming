#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	int x,c;
}p[100050];
int maxm[1050],mem[1050];
int l,n,va,vb;
int ans;
bool cmp(point x,point y){
	return x.c<y.c;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].c);
	}
	sort(p+1,p+n,cmp);
	int now1=1;
	for(int i=1;i<=n;i++){
		if(p[i].c>maxm[p[i].x]){
		for(int j=now1;j<=p[i].x;j++){
		maxm[j]=p[i].c;
		mem[j]=p[i].x;
		}
		now1=p[i].x+1;
		}
	}
	/*for(int i=1;i<=l;i++){
		cout<<"i = "<<i<<" mem[i] = "<<mem[i]<<" maxm[i] = "<<maxm[i]<<endl;
	}*/
	int delta=va-vb;int last=0;
	for(int i=1;i<=l;i=mem[i]){
		if(mem[i]==i)i++;
		if(mem[i]==0)break;
		
		int now2=mem[i];
		ans+=(now2-last)*maxm[i]*delta;
		last=mem[i];
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
