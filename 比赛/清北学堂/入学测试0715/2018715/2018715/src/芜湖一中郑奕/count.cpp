#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char a[20];
int ans[10][10]={0};
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int jibun=0,hoka=0,i;
	scanf("%c%c%c\n%c%c%c\n%c%c%c\n",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]);
	ans[0][0]=0,ans[0][1]=1,ans[0][2]=2;
	ans[1][0]=3,ans[1][1]=4,ans[1][2]=5;
	ans[2][0]=6,ans[2][1]=7,ans[2][2]=8;
	ans[3][0]=0,ans[3][1]=3,ans[3][2]=6;
	ans[4][0]=1,ans[4][1]=4,ans[4][2]=7;
	ans[5][0]=2,ans[5][1]=5,ans[5][2]=8;
	ans[6][0]=0,ans[6][1]=4,ans[6][2]=8;
	ans[7][0]=2,ans[7][1]=4,ans[7][2]=6;
	for(i=0;i<8;i++){
		if((a[ans[i][0]]==a[ans[i][1]])&&(a[ans[i][0]]==a[ans[i][2]])&&(a[ans[i][1]]==a[ans[i][2]]))
		jibun++;
		else if((a[ans[i][0]]==a[ans[i][1]])||(a[ans[i][0]]==a[ans[i][2]])||(a[ans[i][1]]==a[ans[i][2]]))
		hoka++;
	}
	printf("%d\n%d\n",jibun,hoka);
	return 0;
}
