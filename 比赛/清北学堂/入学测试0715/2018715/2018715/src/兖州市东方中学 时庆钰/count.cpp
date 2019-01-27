#include <bits/stdc++.h>
using namespace std;
char c[3][3],C;
int p = 0, t = 0;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){
			reinput:
			if(isalpha(C = getchar()))
				c[i][j] = C;
			else goto reinput;
		}
	for(int i = 0; i < 3; i++){
		if(c[i][1] == c[i][2] && c[i][2] == c[i][0]) p++;
		else if(c[i][0] == c[i][1] || c[i][1] == c[i][2] || c[i][0] == c[i][2]) t++;
		if(c[0][i] == c[1][i] && c[1][i] == c[2][i]) p++;
		else if(c[0][i] == c[1][i] || c[1][i] == c[2][i] || c[0][i] == c[2][i]) t++;
	}
	if(c[0][0] == c[1][1] && c[1][1] == c[2][2]) p++;
	else if(c[0][0] == c[1][1] || c[1][1] == c[2][2] || c[0][0] == c[2][2]) t++;
	if(c[0][2] == c[1][1] && c[1][1] == c[2][0]) p++;
	else if(c[0][2] == c[1][1] || c[1][1] == c[2][0] || c[0][2] == c[2][0]) t++;
	cout << p << endl << t << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
