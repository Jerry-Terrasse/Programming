#include<bits/stdc++.h>
char a[4][4];
int ans1, ans2;
int main(){
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for(int i = 1; i <= 3; i ++){
		for(int j = 1; j <= 3; j ++){
			std::cin >> a[i][j];
		}
	}
	if(a[1][1] == a[1][2] && a[1][2] == a[1][3]) ans1 ++;
	if(a[2][1] == a[2][2] && a[2][2] == a[2][3]) ans1 ++;
	if(a[3][1] == a[3][2] && a[3][2] == a[3][3]) ans1 ++;
	
	if(a[1][1] == a[2][1] && a[1][1] == a[3][1]) ans1 ++;
	if(a[1][2] == a[2][2] && a[2][2] == a[3][2]) ans1 ++;
	if(a[1][3] == a[2][3] && a[1][3] == a[3][3]) ans1 ++;
	
	if(a[1][1] == a[2][2] && a[2][2] == a[3][3]) ans1 ++;
	if(a[1][3] == a[2][2] && a[2][2] == a[3][1]) ans1 ++;
	
	if((a[1][1] == a[1][2] && a[1][2] != a[1][3]) || (a[1][1] != a[1][2] && a[1][2] == a[1][3]) || (a[1][1] != a[1][2] && a[1][1] == a[1][3])) ans2 ++;
	if((a[2][1] == a[2][2] && a[2][2] != a[2][3]) || (a[2][1] != a[2][2] && a[2][2] == a[2][3]) || (a[2][1] != a[2][2] && a[2][1] == a[2][3])) ans2 ++;
	if((a[3][1] == a[3][2] && a[3][2] != a[3][3]) || (a[3][1] != a[3][2] && a[3][2] == a[3][3]) || (a[3][1] != a[3][2] && a[3][1] == a[3][3])) ans2 ++;
	
	if((a[1][1] == a[2][1] && a[1][1] != a[3][1]) || (a[1][1] != a[2][1] && a[2][1] == a[3][1]) || (a[1][1] != a[2][1] && a[1][1] == a[3][1])) ans2 ++;
	if((a[1][2] == a[2][2] && a[1][2] != a[3][2]) || (a[1][2] != a[2][2] && a[2][2] == a[3][2]) || (a[1][2] != a[2][2] && a[1][2] == a[3][2])) ans2 ++;
	if((a[1][3] == a[2][3] && a[1][3] != a[3][3]) || (a[1][3] != a[2][3] && a[2][3] == a[3][3]) || (a[1][3] != a[2][3] && a[1][3] == a[3][3])) ans2 ++;
	
	if((a[1][1] == a[2][2] && a[2][2] != a[3][3]) || (a[1][1] != a[2][2] && a[2][2] == a[3][3]) || (a[1][1] != a[2][2] && a[1][1] == a[3][3])) ans2 ++;
	if((a[1][3] == a[2][2] && a[1][3] != a[3][1]) || (a[1][3] != a[2][2] && a[2][2] == a[3][1]) || (a[1][3] != a[2][2] && a[1][3] == a[3][1])) ans2 ++;
	printf("%d\n%d", ans1, ans2);
	return 0;
}

