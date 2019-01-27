#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[4 + 1][4 + 1];
int ansp, anst;
int main() {
	freopen("count.in", "r",stdin);
	freopen("count.out", "w", stdout);
	
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= 3; i++) {		//每一行 
		if (a[i][1] == a[i][2] && a[i][1] == a[i][3]) {
			ansp++;
		}
		if ((a[i][1] == a[i][2] && a[i][1] != a[i][3]) 
		|| (a[i][1] == a[i][3] && a[i][1] != a[i][2])
		|| (a[i][2] == a[i][3] && a[i][2] != a[i][1])) {
			anst++;
		}
	}
	
	for (int j = 1; j <= 3; j++) {		//每一列 
		if (a[1][j] == a[2][j] && a[1][j] == a[3][j]) {
			ansp++;
		}
		if ((a[1][j] == a[2][j] && a[1][j] != a[3][j])
		|| (a[1][j] == a[3][j] && a[1][j] != a[2][j])
		|| (a[2][j] == a[3][j] && a[2][j] != a[1][j])) {
			anst++;
		}
	}
	
	if (a[1][1] == a[2][2] && a[1][1] == a[3][3]) {
		ansp++;
	}
	if (a[1][3] == a[2][2] && a[1][3] == a[3][1]) {
		ansp++;
	}
	
	if (a[1][1] == a[2][2] && a[1][1] != a[3][3]) {
		anst++;
	}
	if (a[1][1] == a[3][3] && a[1][1] != a[2][2]) {
		anst++;
	}
	if (a[2][2] == a[3][3] && a[2][2] != a[1][1]) {
		anst++;
	}
	
	if (a[1][3] == a[2][2] && a[1][3] != a[3][1]) {
		anst++;
	}
	if (a[1][3] == a[3][1] && a[1][3] != a[2][2]) {
		anst++;
	}
	if (a[2][2] == a[3][1] && a[2][2] != a[1][3]) {
		anst++;
	}
	
	printf("%d\n%d", ansp, anst);
	return 0;
}
