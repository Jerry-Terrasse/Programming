#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans; 
const int maxn=1e5+7;
int l[maxn],r[maxn],s[maxn];
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		s[i]=r[i]-l[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,r[i]-l[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	int ll=2147483647,rr=0;
	for(int i=1;i<=n;i++){
		ll=min(ll,l[i]);
		rr=max(rr,r[i]);
	}
	cout<<rr-ll<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
