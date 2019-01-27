#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define long long ll
const int maxn=501;
using namespace std;
int n,k,res;
struct gjc{
	int x1,x2,val; 
}dd[maxn];
bool cmp(gjc a,gjc b){
	return a.val<b.val;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	res=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>dd[i].x1>>dd[i].x2;
		dd[i].val=dd[i].x2-dd[i].x1;
	}
	sort(dd,dd+n,cmp);
	for(int i=n;i>=k;i--){
		res+=dd[i].val;
		for(int j=n-1;j>=1;j--){
			if(dd[j].x1>=dd[i].x1&&dd[j].x2<=dd[i].x2) dd[j].val=0;//2
			if(dd[j].x1<dd[i].x1&&dd[j].x2<=dd[i].x1) dd[j].val=dd[j].val;//2
			if(dd[j].x1<dd[i].x1&&dd[j].x2>dd[i].x1&&dd[j].x2<=dd[i].x2) dd[j].val=dd[i].x1-dd[j].x1;//1
			if(dd[j].x1>dd[i].x1&&dd[j].x2>dd[i].x2) dd[j].val=dd[j].x2-dd[i].x2;//1
			//if(dd[j].x1>dd[i].x1&&dd[])
		}
		sort(dd,dd+n,cmp);
	}
	cout<<res+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
