#include<iostream>
#include<cstdio>
using namespace std;
char jing[5][5]; 
int ans1=0, ans2=0;
bool ok;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			cin>>jing[i][j];
	for(int i=1; i<=3; i++){
		ok=false;
		if(jing[1][i]==jing[2][i]){
			if(jing[2][i]==jing[3][i]){
				ans1++;
				ok=true;
			}	
		}
		if(jing[1][i]==jing[3][i] || jing[3][i]==jing[2][i] || jing[1][i]==jing[2][i]){
			if(!ok) ans2++;
		}
	}
	for(int i=1; i<=3; i++){
		ok=false;
		if(jing[i][1]==jing[i][2]){
			if(jing[i][2]==jing[i][3]){
				ans1++;
				ok=true;
			}	
		}
		if(jing[i][3]==jing[i][1] || jing[i][2]==jing[i][3] || jing[i][1]==jing[i][2]){
			if(!ok) ans2++;
		}
	}
	int j=2, k=1;
	while(j){
		ok=false;
		if(jing[1][k]==jing[2][2]){
			if(jing[2][2]==jing[3][4-k]){
				ans1++;
				ok=true;
			}	
		}
		if(jing[1][k]==jing[3][4-k] || jing[3][4-k]==jing[2][2] || jing[1][k]==jing[2][2]){
			if(!ok) ans2++;
		}
		j--;
		k=3;
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
