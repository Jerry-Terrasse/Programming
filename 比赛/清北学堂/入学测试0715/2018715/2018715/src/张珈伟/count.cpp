#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	char s[4][4];
	for(int i = 1;i <= 3;i++) scanf("%s",s[i] + 1);
	int ans1 = 0;
	int ans2 = 0;
	for(int i = 1;i <= 3;i++) {
		if(s[i][1] == s[i][2] && s[i][2] == s[i][3]) ans1++;
		else if(s[i][1] == s[i][2] || s[i][2] == s[i][3] || s[i][3] == s[i][1]) ans2++;
	}
	for(int i = 1;i <= 3;i++) {
		if(s[1][i] == s[2][i] && s[2][i] == s[3][i]) ans1++;
		else if(s[1][i] == s[2][i] || s[2][i] == s[3][i] || s[3][i] == s[1][i]) ans2++;
	}
	if(s[1][1] == s[2][2] && s[2][2] == s[3][3]) ans1++;
	else if(s[1][1] == s[2][2] || s[2][2] == s[3][3] || s[3][3] == s[1][1]) ans2++;
	if(s[1][3] == s[2][2] && s[2][2] == s[1][3]) ans1++;
	else if(s[3][1] == s[2][2] || s[2][2] == s[1][3] || s[1][3] == s[3][1]) ans2++;
	printf("%d\n%d",ans1,ans2);
	return 0;
}
