#include<bits/stdc++.h>
using namespace std;
int sum,q;
struct datamode{
    int begin;
    int end;
    int j;
}data[100010];
bool cmp(datamode a, datamode b)
{
    return a.end<b.end;
}
int main(void){
   freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
    int n,k;
    cin >> n>>k;
    for(int i=1; i<=n; i++){
    cin >> data[i].begin >> data[i].end;
	data[i].j=data[i].end-data[i].begin;	   
   } 
    sort(data+1, data+1+n, cmp);
    for(int i=1;i<=n;i++){
    if(data[i].begin>=data[n].begin && data[i].end<=data[n].end){
    	sum++; 
    	if(sum==n){
		cout<<data[n].j;
		fclose(stdin);
		fclose(stdout);
    	return 0;
    }
	}
}
int min=0,ans=0;
	for(int i=1;i<=n;i++){
		if(data[i].end<=data[n].begin)   min=max(min,data[i].j);
		if(data[i].begin>=data[n].end)   ans=max(ans,data[i].j);
	}
	ans=max(ans,min);
int o=0,p=0;	
	for(int i=1;i<=n;i++){
	 if(data[i].end>=data[n].begin && data[i].begin<=data[n].begin) o=max(o,data[n].end-data[i].begin);
	 if(data[i].begin<=data[n].begin && data[i].end>=data[n].end)   p=max(p,data[i].end-data[n].begin);
	}
	p=max(p,o);
int y=ans+data[n].j;
	p=max(p,y);
	cout<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;

};
	

