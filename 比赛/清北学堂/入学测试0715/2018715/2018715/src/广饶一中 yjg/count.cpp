#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s2;
int s[4][4],ans,ans1;
bool flag1[100],flag[100][100];
int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			cin>>s2,s[i][j]=s2-'A'+1;
	for(int i=1; i<=3; i++) {
		if(s[i][1]==s[i][2]&&s[i][2]==s[i][3]&&!flag1[s[i][1]]) {
			ans++;
			flag1[s[i][1]]=true;
		}
		if(s[1][i]==s[2][i]&&s[2][i]==s[3][i]&&!flag1[s[1][i]]) {
			ans++;
			flag1[s[1][i]]=true;
		}
		if(s[1][i]==s[2][i]&&s[1][i]!=s[3][i]&&!flag[s[1][i]][s[3][i]]) {
			ans1++;
			flag[s[1][i]][s[3][i]]=flag[s[3][i]][s[1][i]]=true;
		}
		if(s[2][i]==s[3][i]&&s[1][i]!=s[3][i]&&!flag[s[1][i]][s[3][i]]) {
			ans1++;
			flag[s[1][i]][s[3][i]]=flag[s[3][i]][s[1][i]]=true; 
		}
		if(s[1][i]==s[3][i]&&s[1][i]!=s[2][i]&&!flag[s[1][i]][s[2][i]]) {
			ans1++;
			flag[s[1][i]][s[2][i]]=flag[s[2][i]][s[1][i]]=true;
		}
		if(s[i][1]==s[i][2]&&s[i][1]!=s[i][3]&&!flag[s[i][1]][s[i][3]]) {
			ans1++;
			flag[s[i][1]][s[i][3]]=flag[s[i][3]][s[i][1]]=true; 
		}
		if(s[i][2]==s[i][3]&&s[i][1]!=s[i][3]&&!flag[s[i][1]][s[i][3]]) {
			ans1++;
			flag[s[i][1]][s[i][3]]=flag[s[i][3]][s[i][1]]=true; 
		}
		if(s[i][1]==s[i][3]&&s[i][1]!=s[i][2]&&!flag[s[i][1]][s[i][2]]) {
			ans1++;
			flag[s[i][1]][s[i][2]]=flag[s[i][2]][s[i][1]]=true; 
		}
	}
	if((s[1][1]==s[2][2]&&s[2][2]==s[3][3]&&!flag[s[2][2]])||(s[1][3]==s[2][2]&&s[2][2]==s[3][1]&&!flag[s[2][2]])) {
		ans++;
		flag[2][2]=true;
	}
	if(s[1][1]==s[3][3]&&s[1][1]!=s[2][2]&&!flag[s[1][1]][s[2][2]]) {
		ans1++;
		flag[s[1][1]][s[2][2]]=true;
	}
	if(s[1][1]==s[2][2]&&s[1][1]!=s[3][3]&&!flag[s[1][1]][s[3][3]]) {
		ans1++;
		flag[s[1][1]][s[3][3]]=true;
	}
	if(s[3][3]==s[2][2]&&s[1][1]!=s[3][3]&&!flag[s[1][1]][s[3][3]]) {
		ans1++;
		flag[s[1][1]][s[3][3]]=true;
	}
	if(s[1][3]==s[3][1]&&s[1][3]!=s[2][2]&&!flag[s[1][3]][s[2][2]]) {
		ans1++;
		flag[s[1][3]][s[2][2]]=flag[s[2][2]][s[1][3]]=true;
	}
	if(s[1][3]==s[2][2]&&s[1][3]!=s[3][1]&&!flag[s[1][3]][s[3][1]]) {
		ans1++;
		flag[s[1][3]][s[3][1]]=flag[s[3][1]][s[1][3]]=true;
	}
	if(s[3][1]==s[2][2]&&s[1][3]!=s[3][1]&&!flag[s[3][1]][s[1][3]]) {
		ans1++;
		flag[s[1][3]][s[3][1]]=flag[s[3][1]][s[1][3]]=true;
	}
	printf("%d\n%d",ans,ans1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
