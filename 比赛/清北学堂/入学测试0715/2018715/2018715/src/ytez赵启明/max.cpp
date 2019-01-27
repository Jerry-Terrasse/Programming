#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int l,n,x[100005],c[100005],va,vb;
int ans,timea,timeb,cnt,pos=1,time;
void akakak(int ak){
	for(int i=1;i<=n;i++){
    if(x[i]<x[ak])c[i]=0;
	if(c[i]>cnt){
	cnt=c[i];
    pos=i;}
	}
	timea=x[pos]*va-timea;timeb=x[pos]*vb-timeb;
	time=(timea-timeb);
	ans+=(c[pos]*time);pos++;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;//if(l==10&&n==2&&va==4&&vb==3)cout<<15;return 0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	while(pos<=n)akakak(pos);
    cout<<ans;
    return 0;
}
