#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char a[4][4];
int ans1,ans2;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++){
		cin>>a[i][j];
	}
	//1
	if(a[1][1]==a[1][2]){
		if(a[1][1]=a[1][3])ans1++;
		else ans2++;
	}
	else if(a[1][1]==a[1][3]||a[1][2]==a[1][3])ans2++;
	//2
	if(a[2][1]==a[2][2]){
		if(a[2][1]=a[2][3])ans1++;
		else ans2++;
	}
	else if(a[2][1]==a[2][3]||a[2][2]==a[2][3])ans2++;
	//3
	if(a[3][1]==a[3][2]){
		if(a[3][1]=a[3][3])ans1++;
		else ans2++;
	}
	else if(a[3][1]==a[3][3]||a[3][2]==a[3][3])ans2++;
	//4
	if(a[1][1]==a[2][1]){
		if(a[1][1]=a[3][1])ans1++;
		else ans2++;
	}
	else if(a[1][1]==a[3][1]||a[2][1]==a[3][1])ans2++;
	//5
	if(a[1][2]==a[2][2]){
		if(a[1][2]=a[3][2])ans1++;
		else ans2++;
	}
	else if(a[1][2]==a[3][2]||a[2][2]==a[3][2])ans2++;
	//6
	if(a[1][3]==a[2][3]){
		if(a[1][3]=a[3][3])ans1++;
		else ans2++;
	}
	else if(a[1][3]==a[3][3]||a[2][3]==a[3][3])ans2++;
	//7
	if(a[1][1]==a[2][2]){
		if(a[1][1]=a[3][3])ans1++;
		else ans2++;
	}
	else if(a[1][1]==a[3][3]||a[2][2]==a[3][3])ans2++;
	//8
	if(a[1][3]==a[2][2]){
		if(a[1][3]=a[3][1])ans1++;
		else ans2++;
	}
	else if(a[1][3]==a[3][1]||a[2][2]==a[3][1])ans2++;
	
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
