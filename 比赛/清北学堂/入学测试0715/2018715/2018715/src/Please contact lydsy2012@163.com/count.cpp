#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

const int MAXN = 100;
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int m[MAXN][MAXN],ans1,ans2;

inline bool equ(int x,int y,int z){
	return ((x == y) && (y == z));
}

inline int judge1(){
	int ret = 0;
	for(int i = 1;i <= 3;i++){
		if(equ(m[i][1],m[i][2],m[i][3]))
			ret++;
		if(equ(m[1][i],m[2][i],m[3][i]))
			ret++;
	}
	if(equ(m[1][1],m[2][2],m[3][3])) ret++;
	if(equ(m[3][1],m[2][2],m[1][3])) ret++;
	return ret;
}

inline int judge2(){
	int ret = 0;
	for(int i = 1;i <= 3;i++){
		if((m[i][1] == m[i][2] || m[i][2] == m[i][3] || m[i][3] == m[i][1]) && !equ(m[i][1],m[i][2],m[i][3]))
			ret++;
		if((m[1][i] == m[2][i] || m[2][i] == m[3][i] || m[3][i] == m[1][i]) && !equ(m[1][i],m[2][i],m[3][i]))
			ret++;
	}
	if((m[1][1] == m[2][2] || m[2][2] == m[3][3] || m[3][3] == m[1][1]) && !equ(m[1][1],m[2][2],m[3][3])) ret++;
	if((m[3][1] == m[2][2] || m[2][2] == m[1][3] || m[1][3] == m[3][1]) && !equ(m[3][1],m[2][2],m[1][3])) ret++;
	return ret;
}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i = 1;i <= 3;i++){
		std::string str;
		std::cin >> str;
		for(int j = 0;j < 3;j++)
			m[i][j + 1] = (int)(str[j]);
	}
	printf("%d\n%d",judge1(),judge2());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
