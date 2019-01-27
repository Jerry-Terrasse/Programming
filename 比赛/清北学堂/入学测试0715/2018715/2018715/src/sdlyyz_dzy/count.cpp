#include<cstdio>
#include<iostream>
using namespace std;
int b[10], ans1, ans2, x, y, q;
char a[10];
int main(){
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for(int i = 1; i<= 9;i++){
		cin>>a[i];
		if(a[i] == 'A')b[i] = 1;
		if(a[i] == 'B')b[i] = 2;
		if(a[i] == 'C')b[i] = 3;
		if(a[i] == 'D')b[i] = 4;
		if(a[i] == 'E')b[i] = 5;
		if(a[i] == 'F')b[i] = 6;
		if(a[i] == 'G')b[i] = 7;
		if(a[i] == 'H')b[i] = 8;
		if(a[i] == 'I')b[i] = 9;
		if(a[i] == 'J')b[i] = 10;
		if(a[i] == 'K')b[i] = 11;
		if(a[i] == 'L')b[i] = 12;
		if(a[i] == 'M')b[i] = 13;
		if(a[i] == 'N')b[i] = 14;
		if(a[i] == 'O')b[i] = 15;
		if(a[i] == 'P')b[i] = 16;
		if(a[i] == 'Q')b[i] = 17;
		if(a[i] == 'R')b[i] = 18;
		if(a[i] == 'S')b[i] = 19;
		if(a[i] == 'T')b[i] = 20;
		if(a[i] == 'U')b[i] = 21;
		if(a[i] == 'V')b[i] = 22;
		if(a[i] == 'W')b[i] = 23;
		if(a[i] == 'X')b[i] = 24;
		if(a[i] == 'Y')b[i] = 25;
		if(a[i] == 'Z')b[i] = 26;
	}
	for(int i = 1; i <= 9; i = i + 3){
		if((b[i] == b[i + 1])&&(b[i] == b[i + 2]))ans1++;
	}
	for(int i = 1; i <= 3; i++){
		if((b[i] == b[i+3])&&(b[i] == b[i + 6]))ans1++;
	}
    for(int i = 1; i <= 3; i = i + 2){
    	if((b[i] == b[i + 4])&&(b[i] == b[i + 8]))ans1++;
	}
	for(int i = 1; i <= 9; i = i + 3){
		if(b[i] != b[i + 1])x++;
		if(b[i] != b[i + 2])x++; 
		if(x == 1)ans2++;
		x = 0;
		//cout<<ans2<<endl;
	}
	for(int i = 1; i <= 3; i++){
		if(b[i] != b[i+3])y++;
		if(b[i] != b[i+6])y++;
		if(y == 1)ans2++;
		y = 0;
		//cout<<ans2<<endl;
	}
    if(b[1] != b[5])y++;
    if(b[1] != b[9])y++;
    if(y == 1)ans2++;
    //cout<<ans2<<endl;
    if(b[3] != b[5])q++;
    if(b[3] != b[7])q++;
    if(q == 1)ans2++;
    //cout<<ans2<<endl;
	cout<<ans1<<endl<<ans2<<endl;
}
