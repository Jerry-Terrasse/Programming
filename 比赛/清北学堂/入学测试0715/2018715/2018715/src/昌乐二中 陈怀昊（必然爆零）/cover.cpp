#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
//bool line[100001];
struct a{
	int left;
	int right;
	int length;
}cover[101];

int n,k,maxx,ll,rr,ans;
int main(){
	//memset(line,false,sizeof(line));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>cover[i].left>>cover[i].right;
		cover[i].length=cover[i].right-cover[i].left;
        if(cover[i].length>maxx)
        maxx=cover[i].length;
        if(cover[i].left<ll)
          ll=cover[i].left;
        if(cover[i].right>rr)
          rr=cover[i].right;
	}
	
	if(k==1){
		cout<<maxx;
		return 0;
	}
	ans=rr-ll-1;
	cout<<ans;
	 /* 
	*/
	return 0;
}