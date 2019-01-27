#include <cstdio>
#include <algorithm>

char jing[3][3], ha[8][3];
bool rep[8], per[8];

bool judge(char a[], char b[]) {
	bool bb=true;
	for(int i=0; i<3; i++) if(a[i]!=b[i]) {bb=false; break;}
	return bb;
}

int ans, ans1;

int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) scanf("%c", &jing[i][j]), ha[i][j]=jing[i][j];
		std::sort(ha[i], ha[i]+3);
		getchar();
	}
	for(int j=0; j<3; j++) {
	  for(int i=0; i<3; i++) ha[j+3][i]=jing[i][j];
		std::sort(ha[j+3], ha[j+3]+3);
	}
	ha[6][0]=jing[2][0], ha[6][1]=jing[1][1], ha[6][2]=jing[0][2];
	ha[7][0]=jing[0][0], ha[7][1]=jing[1][1], ha[7][2]=jing[2][2];
	std::sort(ha[6], ha[6]+3);
	std::sort(ha[7], ha[7]+3);
	for(int i=0; i<8; i++) {
		if(ha[i][0]==ha[i][1]&&ha[i][1]==ha[i][2]) {per[i]=true; continue;}
		if(ha[i][0]!=ha[i][1]&&ha[i][1]!=ha[i][2]) rep[i]=true;
	}
	for(int i=0; i<8; i++) {
		if(rep[i]) continue;
		for(int j=i+1; j<8; j++) {
			if(judge(ha[i], ha[j])) rep[j]=true;	
			if(ha[i][0]==ha[j][0]&&ha[i][1]!=ha[j][1]&&ha[i][2]==ha[j][2]) rep[j]=true;	
		}
	}
	for(int i=0; i<8; i++) {
		if(rep[i]) continue;
		if(per[i]) {ans1++; continue;}
		ans++;
	}
	printf("%d\n%d\n", ans1, ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
