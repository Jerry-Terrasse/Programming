#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
char Map[10][4];
int cnt1,cnt2;
void check(){
	if(Map[1][1] == Map[1][2] && Map[1][2] == Map[1][3]) cnt1++;
	if(Map[2][1] == Map[2][2] && Map[2][2] == Map[2][3]) cnt1++;
	if(Map[3][1] == Map[3][2] && Map[3][2] == Map[3][3]) cnt1++;
	if(Map[1][1] == Map[2][1] && Map[2][1] == Map[3][1]) cnt1++;
	if(Map[1][2] == Map[2][2] && Map[2][2] == Map[3][2]) cnt1++;
	if(Map[1][3] == Map[2][3] && Map[2][3] == Map[3][3]) cnt1++;
	if(Map[1][1] == Map[2][2] && Map[2][2] == Map[3][3]) cnt1++;
	if(Map[1][3] == Map[2][2] && Map[2][2] == Map[3][1]) cnt1++;
}

void query(){
	 int num = 0;
	 if(Map[1][1] != Map[1][2]) num++;
	 if(Map[1][1] != Map[1][3]) num++;
	 if(Map[1][2] != Map[1][3]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 if(Map[2][1] != Map[2][2]) num++;
	 if(Map[2][1] != Map[2][3]) num++;
	 if(Map[2][2] != Map[2][3]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 if(Map[3][1] != Map[3][2]) num++;
	 if(Map[3][1] != Map[3][3]) num++;
	 if(Map[3][2] != Map[3][3]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 
	 if(Map[1][2] != Map[2][2]) num++;
	 if(Map[2][2] != Map[3][2]) num++;
	 if(Map[1][2] != Map[3][2]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 if(Map[1][1] != Map[2][1]) num++;
	 if(Map[1][1] != Map[3][1]) num++;
	 if(Map[2][1] != Map[3][1]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 if(Map[1][3] != Map[2][3]) num++;
	 if(Map[1][3] != Map[3][3]) num++;
	 if(Map[2][3] != Map[3][3]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 
	 if(Map[1][1] != Map[2][2]) num++;
	 if(Map[1][1] != Map[3][3]) num++;
	 if(Map[2][2] != Map[3][3]) num++;
	 if(num == 2) cnt2++;
	 num = 0;
	 if(Map[1][3] != Map[2][2]) num++;
	 if(Map[1][3] != Map[3][1]) num++;
	 if(Map[2][2] != Map[3][1]) num++;
	 if(num == 2) cnt2++;
}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i = 1;i <= 3 ;++i)
	  for(int j = 1;j <= 3; ++j)
	     cin>>Map[i][j];
	check();  
	query(); 
	printf("%d\n%d",cnt1,cnt2);
	return 0;
}
