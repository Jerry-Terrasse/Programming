#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
int k,n;
int l[500],r[500];
using namespace std;
struct{
	int l;
	int r;
}b[500];
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	sort(b.l,b.l+n);
    sort(b.r,b.r+n);
    cout<<b.l -b.r <<endl;
    return 0;
	fclose(stdin);
	fclose(stdout);
}
