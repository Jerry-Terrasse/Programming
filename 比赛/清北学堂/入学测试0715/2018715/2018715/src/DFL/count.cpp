#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char sq[4][4];
int ans1;
int ans2; 
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	    cin>>sq[i][j];
    if(sq[1][1]==sq[1][2]){
    	if(sq[1][1]==sq[1][3])ans1++;
    	else ans2++;
	}
	else if(sq[1][1]==sq[1][3]||sq[1][3]==sq[1][2])ans2++;
	if(sq[2][1]==sq[2][2]){
    	if(sq[2][1]==sq[2][3])ans1++;
    	else ans2++;
	}
	else if(sq[2][1]==sq[2][3]||sq[2][2]==sq[2][3])ans2++;
	if(sq[3][1]==sq[3][2]){
    	if(sq[3][1]==sq[3][3])ans1++;
    	else ans2++;
	}
	else if(sq[3][1]==sq[3][3]||sq[3][3]==sq[3][2])ans2++;
	if(sq[1][1]==sq[2][1]){
    	if(sq[1][1]==sq[3][1])ans1++;
    	else ans2++;
	}
	else if(sq[1][1]==sq[3][1]||sq[2][1]==sq[3][1])ans2++;
	if(sq[1][2]==sq[2][2]){
    	if(sq[1][2]==sq[3][2])ans1++;
    	else ans2++;
	}
	else if(sq[1][2]==sq[3][2]||sq[2][2]==sq[3][2])ans2++;
	if(sq[1][3]==sq[2][3]){
    	if(sq[1][3]==sq[3][3])ans1++;
    	else ans2++;
	}
	else if(sq[1][3]==sq[3][3]||sq[2][3]==sq[3][3])ans2++;
	if(sq[1][1]==sq[2][2]){
    	if(sq[1][1]==sq[3][3])ans1++;
    	else ans2++;
	}
	else if(sq[1][1]==sq[3][3]||sq[2][2]==sq[3][3])ans2++;
	if(sq[1][3]==sq[2][2]){
    	if(sq[1][3]==sq[3][1])ans1++;
    	else ans2++;
	}
	else if(sq[1][3]==sq[3][1]||sq[2][2]==sq[3][1])ans2++;
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
}
