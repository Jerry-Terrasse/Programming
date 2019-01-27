#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char su[4][4];
int ren=0,zhu=0;
char s;
void find()
{
	for(int i=1;i<=3;i++)
	if(su[i][1]=su[i][2]=su[i][3])ren++;
	for(int i=1;i<=3;i++)
	if(su[1][i]=su[2][i]=su[3][i])ren++;
	if(su[1][1]=su[2][2]=su[3][3])ren++;
	if(su[3][1]=su[2][2]=su[1][3])ren++;
	for(int i=1;i<=3;i++){
	if(su[i][1]=su[i][2]||su[i][2]!=su[i][3])zhu++;
	if(su[i][2]=su[i][3]||su[i][3]!=su[i][1])zhu++;
	if(su[i][1]=su[i][3]||su[i][3]!=su[i][2])zhu++;
	}
	for(int i=1;i<=3;i++){
	if(su[1][i]=su[2][i]||su[2][i]!=su[3][i])zhu++;
	if(su[2][i]=su[3][i]||su[3][i]!=su[1][i])zhu++;
	if(su[3][i]=su[3][i]||su[3][i]!=su[2][i])zhu++;
	}
	if(su[1][1]=su[2][2]||su[2][2]!=su[3][3])zhu++;
	if(su[1][1]=su[3][3]||su[2][2]!=su[3][3])zhu++;
	if(su[2][2]=su[3][3]||su[1][1]!=su[2][2])zhu++;
	if(su[3][1]=su[2][2]||su[2][2]!=su[1][3])zhu++;
	if(su[3][1]=su[1][3]||su[2][2]!=su[1][3])zhu++;
	if(su[2][2]=su[1][3]||su[1][3]!=su[2][2])zhu++;
	}

int main()
{
	freopen("count","in",stdin);
	freopen("count","out",stdout);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			cin>>s;
			su[i][j]=s;
		}
	find();
	printf("%d\n",ren);
	printf("%d\n",zhu);
	return 0;
}
