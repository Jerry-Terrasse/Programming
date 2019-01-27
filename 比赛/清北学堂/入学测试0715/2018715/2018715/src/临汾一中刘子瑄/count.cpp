#include<iostream>
using namespace std;
char well[4][4];
int ans1, ans2, num;
char team[10];
int main(){
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++){
			cin>>well[i][j];
		}
	for(int i=1; i<=3; i++){
		if(well[i][1]==well[i][2]&&well[i][2]==well[i][3])ans1++;
		if(well[1][i]==well[2][i]&&well[2][i]==well[3][i])ans1++;
	}
	if(well[1][1]==well[2][2]&&well[2][2]==well[3][3])ans1++;
	if(well[1][3]==well[2][2]&&well[2][2]==well[3][1])ans1++;
	
	//xie
	if(well[1][1]==well[3][3]&&well[1][1]!=well[2][2])ans2++;
	if(well[1][1]==well[2][2]&&well[3][3]!=well[2][2])ans2++;
	if(well[2][2]==well[3][3]&&well[1][1]!=well[2][2])ans2++;
	if(well[1][3]==well[3][1]&&well[1][3]!=well[2][2])ans2++;
	if(well[1][3]==well[2][2]&&well[3][1]!=well[2][2])ans2++;
	if(well[3][1]==well[2][2]&&well[1][3]!=well[2][2])ans2++;
	
	for(int i=1; i<=3; i++){
		//shu
		if(well[1][i]==well[2][i]&&well[2][i]!=well[3][i])ans2++;
		if(well[3][i]==well[2][i]&&well[2][i]!=well[1][i])ans2++;
		if(well[1][i]==well[3][i]&&well[2][i]!=well[3][i])ans2++;
		///heng
		if(well[i][1]==well[i][2]&&well[i][2]!=well[i][3])ans2++;
		if(well[i][1]==well[i][3]&&well[i][2]!=well[i][3])ans2++;
		if(well[i][3]==well[i][2]&&well[i][2]!=well[i][1])ans2++;
	}
	cout<<ans1<<endl<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
