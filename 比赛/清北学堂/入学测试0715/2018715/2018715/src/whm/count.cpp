#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char a[10][10],b[10][10];
int ans1,ans2;
using namespace std;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	    for(int j=1;j<=3;j++){
	    	cin>>a[i][j];
		}
	for(int i=1;i<=3;i++){
		if(a[i][1]==a[i][2]&&a[i][1]==a[i][3])ans1++;
		if(a[1][i]==a[2][i]&&a[2][i]==a[3][i])ans1++;
		if(a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][2]==a[i][3])ans2++;
		if(a[1][i]==a[2][i]||a[1][i]==a[3][i]||a[2][i]==a[3][i])ans2++;
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])ans1++;
	if(a[3][1]==a[2][2]&&a[2][2]==a[1][3])ans1++;
	if(a[1][1]==a[2][2]||a[1][1]==a[3][3]||a[2][2]==a[3][3])ans2++;
	if(a[3][1]==a[2][2]||a[1][3]==a[2][2]||a[1][3]==a[3][1])ans2++;
	ans2-=ans1;
	cout<<ans1<<endl<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
