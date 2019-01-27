#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int l,n;
int va,vb;
int wi[100100],ci[100100];
int f[100010];
signed main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>l>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	{
		cin>>wi[i]>>ci[i];
	}
	int ssm=0;
	int t=1;
	int wit=0;
	for(int i=1;i<=n;i++)
	{
	     ssm+=(wi[i]-wit)*(va-vb)*ci[i];
	     wit=wi[i];
	 }
	 cout<<ssm<<endl;
	 return 0;
}
