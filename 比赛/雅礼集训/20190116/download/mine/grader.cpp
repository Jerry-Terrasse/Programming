#include <bits/stdc++.h>
#include "mine.h"

using namespace std;

static const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
static const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

static int times, remain, board[16][30];
static bool visit[16][30];

void ensure(bool f, const char *str){
	if (!f) {
		fprintf(stderr, "%s\n", str);
		exit(-1);
	}
}

int open(int r, int c) {
	ensure(!visit[r][c], "you can't open a cell twice");
	visit[r][c] = true;
	board[r][c] == -1 ? ++times : --remain;
	if (!remain) {
		printf("Accepted answer: %d\n", times);
		exit(0);
	}
	return board[r][c];
}

int main() {
	int n, m, q, x;
	scanf("%d %d %d %d", &n, &m, &q, &x);
	int cnt = 0;
	while (cnt < q) {
		x = 48271ll * x % 2147483647;
		int y = x % (n * m);
		int r = y / m, c = y % m;
		if (!board[r][c]) {
			board[r][c] = -1;
			++cnt;
		}
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (!board[i][j]) {
		for (int k = 0; k < 8; ++k) {
			int x = i + dx[k], y = j + dy[k];
			if (x >= 0 && x < n && y >= 0 && y < m && !~board[x][y]) ++board[i][j];
		}
	}
	remain = n * m - q;
	sweep(n, m, q);
	ensure(false, "the map isn't clear");
}
