#include<iostream>
#include<cstdio>
using namespace std;
char a[4][4];
bool m[10000];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);	
	for(int i=1;i<=3;++i)for(int j=1;j<=3;++j)cin>>a[i][j];
	if(a[1][1]==a[1][2]){
		if(a[1][1]==a[1][3])m[int(a[1][1])]=1;
		else m[int(a[1][1]*a[1][3])]=1;
	}
	else if(a[1][1]==a[1][3])m[int(a[1][1]*a[1][2])]=1;
	else if(a[1][2]==a[1][3])m[int(a[1][1]*a[1][3])]=1;
	if(a[2][1]==a[2][2]){
		if(a[2][1]==a[2][3])m[int(a[2][1])]=1;
		else m[int(a[2][1]*a[2][3])]=1;
	}
	else if(a[2][1]==a[2][3])m[int(a[2][1]*a[2][2])]=1;
	else if(a[2][2]==a[2][3])m[int(a[2][1]*a[2][3])]=1;
	if(a[3][1]==a[3][2]){
		if(a[3][1]==a[3][3])m[int(a[3][1])]=1;
		else m[int(a[3][1]*a[3][3])]=1;
	}
	else if(a[3][1]==a[3][3])m[int(a[3][1]*a[3][2])]=1;
	else if(a[3][2]==a[3][3])m[int(a[3][1]*a[3][3])]=1;
	if(a[1][1]==a[2][1]){
		if(a[1][1]==a[3][1])m[int(a[1][1])]=1;
		else m[int(a[1][1]*a[3][1])]=1;
	}
	else if(a[1][1]==a[3][1])m[int(a[1][1]*a[2][1])]=1;
	else if(a[2][1]==a[3][1])m[int(a[1][1]*a[3][1])]=1;
	if(a[1][2]==a[2][2]){
		if(a[1][2]==a[3][2])m[int(a[1][2])]=1;
		else m[int(a[1][2]*a[3][2])]=1;
	}
	else if(a[1][2]==a[3][2])m[int(a[1][2]*a[2][2])]=1;
	else if(a[2][2]==a[3][2])m[int(a[1][2]*a[3][2])]=1;
	if(a[1][3]==a[2][3]){
		if(a[1][3]==a[3][3])m[int(a[1][3])]=1;
		else m[int(a[1][3]*a[3][3])]=1;
	}
	else if(a[1][3]==a[3][3])m[int(a[1][3]*a[2][3])]=1;
	else if(a[2][3]==a[3][3])m[int(a[1][3]*a[3][3])]=1;
	if(a[1][1]==a[2][2]){
		if(a[1][1]==a[3][3])m[int(a[1][1])]=1;
		else m[int(a[1][1]*a[3][3])]=1;
	}
	else if(a[2][2]==a[3][3])m[int(a[1][1]*a[2][2])]=1;
	else if(a[1][1]==a[3][3])m[int(a[2][2]*a[3][3])]=1;
	if(a[1][3]==a[2][2]){
		if(a[2][2]==a[3][1])m[int(a[2][2])]=1;
		else m[int(a[3][1]*a[1][3])]=1;
	}
	else if(a[2][2]==a[3][1])m[int(a[1][3]*a[2][2])]=1;
	else if(a[3][1]==a[1][3])m[int(a[2][2]*a[1][3])]=1;
	int ans=0;
	for(int i=65;i<=90;++i)if(m[i])ans++;
	cout<<ans<<"\n";ans=0;
	for(int i=65;i<=90;++i)for(int j=i+1;j<=90;++j)if(m[i*j])ans++;
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
