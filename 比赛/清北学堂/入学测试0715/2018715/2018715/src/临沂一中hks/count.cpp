#include <cstdio>
#include <algorithm>
char sq[3][3];
int person, group;
void update(char const &a, char const &b, char const &c) {
	char str[3];
	str[0] = a, str[1] = b, str[2] = c;
	std::sort(str, str+3);
	if (((str[0] == str[1]) && (str[2] != str[0])) || ((str[1] == str[2]) && (str[1] != str[0])))
		group++;
	if (str[0] == str[1] && str[1] == str[2])
		person++;
}
int main(int argc, char* const argv[]) {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			sq[i][j] = getchar();
		getchar();
	}
	for (int i = 0; i < 3; i++) 
		update(sq[i][0], sq[i][1], sq[i][2]), update(sq[0][i], sq[1][i], sq[2][i]);
	update(sq[0][0], sq[1][1], sq[2][2]);
	update(sq[0][2], sq[1][1], sq[2][0]);
	printf("%d\n%d\n", person, group);	
	return 0;
} 
