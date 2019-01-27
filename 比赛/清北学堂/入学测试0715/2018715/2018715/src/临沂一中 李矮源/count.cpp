#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

char mat[4][4], ansp, ansg;
bool winp[27], wing[27][27];

bool checkc(int x) {
	return mat[1][x] == mat[2][x] && mat[1][x] == mat[3][x];
}

bool checkr(int x) {
	return mat[x][1] == mat[x][2] && mat[x][1] == mat[x][3];
}

bool checkn() {
	return mat[1][1] == mat[2][2] && mat[1][1] == mat[3][3];
}

bool checkp() {
	return mat[1][3] == mat[2][2] && mat[1][3] == mat[3][1];
}

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			mat[i][j] = getchar();
		}
		getchar();
	}
	for (int i = 1; i <= 3; ++i) {
		if (checkr(i)) {
			ansp += int(!winp[mat[i][1] - 'A']);
			winp[mat[i][1] - 'A'] &= 1;
		}
	}
	for (int i = 1; i <= 3; ++i) {
		if (checkc(i)) {
			ansp += int(!winp[mat[1][i] - 'A']);
			winp[mat[1][i] - 'A'] &= 1;
		}
	}
	if (checkn()) {
		ansp += int(!winp[mat[1][1] - 'A']);
		winp[mat[1][1] - 'A'] &= 1;
	}
	if (checkp()) {
		ansp += int(!winp[mat[3][1] - 'A']);
		winp[mat[3][1] - 'A'] &= 1;
	}

	for (int i = 1; i <= 3; ++i) {
		if (mat[i][1] == mat[i][2] && mat[i][1] != mat[i][3]) {
			ansg += int(!(wing[mat[i][1]][mat[i][3]] && wing[mat[i][3]][mat[i][1]]));
			wing[mat[i][1]][mat[i][3]] &= 1;
			wing[mat[i][3]][mat[i][1]] &= 1;
		} else if (mat[i][1] == mat[i][3] && mat[i][1] != mat[i][2]) {
			ansg += int(!(wing[mat[i][1]][mat[i][2]] && wing[mat[i][2]][mat[i][1]]));
			wing[mat[i][1]][mat[i][2]] &= 1;
			wing[mat[i][2]][mat[i][1]] &= 1;
		} else if (mat[i][2] == mat[i][3] && mat[i][1] != mat[i][2]) {
			ansg += int(!(wing[mat[i][2]][mat[i][1]] && wing[mat[i][1]][mat[i][2]]));
			wing[mat[i][1]][mat[i][2]] &= 1;
			wing[mat[i][2]][mat[i][1]] &= 1;
		}
	}
	for (int i = 1; i <= 3; ++i) {
		if (mat[1][i] == mat[2][i] && mat[1][i] != mat[3][i]) {
			ansg += int(!(wing[mat[1][i]][mat[3][i]] && wing[mat[3][i]][mat[1][i]]));
			wing[mat[1][i]][mat[3][i]] &= 1;
			wing[mat[3][i]][mat[1][i]] &= 1;
		} else if (mat[1][i] == mat[3][i] && mat[1][i] != mat[2][i]) {
			ansg += int(!(wing[mat[1][i]][mat[2][i]] && wing[mat[2][i]][mat[1][i]]));
			wing[mat[1][i]][mat[2][i]] &= 1;
			wing[mat[2][i]][mat[1][i]] &= 1;
		} else if (mat[2][i] == mat[3][i] && mat[1][i] != mat[2][i]) {
			ansg += int(!(wing[mat[2][i]][mat[1][i]] && wing[mat[1][i]][mat[2][i]]));
			wing[mat[1][i]][mat[2][i]] &= 1;
			wing[mat[2][i]][mat[1][i]] &= 1;
		}
	}

	if (mat[1][1] == mat[2][2] && mat[1][1] != mat[3][3]) {
		ansg += int(!(wing[mat[1][1]][mat[3][3]] && wing[mat[3][3]][mat[1][1]]));
		wing[mat[1][1]][mat[3][3]] &= 1;
		wing[mat[3][3]][mat[1][1]] &= 1;
	} else if (mat[1][1] == mat[3][3] && mat[1][1] != mat[2][2]) {
		ansg += int(!(wing[mat[1][1]][mat[2][2]] && wing[mat[2][2]][mat[1][1]]));
		wing[mat[1][1]][mat[2][2]] &= 1;
		wing[mat[2][2]][mat[1][1]] &= 1;
	} else if (mat[2][2] == mat[3][3] && mat[1][1] != mat[2][2]) {
		ansg += int(!(wing[mat[2][2]][mat[1][1]] && wing[mat[1][1]][mat[2][2]]));
		wing[mat[1][1]][mat[2][2]] &= 1;
		wing[mat[2][2]][mat[1][1]] &= 1;
	}

	if (mat[1][3] == mat[2][2] && mat[1][3] != mat[3][1]) {
		ansg += int(!(wing[mat[1][3]][mat[3][1]] && wing[mat[3][1]][mat[1][3]]));
		wing[mat[1][3]][mat[3][1]] &= 1;
		wing[mat[3][1]][mat[1][3]] &= 1;
	} else if (mat[1][3] == mat[3][1] && mat[1][3] != mat[2][2]) {
		ansg += int(!(wing[mat[1][3]][mat[2][2]] && wing[mat[2][2]][mat[1][3]]));
		wing[mat[1][3]][mat[2][2]] &= 1;
		wing[mat[2][2]][mat[1][3]] &= 1;
	} else if (mat[2][2] == mat[3][1] && mat[1][3] != mat[2][2]) {
		ansg += int(!(wing[mat[2][2]][mat[1][3]] && wing[mat[1][3]][mat[2][2]]));
		wing[mat[1][3]][mat[2][2]] &= 1;
		wing[mat[2][2]][mat[1][3]] &= 1;
	}

	printf("%d\n%d", ansp, ansg);
	return 0;
}
