#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
char a[4][4];
int x,y,z,tot1,tot2;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j) scanf("%1s",&a[i][j]);
	for(int i=1;i<=3;++i){
		if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]) {tot1++;continue;}
		if(a[i][2]==a[i][1]||a[i][2]==a[i][3]||a[i][1]==a[i][3]) {tot2++;continue;}
	}
	for(int j=1;j<=3;++j){
		if(a[1][j]==a[2][j]&&a[2][j]==a[3][j]) {tot1++;continue;}
		if(a[2][j]==a[1][j]||a[2][j]==a[3][j]||a[1][j]==a[3][j]) {tot2++;continue;}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]) tot1++;
	if(a[1][1]==a[2][2]||a[2][2]==a[3][3]||a[1][1]==a[3][3]) tot2++;
	if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]) tot1++;
	if(a[1][3]==a[2][2]||a[2][2]==a[3][1]||a[1][3]==a[3][1]) tot2++;
	cout<<tot1<<endl;
	cout<<tot2;
	return 0;
}
