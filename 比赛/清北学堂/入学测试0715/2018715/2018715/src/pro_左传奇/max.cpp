#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int l,n,va,vb,dv,dt,sum;
struct spot{
	int x,c;
};
spot list[100007];
bool cmp(spot a,spot b){
	if(a.c==b.c) return a.x<b.x;
	return a.c<b.c;
}
spot tmp;
int lastspot;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=0;i<n;i++){
		cin>>tmp.x>>tmp.c;
		list[i]=tmp;
	}
	dv=va-vb;
	sort(list,list+n,cmp);
	for(int i=n-1;i>=0;i--){
		tmp=list[i];
		if(tmp.x<=lastspot) continue;
		dt=(tmp.x-lastspot)*dv;
		sum+=dt*tmp.c;
		lastspot=tmp.x;
	}
	cout<<sum;
}

