#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define long long ll
int sum,ans;
char a[4][4];
using namespace std;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	if(a[1][1]==a[2][1]&&a[1][1]==a[3][1]) ans++;
	if(a[1][2]==a[2][2]&&a[1][2]==a[3][2]) ans++;
	if(a[1][3]==a[2][3]&&a[1][3]==a[3][3]) ans++;
	if(a[1][1]==a[1][2]&&a[1][1]==a[1][3]) ans++;
	if(a[2][1]==a[2][2]&&a[2][1]==a[2][3]) ans++;
	if(a[3][1]==a[3][2]&&a[3][1]==a[3][3]) ans++;
	for(int i=1;i<3;i++){
		for(int j=1;j<3;j++){
			if(a[i][j]==a[i+1][j+1]||a[i][j]==a[i+1][j]||a[i][j]==a[i][j+1]) sum++;
		}
	}
	cout<<ans<<endl;
	cout<<sum-ans;
	return 0;
}

