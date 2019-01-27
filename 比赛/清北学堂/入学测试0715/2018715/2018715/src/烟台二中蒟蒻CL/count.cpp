#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char  ji ;
int  a[5][5] ;
long long  he[5][5] ;//2:行  1:列  3:斜 
int   jia ;
int  jishu1 = 0 , jishu2 = 0 ;
bool  v[25];//false
bool  u[25][25];
int main(){
	//freopen("count.in","r",stdin);
	//freopen("count.out","w",stdout);
    for(int i = 1 ; i <= 3 ; i++){
    	for(int j = 1 ; j <= 3 ; j++){
    	    cin >> ji ;
    		a[i][j] = (ji - 'A');
    	}
    }
    
    
	he[2][1] =  a[1][1] + a[1][2] + a[1][3]  ;//1 1
	he[2][2] =  a[2][1] + a[2][2] + a[2][3]  ;//2 1
	he[2][3] =  a[3][1] + a[3][2] + a[3][3]  ;//3 1
	he[1][1] =  a[1][1] + a[2][1] + a[3][1]  ;//1 1
	he[1][2] =  a[1][2] + a[2][2] + a[3][2]  ;//1 2
	he[1][3] =  a[1][3] + a[2][3] + a[3][3]  ;//1 3
	he[3][1] =  a[1][1] + a[2][2] + a[3][3]  ;//2 2
	he[3][2] =  a[1][3] + a[2][2] + a[3][1]  ;//2 2
	he[3][3] = 71203751 ; 
	
	
	for(int i = 1 ; i <= 3 ; i++){
		for(int j = 1 ; j <= 3 ; j++){
			if(i == 1){ //第j列 
				if(he[i][j] / 3 == a[1][j] && he[i][j] / 3 == a[3][j] && v[a[1][j]] == false){
					v[a[i][j]] = true ;
					jishu1 ++ ;
				}
				if(a[1][j]==a[2][j] && u[a[1][j]][a[2][j]] == false && a[2][j]!=a[3][j]){
					u[a[1][j]][a[2][j]] = true ;
					u[a[2][j]][a[1][j]] = true ;
					jishu2 ++ ;
				}
				else if(a[2][j]==a[3][j] && u[a[2][j]][a[3][j]] == false && a[1][j]!=a[3][j]){
					u[a[2][j]][a[3][j]] = true ;
					u[a[3][j]][a[2][j]] = true ;
					jishu2 ++ ;
				}
				else if(a[1][j]==a[3][j] && u[a[1][j]][a[3][j]] == false && a[2][j]!=a[3][j]){
					u[a[1][j]][a[3][j]] = true ;
					u[a[3][j]][a[1][j]] = true ;
					jishu2 ++ ;
				}
			}
			else if(i == 2){ //第j行 
				if(he[i][j] / 3 == a[j][1] && he[i][j] / 3 == a[j][3] && v[a[j][1]] == false){
					v[a[j][1]] = true ;
					jishu1 ++ ;
				}
				if(a[j][1]==a[j][3] && u[a[j][1]][a[j][3]] == false && a[j][2]!=a[j][3]){
					u[a[j][1]][a[j][3]] = true ;
					u[a[j][3]][a[j][1]] = true ;
					jishu2 ++ ;
				}
				else if(a[j][2]==a[j][3] && u[a[j][2]][a[j][3]] == false && a[j][1]!=a[j][2]){
					u[a[j][2]][a[j][3]] = true ;
					u[a[j][3]][a[j][2]] = true ;
					jishu2 ++ ;
				}
				else if(a[j][1]==a[j][2] && u[a[j][1]][a[j][2]] == false && a[j][1]!=a[j][3]){
					u[a[j][1]][a[j][2]] = true ;
					u[a[j][2]][a[j][1]] = true ;
					jishu2 ++ ;
				}
			}
			if(i == 3 && j == 1 ){
				if(he[i][j] / 3 == a[2][2] && he[i][j] / 3 == a[1][1] && v[a[1][1]] == false){
					v[a[1][1]] = true ;
					jishu1 ++ ;
				}
				if(a[1][1]==a[2][2] && u[a[1][1]][a[2][2]] == false && a[1][1]!=a[3][3]){
					u[a[1][1]][a[2][2]] == true ;
					u[a[2][2]][a[1][1]] == true ;
					jishu2 ++;
				}
				else if(a[1][1]==a[3][3] && u[a[1][1]][a[3][3]] == false && a[3][3]!=a[2][2]){
					u[a[1][1]][a[3][3]] == true ;
					u[a[3][3]][a[1][1]] == true ;
					jishu2 ++;
				}
				else if(a[3][3]==a[2][2] && u[a[3][3]][a[2][2]] == false && a[1][1]!=a[2][2]){
					u[a[3][3]][a[2][2]] == true ;
					u[a[2][2]][a[3][3]] == true ;
					jishu2 ++;
				}
			}
			if(i == 3 && j == 2 ){
				if(he[i][j] / 3 == a[2][2] && he[i][j] / 3 == a[1][3] && v[a[1][3]] == false){
					v[a[1][3]] = true ;
					jishu1 ++ ;
				}
				if(a[1][3]==a[2][2] && u[a[1][3]][a[2][2]] == false && a[1][3]!=a[3][1]){
					u[a[1][3]][a[2][2]] == true ;
					u[a[2][2]][a[1][3]] == true ;
					jishu2 ++;
				}
				else if(a[1][3]==a[3][1] && u[a[1][3]][a[3][1]] == false && a[3][1]!=a[2][2]){
					u[a[1][3]][a[3][1]] == true ;
					u[a[3][1]][a[1][3]] == true ;
					jishu2 ++;
				}
				else if(a[3][1]==a[2][2] && u[a[3][1]][a[2][2]] == false && a[1][3]!=a[2][2]){
					u[a[3][1]][a[2][2]] == true ;
					u[a[2][2]][a[3][1]] == true ;
					jishu2 ++;
				}
			}
		}
	}
	cout << jishu1 << endl;
	cout << jishu2 ;
	
	
	
} 
